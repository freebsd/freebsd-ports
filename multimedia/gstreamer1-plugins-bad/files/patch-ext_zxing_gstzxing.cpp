--- ext/zxing/gstzxing.cpp.orig	2022-12-19 23:34:46 UTC
+++ ext/zxing/gstzxing.cpp
@@ -368,8 +368,8 @@ gst_zxing_transform_frame_ip (GstVideoFilter * vfilter
   auto result = ReadBarcode ({(unsigned char *)data, width, height, zxing->image_format}, hints);
   if (result.isValid ()) {
     GST_DEBUG_OBJECT (zxing, "Symbol found. Text: %s Format: %s",
-        TextUtfEncoding::ToUtf8 (result.text ()).c_str (),
-        ToString (result.format ()));
+        result.text ().c_str (),
+        ToString (result.format ()).c_str());
   } else {
     goto out;
   }
@@ -394,9 +394,9 @@ gst_zxing_transform_frame_ip (GstVideoFilter * vfilter
         "timestamp", G_TYPE_UINT64, timestamp,
         "stream-time", G_TYPE_UINT64, stream_time,
         "running-time", G_TYPE_UINT64, running_time,
-        "type", G_TYPE_STRING, ToString (result.format ()),
+        "type", G_TYPE_STRING, ToString (result.format ()).c_str(),
         "symbol", G_TYPE_STRING,
-        TextUtfEncoding::ToUtf8 (result.text ()).c_str (), NULL);
+        result.text ().c_str (), NULL);
 
     if (zxing->attach_frame) {
       /* create a sample from image */
