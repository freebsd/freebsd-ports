--- src/common/util/strerror.c.orig	Mon Mar 17 07:16:32 1997
+++ src/common/util/strerror.c	Wed Nov 13 08:58:11 2002
@@ -89,8 +89,10 @@
 char *strerror(n)
      int n;
 {
+#ifndef __FreeBSD__
     extern int sys_nerr;
     extern char *sys_errlist[];
+#endif
 
     if (n < 0 || n >= sys_nerr)
 	return (NULL);
