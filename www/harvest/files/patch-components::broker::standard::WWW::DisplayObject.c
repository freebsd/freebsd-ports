--- components/broker/standard/WWW/DisplayObject.c.orig	Mon Feb 11 07:57:16 2002
+++ components/broker/standard/WWW/DisplayObject.c	Wed Nov 13 09:01:03 2002
@@ -215,8 +215,8 @@
 char *xstrerror(n)
 int n;
 {
-	extern int sys_nerr;
 #ifdef NEED_SYS_ERRLIST
+	extern int sys_nerr;
 	extern char *sys_errlist[];
 #endif
 
