--- components/broker/standard/WWW/DisplayObject.c.orig	Mon Feb 11 07:57:16 2002
+++ components/broker/standard/WWW/DisplayObject.c	Sat Nov 23 04:30:56 2002
@@ -214,10 +214,12 @@
  */
 char *xstrerror(n)
 int n;
+#if !defined(__FreeBSD__)
 {
 	extern int sys_nerr;
 #ifdef NEED_SYS_ERRLIST
 	extern char *sys_errlist[];
+#endif
 #endif
 
 	if (n < 0 || n >= sys_nerr)
