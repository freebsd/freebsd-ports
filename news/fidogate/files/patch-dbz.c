--- src/toss/dbz.c.orig	Wed Oct 18 23:53:57 2000
+++ src/toss/dbz.c	Mon Jul 22 19:52:59 2002
@@ -300,8 +300,10 @@
 #endif
 
 /* externals used */
+#ifndef __FreeBSD__
 extern char *malloc();
 extern char *calloc();
+#endif
 extern void free();		/* ANSI C; some old implementations say int */
 extern int atoi();
 extern long atol();
