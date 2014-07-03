--- src/modules/imagery/imagery_opencv/opencv_nnet.cpp.orig	2013-10-24 19:04:27.000000000 +0200
+++ src/modules/imagery/imagery_opencv/opencv_nnet.cpp	2013-10-24 19:06:05.000000000 +0200
@@ -60,8 +60,8 @@
 
 //---------------------------------------------------------
 #include "opencv_nnet.h"
-#include "opencv\cxcore.h"
-#include "opencv\ml.h"
+#include <opencv/cxcore.h>
+#include <opencv/ml.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
