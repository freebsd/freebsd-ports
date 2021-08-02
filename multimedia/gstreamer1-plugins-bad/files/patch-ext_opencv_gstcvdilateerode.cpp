--- ext/opencv/gstcvdilateerode.cpp.orig	2021-08-02 14:37:33 UTC
+++ ext/opencv/gstcvdilateerode.cpp
@@ -89,7 +89,7 @@ gst_cv_dilate_erode_get_type (void)
 {
   static volatile gsize opencv_dilate_erode_type = 0;
 
-  if (g_once_init_enter (&opencv_dilate_erode_type)) {
+  if (g_once_init_enter ((unsigned long *)&opencv_dilate_erode_type)) {
     GType _type;
     static const GTypeInfo opencv_dilate_erode_info = {
       sizeof (GstCvDilateErodeClass),
