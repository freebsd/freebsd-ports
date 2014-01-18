--- src/image_process.h.orig	2014-01-18 09:13:38.000000000 +0900
+++ src/image_process.h	2014-01-18 09:14:25.000000000 +0900
@@ -154,7 +154,7 @@
  ****************************************************************/
 
 #ifdef HAVE_LIBAFFLIB
-//#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
+#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
 #include <afflib/afflib.h>
 #include <vector>			
 class process_aff : public image_process {
