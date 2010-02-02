--- ./c_packages/safe_malloc/fatal.c.orig	1991-09-21 23:13:52.000000000 -0400
+++ ./c_packages/safe_malloc/fatal.c	2010-02-02 14:21:04.000000000 -0500
@@ -8,8 +8,8 @@
 #include "safe_malloc.h"
 
 extern int errno;
-extern char *sys_errlist[];
-extern int sys_nerr;
+/*extern char *sys_errlist[];
+extern int sys_nerr;*/
 
 fatal(fmt, a1, a2, a3, a4, a5)
   char *fmt, *a1, *a2, *a3, *a4, *a5;
