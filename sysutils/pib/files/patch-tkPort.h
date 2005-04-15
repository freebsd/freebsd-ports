--- tkPort.h.orig	Wed Apr 13 17:30:58 2005
+++ tkPort.h	Wed Apr 13 17:30:13 2005
@@ -133,8 +133,6 @@ extern int errno;
  * in any other header file.
  */
 
-extern void		panic();
-
 /*
  * These functions do nothing under Unix, so we just eliminate calls them.
  */

