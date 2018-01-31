--- src/tsrm.c.orig	2016-09-14 15:02:26 UTC
+++ src/tsrm.c
@@ -25,7 +25,6 @@
 /*
  * Includes order: from local to global
  */
-#define _XOPEN_SOURCE 700   // Required by pthread_mutex_setattr
 
 #include "tsrm.h"
 
