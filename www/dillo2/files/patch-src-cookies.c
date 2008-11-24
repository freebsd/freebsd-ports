--- src/cookies.c.orig	2008-09-28 22:57:42.000000000 +0400
+++ src/cookies.c	2008-11-24 17:21:06.000000000 +0300
@@ -17,6 +17,8 @@
 
 #ifdef DISABLE_COOKIES
 
+#include "msg.h"
+
 /*
  * Initialize the cookies module
  */
