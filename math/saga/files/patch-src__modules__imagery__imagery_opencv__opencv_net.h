--- src/modules/imagery/imagery_opencv/opencv_nnet.h.orig	2013-10-24 19:07:03.000000000 +0200
+++ src/modules/imagery/imagery_opencv/opencv_nnet.h	2013-10-24 19:08:34.000000000 +0200
@@ -64,8 +64,8 @@
 
 //---------------------------------------------------------
 #include "MLB_Interface.h"
-#include "opencv\cxcore.h"
-#include "opencv\ml.h"
+#include <opencv/cxcore.h>
+#include <opencv/ml.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
