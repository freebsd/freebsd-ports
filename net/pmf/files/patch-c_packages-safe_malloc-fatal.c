--- c_packages/safe_malloc/fatal.c.orig	Mon Nov 18 18:14:28 2002
+++ c_packages/safe_malloc/fatal.c	Mon Nov 18 18:15:21 2002
@@ -8,8 +8,8 @@
 #include "safe_malloc.h"
 
 extern int errno;
-extern char *sys_errlist[];
-extern int sys_nerr;
+/*extern char *sys_errlist[];
+extern int sys_nerr;*/
 
 fatal(fmt, a1, a2, a3, a4, a5)
   char *fmt, *a1, *a2, *a3, *a4, *a5;
