--- main.c.orig	2008-07-12 06:05:22 UTC
+++ main.c
@@ -57,6 +57,30 @@ static char rcsid[] =
 
 #define next(a) (*++*(a) ? *(a) : (*++(a) ? *(a) : (char *)(uintptr_t)usage()))
 
+struct ww *window[NWINDOW];	/* the windows */
+struct ww *selwin;		/* the selected window */
+struct ww *lastselwin;		/* the last selected window */
+struct ww *cmdwin;		/* the command window */
+struct ww *framewin;		/* the window for framing */
+struct ww *boxwin;		/* the window for the box */
+struct ww *fgwin;		/* the last foreground window */
+
+struct var *alias_head;
+struct var *var_head;
+
+char *default_shell[128];	/* default shell argv */
+char *default_shellfile;	/* default shell program */
+int default_nline;		/* default buffer size for new windows */
+int default_smooth;		/* default "smooth" parameter */
+char escapec;			/* the escape character */
+
+struct timeval starttime;
+
+char quit;			/* quit command issued */
+char terse;			/* terse mode */
+char debug;			/* debug mode */
+char incmd;			/* in command mode */
+
 /*ARGSUSED*/
 main(argc, argv)
 char **argv;
