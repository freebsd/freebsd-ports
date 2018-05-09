--- ext/opencv/gstfaceblur.c.orig	2011-12-30 13:24:28.000000000 -0500
+++ ext/opencv/gstfaceblur.c	2018-05-02 15:58:32.070297000 -0400
@@ -268,9 +268,7 @@ gst_face_blur_chain (GstPad * pad, GstBuffer * buf)
     faces =
         cvHaarDetectObjects (filter->cvGray, filter->cvCascade,
         filter->cvStorage, 1.1, 2, 0, cvSize (30, 30)
-#if (CV_MAJOR_VERSION >= 2) && (CV_MINOR_VERSION >= 2)
         , cvSize (32, 32)
-#endif
         );
 
     if (faces && faces->total > 0) {
