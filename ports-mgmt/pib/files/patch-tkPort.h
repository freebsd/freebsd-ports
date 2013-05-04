--- ./tkPort.h.orig	1996-12-17 05:05:30.000000000 -0500
+++ ./tkPort.h	2013-05-04 09:54:01.114260299 -0400
@@ -133,8 +133,6 @@
  * in any other header file.
  */
 
-extern void		panic();
-
 /*
  * These functions do nothing under Unix, so we just eliminate calls them.
  */
