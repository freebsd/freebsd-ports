--- ext/zxing/gstzxing.cpp.orig	2023-01-23 19:29:34 UTC
+++ ext/zxing/gstzxing.cpp
@@ -369,7 +369,7 @@ gst_zxing_transform_frame_ip (GstVideoFilter * vfilter
   if (result.isValid ()) {
     GST_DEBUG_OBJECT (zxing, "Symbol found. Text: %s Format: %s",
         result.text ().c_str (),
-        ToString (result.format ()));
+        ToString (result.format ()).c_str());
   } else {
     goto out;
   }
@@ -394,7 +394,7 @@ gst_zxing_transform_frame_ip (GstVideoFilter * vfilter
         "timestamp", G_TYPE_UINT64, timestamp,
         "stream-time", G_TYPE_UINT64, stream_time,
         "running-time", G_TYPE_UINT64, running_time,
-        "type", G_TYPE_STRING, ToString (result.format ()),
+        "type", G_TYPE_STRING, ToString (result.format ()).c_str(),
         "symbol", G_TYPE_STRING,
         result.text ().c_str (), NULL);
 
