--- ext/opencv/gstfaceblur.h.orig	2011-12-30 13:24:28.000000000 -0500
+++ ext/opencv/gstfaceblur.h	2018-05-02 15:58:32.071694000 -0400
@@ -49,10 +49,6 @@
 #include <gst/gst.h>
 #include <cv.h>
 
-#if (CV_MAJOR_VERSION >= 2) && (CV_MINOR_VERSION >= 2)
-#include <opencv2/objdetect/objdetect.hpp>
-#endif
-
 G_BEGIN_DECLS
 /* #defines don't like whitespacey bits */
 #define GST_TYPE_FACE_BLUR \
