--- erpcd/spy.c.orig	Mon May  5 16:09:35 1997
+++ erpcd/spy.c	Thu Sep 18 20:10:32 2003
@@ -34,8 +34,10 @@
 
 int debug = 0;
 
+#if !defined(__FreeBSD__)
 extern int errno;
 extern char *sys_errlist[];	/* errno strings */
+#endif
 
 static void timeout();
 
