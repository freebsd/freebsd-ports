--- error.c.orig	Mon Nov 18 18:08:20 2002
+++ error.c	Mon Nov 18 18:08:48 2002
@@ -15,8 +15,8 @@
 #include "pmf.h"
 
 extern int errno;
-extern char *sys_errlist[];
-extern int sys_nerr;
+/* extern char *sys_errlist[];
+extern int sys_nerr; */
 
 /*---------------------------------------------------------------------------*/

