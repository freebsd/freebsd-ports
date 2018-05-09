--- ext/opencv/gstfacedetect.h.orig	2011-12-30 13:24:28.000000000 -0500
+++ ext/opencv/gstfacedetect.h	2018-05-02 15:58:32.074608000 -0400
@@ -51,9 +51,7 @@
 #include <cv.h>
 #include "gstopencvvideofilter.h"
 
-#if (CV_MAJOR_VERSION >= 2) && (CV_MINOR_VERSION >= 2)
-#include <opencv2/objdetect/objdetect.hpp>
-#endif
+#include <opencv2/imgcodecs/imgcodecs_c.h>
 
 G_BEGIN_DECLS
 /* #defines don't like whitespacey bits */
