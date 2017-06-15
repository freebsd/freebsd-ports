--- src/toss/dbz.c.orig	2000-10-18 21:53:57 UTC
+++ src/toss/dbz.c
@@ -300,8 +300,10 @@ static int debug;			/* controlled by dbz
 #endif
 
 /* externals used */
+#ifndef __FreeBSD__
 extern char *malloc();
 extern char *calloc();
+#endif
 extern void free();		/* ANSI C; some old implementations say int */
 extern int atoi();
 extern long atol();
