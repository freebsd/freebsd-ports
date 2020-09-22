--- defs.h.orig	2008-07-12 06:05:22 UTC
+++ defs.h
@@ -42,29 +42,29 @@
 
 #define NWINDOW 9
 
-struct timeval starttime;
+extern struct timeval starttime;
 
-struct ww *window[NWINDOW];	/* the windows */
-struct ww *selwin;		/* the selected window */
-struct ww *lastselwin;		/* the last selected window */
-struct ww *cmdwin;		/* the command window */
-struct ww *framewin;		/* the window for framing */
-struct ww *boxwin;		/* the window for the box */
-struct ww *fgwin;		/* the last foreground window */
+extern struct ww *window[NWINDOW];	/* the windows */
+extern struct ww *selwin;		/* the selected window */
+extern struct ww *lastselwin;		/* the last selected window */
+extern struct ww *cmdwin;		/* the command window */
+extern struct ww *framewin;		/* the window for framing */
+extern struct ww *boxwin;		/* the window for the box */
+extern struct ww *fgwin;		/* the last foreground window */
 
 #define isfg(w)		((w)->ww_order <= fgwin->ww_order)
 
-char *default_shell[128];	/* default shell argv */
-char *default_shellfile;	/* default shell program */
-int default_nline;		/* default buffer size for new windows */
-int default_smooth;		/* default "smooth" parameter */
-char escapec;			/* the escape character */
+extern char *default_shell[128];	/* default shell argv */
+extern char *default_shellfile;	/* default shell program */
+extern int default_nline;		/* default buffer size for new windows */
+extern int default_smooth;		/* default "smooth" parameter */
+extern char escapec;			/* the escape character */
 
 	/* flags */
-char quit;			/* quit command issued */
-char terse;			/* terse mode */
-char debug;			/* debug mode */
-char incmd;			/* in command mode */
+extern char quit;			/* quit command issued */
+extern char terse;			/* terse mode */
+extern char debug;			/* debug mode */
+extern char incmd;			/* in command mode */
 
 struct ww *getwin();
 struct ww *openwin();
