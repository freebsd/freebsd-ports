--- ./xless.h.orig	1994-07-29 04:56:41.000000000 +0200
+++ ./xless.h	2014-06-13 14:48:54.067816752 +0200
@@ -38,13 +38,14 @@
 
 #define XLESS_MAX_INPUT		256
 
-/* handle differences between K&R and ANSI C */
+/* handle differences between K&R and ANSI C
 #if __STDC__
 #define __P(a)	a
 #else
 #define __P(a)	()
 #define const
 #endif
+*/
 
 /*
  * The default editor; make sure the file exists.
