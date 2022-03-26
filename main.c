#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <sl/arg.h>
char *argv0, *fmt = "%dx%d\n" ;
Display *dpy;
int sw, sh, screen;
void
usage(void)
{
	fprintf(stderr, "usage: %s [-s screen] [-f format]\n", argv0);
	exit(1);
}
void
main(int argc, char *argv[])
{
	argv0 = argv[0] ;
	if(! (dpy = XOpenDisplay(NULL)) ){
		fprintf(stderr, "%s: cannot open open display.", argv0);
		exit(1);
	}
	screen = DefaultScreen(dpy) ;
	ARGBEGIN {
	case 's' :
		screen = atoi(EARGF(usage())) ;
	break;
	case 'f' :
		fmt = EARGF(usage()) ;
	break;
	default:
		usage();
	} ARGEND ;
	if(argc) usage() ;
	sw = DisplayWidth(dpy, screen) ;
	sh = DisplayHeight(dpy, screen) ;
	printf(fmt, sw, sh);
	exit(0);
}

