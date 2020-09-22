--- ww.h.orig	2008-07-12 06:05:22 UTC
+++ ww.h
@@ -207,44 +207,44 @@ struct ww_update {
 #define WWU_TOUCHED	0x01		/* touched */
 
 	/* the window structures */
-struct ww wwhead;
-struct ww *wwindex[NWW + 1];		/* last location is for wwnobody */
-struct ww wwnobody;
+extern struct ww wwhead;
+extern struct ww *wwindex[NWW + 1];		/* last location is for wwnobody */
+extern struct ww wwnobody;
 
 	/* tty things */
-struct ww_tty wwoldtty;		/* the old (saved) terminal settings */
-struct ww_tty wwnewtty;		/* the new (current) terminal settings */
-struct ww_tty wwwintty;		/* the terminal settings for windows */
-char *wwterm;			/* the terminal name */
-char wwtermcap[1024];		/* place for the termcap */
+extern struct ww_tty wwoldtty;		/* the old (saved) terminal settings */
+extern struct ww_tty wwnewtty;		/* the new (current) terminal settings */
+extern struct ww_tty wwwintty;		/* the terminal settings for windows */
+extern char *wwterm;			/* the terminal name */
+extern char wwtermcap[1024];		/* place for the termcap */
 
 	/* generally useful variables */
-int wwnrow, wwncol;		/* the screen size */
-char wwavailmodes;		/* actually supported modes */
-char wwcursormodes;		/* the modes for the fake cursor */
-char wwwrap;			/* terminal has auto wrap around */
-int wwdtablesize;		/* result of getdtablesize() call */
-char **wwsmap;			/* the screen map */
-union ww_char **wwos;		/* the old (current) screen */
-union ww_char **wwns;		/* the new (desired) screen */
-union ww_char **wwcs;		/* the checkpointed screen */
-char *wwtouched;		/* wwns changed flags */
-struct ww_update *wwupd;	/* for display update */
-int wwospeed;			/* output baud rate, copied from wwoldtty */
-int wwbaud;			/* wwospeed converted into actual number */
-int wwcursorrow, wwcursorcol;	/* where we want the cursor to be */
-int wwerrno;			/* error number */
+extern int wwnrow, wwncol;		/* the screen size */
+extern char wwavailmodes;		/* actually supported modes */
+extern char wwcursormodes;		/* the modes for the fake cursor */
+extern char wwwrap;			/* terminal has auto wrap around */
+extern int wwdtablesize;		/* result of getdtablesize() call */
+extern char **wwsmap;			/* the screen map */
+extern union ww_char **wwos;		/* the old (current) screen */
+extern union ww_char **wwns;		/* the new (desired) screen */
+extern union ww_char **wwcs;		/* the checkpointed screen */
+extern char *wwtouched;		/* wwns changed flags */
+extern struct ww_update *wwupd;	/* for display update */
+extern int wwospeed;			/* output baud rate, copied from wwoldtty */
+extern int wwbaud;			/* wwospeed converted into actual number */
+extern int wwcursorrow, wwcursorcol;	/* where we want the cursor to be */
+extern int wwerrno;			/* error number */
 
 	/* statistics */
-int wwnflush, wwnwr, wwnwre, wwnwrz, wwnwrc;
-int wwnwwr, wwnwwra, wwnwwrc;
-int wwntokdef, wwntokuse, wwntokbad, wwntoksave, wwntokc;
-int wwnupdate, wwnupdline, wwnupdmiss;
-int wwnupdscan, wwnupdclreol, wwnupdclreos, wwnupdclreosmiss, wwnupdclreosline;
-int wwnread, wwnreade, wwnreadz;
-int wwnreadc, wwnreadack, wwnreadnack, wwnreadstat, wwnreadec;
-int wwnwread, wwnwreade, wwnwreadz, wwnwreadd, wwnwreadc, wwnwreadp;
-int wwnselect, wwnselecte, wwnselectz;
+extern int wwnflush, wwnwr, wwnwre, wwnwrz, wwnwrc;
+extern int wwnwwr, wwnwwra, wwnwwrc;
+extern int wwntokdef, wwntokuse, wwntokbad, wwntoksave, wwntokc;
+extern int wwnupdate, wwnupdline, wwnupdmiss;
+extern int wwnupdscan, wwnupdclreol, wwnupdclreos, wwnupdclreosmiss, wwnupdclreosline;
+extern int wwnread, wwnreade, wwnreadz;
+extern int wwnreadc, wwnreadack, wwnreadnack, wwnreadstat, wwnreadec;
+extern int wwnwread, wwnwreade, wwnwreadz, wwnwreadd, wwnwreadc, wwnwreadp;
+extern int wwnselect, wwnselecte, wwnselectz;
 
 	/* quicky macros */
 #define wwsetcursor(r,c) (wwcursorrow = (r), wwcursorcol = (c))
@@ -256,27 +256,27 @@ int wwnselect, wwnselecte, wwnselectz;
 
 	/* things for handling input */
 void wwrint();		/* interrupt handler */
-struct ww *wwcurwin;	/* window to copy input into */
-char *wwib;		/* input (keyboard) buffer */
-char *wwibe;		/* wwib + sizeof buffer */
-char *wwibp;		/* current read position in buffer */
-char *wwibq;		/* current write position in buffer */
+extern struct ww *wwcurwin;	/* window to copy input into */
+extern char *wwib;		/* input (keyboard) buffer */
+extern char *wwibe;		/* wwib + sizeof buffer */
+extern char *wwibp;		/* current read position in buffer */
+extern char *wwibq;		/* current write position in buffer */
 #define wwmaskc(c)      ((c) & 0xff)
 #define wwgetc()	(wwibp < wwibq ? wwmaskc(*wwibp++) : -1)
 #define wwpeekc()	(wwibp < wwibq ? wwmaskc(*wwibp) : -1)
 #define wwungetc(c)	(wwibp > wwib ? *--wwibp = (c) : -1)
 
 	/* things for short circuiting wwiomux() */
-char wwintr;		/* interrupting */
-char wwsetjmp;		/* want a longjmp() from wwrint() and wwchild() */
-jmp_buf wwjmpbuf;	/* jmpbuf for above */
+extern char wwintr;		/* interrupting */
+extern char wwsetjmp;		/* want a longjmp() from wwrint() and wwchild() */
+extern jmp_buf wwjmpbuf;	/* jmpbuf for above */
 #define wwinterrupt()	wwintr
 #define wwsetintr()	do { wwintr = 1; if (wwsetjmp) longjmp(wwjmpbuf, 1); } \
 			while (0)
 #define wwclrintr()	(wwintr = 0)
 
 	/* checkpointing */
-int wwdocheckpoint;
+extern int wwdocheckpoint;
 
 	/* the window virtual terminal */
 #define WWT_TERM	"window-v2"
@@ -294,11 +294,11 @@ int wwdocheckpoint;
 #define WWT_IMEI	"im=\\E@:ei=\\EO:ic=:mi:" /* XXX, ic for emacs bug */
 #define WWT_IC		"ic=\\EP:"
 #define WWT_DC		"dc=\\EN:"
-char wwwintermcap[1024];	/* terminal-specific but window-independent
+extern char wwwintermcap[1024];	/* terminal-specific but window-independent
 				   part of the window termcap */
 #ifdef TERMINFO
 	/* where to put the temporary terminfo directory */
-char wwterminfopath[1024];
+extern char wwterminfopath[1024];
 #endif
 
 	/* our functions */
