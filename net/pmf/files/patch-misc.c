--- ./misc.c.orig	1991-09-21 23:13:43.000000000 -0400
+++ ./misc.c	2010-02-02 14:21:04.000000000 -0500
@@ -16,7 +16,7 @@
 #include "config.h"
 #include "globals.h"
 
-extern long time();
+extern time_t time();
 extern char *ctime();
 
 /*---------------------------------------------------------------------------*/
