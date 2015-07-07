--- src/modules/imagery/imagery_opencv/opencv_nnet.h.orig	2015-02-26 07:51:59 UTC
+++ src/modules/imagery/imagery_opencv/opencv_nnet.h
@@ -64,8 +64,8 @@
 
 //---------------------------------------------------------
 #include "MLB_Interface.h"
-#include "opencv\cxcore.h"
-#include "opencv\ml.h"
+#include <opencv/cxcore.h>
+#include <opencv/ml.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
