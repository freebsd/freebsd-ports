--- wwinit.c.orig	2009-02-23 10:26:32 UTC
+++ wwinit.c
@@ -48,6 +48,58 @@ static char rcsid[] =
 #include <termcap.h>
 #include "char.h"
 
+struct ww wwhead;
+struct ww *wwindex[NWW + 1];		/* last location is for wwnobody */
+struct ww wwnobody;
+
+extern char *wwterm;			/* the terminal name */
+extern char wwtermcap[1024];		/* place for the termcap */
+
+int wwnrow, wwncol;		/* the screen size */
+char wwavailmodes;		/* actually supported modes */
+char wwcursormodes;		/* the modes for the fake cursor */
+char wwwrap;			/* terminal has auto wrap around */
+int wwdtablesize;		/* result of getdtablesize() call */
+char **wwsmap;			/* the screen map */
+union ww_char **wwos;		/* the old (current) screen */
+union ww_char **wwns;		/* the new (desired) screen */
+union ww_char **wwcs;		/* the checkpointed screen */
+char *wwtouched;		/* wwns changed flags */
+struct ww_update *wwupd;	/* for display update */
+int wwospeed;			/* output baud rate, copied from wwoldtty */
+int wwbaud;			/* wwospeed converted into actual number */
+int wwcursorrow, wwcursorcol;	/* where we want the cursor to be */
+int wwerrno;			/* error number */
+
+int wwnflush, wwnwr, wwnwre, wwnwrz, wwnwrc;
+int wwnwwr, wwnwwra, wwnwwrc;
+int wwntokdef, wwntokuse, wwntokbad, wwntoksave, wwntokc;
+int wwnupdate, wwnupdline, wwnupdmiss;
+int wwnupdscan, wwnupdclreol, wwnupdclreos, wwnupdclreosmiss, wwnupdclreosline;
+int wwnread, wwnreade, wwnreadz;
+int wwnreadc, wwnreadack, wwnreadnack, wwnreadstat, wwnreadec;
+int wwnwread, wwnwreade, wwnwreadz, wwnwreadd, wwnwreadc, wwnwreadp;
+int wwnselect, wwnselecte, wwnselectz;
+
+struct ww_tty wwoldtty;		/* the old (saved) terminal settings */
+struct ww_tty wwnewtty;		/* the new (current) terminal settings */
+struct ww_tty wwwintty;		/* the terminal settings for windows */
+char *wwterm;
+char wwtermcap[1024];
+char wwwintermcap[1024];
+
+struct ww *wwcurwin;	/* window to copy input into */
+char *wwib;		/* input (keyboard) buffer */
+char *wwibe;		/* wwib + sizeof buffer */
+char *wwibp;		/* current read position in buffer */
+char *wwibq;		/* current write position in buffer */
+
+char wwintr;
+char wwsetjmp;
+jmp_buf wwjmpbuf;
+
+int wwdocheckpoint;
+
 wwinit()
 {
 	register i, j;
