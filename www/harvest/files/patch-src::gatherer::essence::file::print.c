--- src/gatherer/essence/file/print.c.orig	Sat Nov 16 08:09:53 2002
+++ src/gatherer/essence/file/print.c	Sat Nov 23 04:28:48 2002
@@ -78,10 +78,12 @@
 warning(f, a)
      char *f, *a;
 {
+#if !defined(__FreeBSD__)
 	extern int errno, sys_nerr;
 #ifndef __CYGWIN__
 #ifdef NEED_SYS_ERRLIST
 	extern char *sys_errlist[];
+#endif
 #endif
 #endif
 	int myerrno;
