--- common/video/mpeg4-2000/idct/idct.hpp.orig	Thu Sep 30 01:01:36 2004
+++ common/video/mpeg4-2000/idct/idct.hpp	Thu Sep 30 01:01:56 2004
@@ -22,6 +22,9 @@
 #ifndef _INT_IDCT_
 #define _INT_IDCT_ 1
 
+#ifndef BLOCK_SIZE
+#define BLOCK_SIZE 5
+#endif
 
 #define IDCT_BLOCK_SIZE	8
 class idct{
