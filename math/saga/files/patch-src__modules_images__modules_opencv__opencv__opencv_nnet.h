--- src/modules_images/modules_opencv/opencv/opencv_nnet.h.orig	2014-03-17 15:06:15.000000000 +0100
+++ src/modules_images/modules_opencv/opencv/opencv_nnet.h	2014-03-17 15:18:58.000000000 +0100
@@ -64,8 +64,8 @@
 
 //---------------------------------------------------------
 #include "MLB_Interface.h"
-#include "opencv\cxcore.h"
-#include "opencv\ml.h"
+#include <opencv/cxcore.h>
+#include <opencv/ml.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
