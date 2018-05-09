--- ext/opencv/gstfacedetect.c.orig	2011-12-30 13:24:28.000000000 -0500
+++ ext/opencv/gstfacedetect.c	2018-05-02 15:58:32.073221000 -0400
@@ -502,9 +502,7 @@ gst_face_detect_transform_ip (GstOpencvVideoFilter * b
         cvHaarDetectObjects (filter->cvGray, filter->cvFaceDetect,
         filter->cvStorage, filter->scale_factor, filter->min_neighbors,
         filter->flags, cvSize (filter->min_size_width, filter->min_size_height)
-#if (CV_MAJOR_VERSION >= 2) && (CV_MINOR_VERSION >= 2)
         , cvSize (filter->min_size_width + 2, filter->min_size_height + 2)
-#endif
         );
 
     if (faces && faces->total > 0) {
@@ -534,9 +532,7 @@ gst_face_detect_transform_ip (GstOpencvVideoFilter * b
           cvHaarDetectObjects (filter->cvGray, filter->cvNoseDetect,
           filter->cvStorage, filter->scale_factor, filter->min_neighbors,
           filter->flags, cvSize (mw, mh)
-#if (CV_MAJOR_VERSION >= 2) && (CV_MINOR_VERSION >= 2)
           , cvSize (mw + 2, mh + 2)
-#endif
           );
       have_nose = (nose && nose->total);
       cvResetImageROI (filter->cvGray);
@@ -550,9 +546,7 @@ gst_face_detect_transform_ip (GstOpencvVideoFilter * b
           cvHaarDetectObjects (filter->cvGray, filter->cvMouthDetect,
           filter->cvStorage, filter->scale_factor, filter->min_neighbors,
           filter->flags, cvSize (mw, mh)
-#if (CV_MAJOR_VERSION >= 2) && (CV_MINOR_VERSION >= 2)
           , cvSize (mw + 2, mh + 2)
-#endif
           );
       have_mouth = (mouth && mouth->total);
       cvResetImageROI (filter->cvGray);
@@ -566,9 +560,7 @@ gst_face_detect_transform_ip (GstOpencvVideoFilter * b
           cvHaarDetectObjects (filter->cvGray, filter->cvEyesDetect,
           filter->cvStorage, filter->scale_factor, filter->min_neighbors,
           filter->flags, cvSize (mw, mh)
-#if (CV_MAJOR_VERSION >= 2) && (CV_MINOR_VERSION >= 2)
           , cvSize (mw + 2, mh + 2)
-#endif
           );
       have_eyes = (eyes && eyes->total);
       cvResetImageROI (filter->cvGray);
