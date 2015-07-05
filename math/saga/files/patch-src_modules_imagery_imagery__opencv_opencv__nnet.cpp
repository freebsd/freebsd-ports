--- src/modules/imagery/imagery_opencv/opencv_nnet.cpp.orig	2015-02-26 07:51:59 UTC
+++ src/modules/imagery/imagery_opencv/opencv_nnet.cpp
@@ -60,8 +60,8 @@
 
 //---------------------------------------------------------
 #include "opencv_nnet.h"
-#include "opencv\cxcore.h"
-#include "opencv\ml.h"
+#include <opencv/cxcore.h>
+#include <opencv/ml.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
