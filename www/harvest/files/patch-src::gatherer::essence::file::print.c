--- src/gatherer/essence/file/print.c.orig	Sat Dec 13 01:02:15 1997
+++ src/gatherer/essence/file/print.c	Wed Nov 13 08:56:34 2002
@@ -78,8 +78,8 @@
 warning(f, a)
      char *f, *a;
 {
-	extern int errno, sys_nerr;
 #ifdef NEED_SYS_ERRLIST
+	extern int errno, sys_nerr;
 	extern char *sys_errlist[];
 #endif
 	int myerrno;
