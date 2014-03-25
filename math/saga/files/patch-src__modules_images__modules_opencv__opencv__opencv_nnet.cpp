--- src/modules_images/modules_opencv/opencv/opencv_nnet.cpp.orig	2014-03-17 15:20:31.000000000 +0100
+++ src/modules_images/modules_opencv/opencv/opencv_nnet.cpp	2014-03-17 15:28:25.000000000 +0100
@@ -60,8 +60,8 @@
 
 //---------------------------------------------------------
 #include "opencv_nnet.h"
-#include "opencv\cxcore.h"
-#include "opencv\ml.h"
+#include <opencv/cxcore.h>
+#include <opencv/ml.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
