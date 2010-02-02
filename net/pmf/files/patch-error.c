--- ./error.c.orig	1991-09-21 23:13:05.000000000 -0400
+++ ./error.c	2010-02-02 14:21:04.000000000 -0500
@@ -15,8 +15,8 @@
 #include "pmf.h"
 
 extern int errno;
-extern char *sys_errlist[];
-extern int sys_nerr;
+/* extern char *sys_errlist[];
+extern int sys_nerr; */
 
 /*---------------------------------------------------------------------------*/
 
