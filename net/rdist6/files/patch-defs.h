--- include/defs.h.orig	Mon Nov  9 20:23:54 1998
+++ include/defs.h	Fri Nov  3 02:39:45 2000
@@ -379,7 +379,9 @@
 extern void			error(char *, ...);
 extern void			fatalerr(char *, ...);
 extern void			message(int, char *, ...);
+#ifndef HAVE_SETPROCTITLE
 extern void			setproctitle(char *fmt, ...);
+#endif
 #else
 extern void			debugmsg();
 extern void			error();
