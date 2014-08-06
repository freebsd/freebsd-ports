--- src/image_process.h.orig	2014-08-06 23:40:34.000000000 +0900
+++ src/image_process.h	2014-08-06 23:40:05.000000000 +0900
@@ -157,7 +157,7 @@
  ****************************************************************/
 
 #ifdef HAVE_LIBAFFLIB
-//#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
+#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
 #include <afflib/afflib.h>
 #include <vector>			
 class process_aff : public image_process {
