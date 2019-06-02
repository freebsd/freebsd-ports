--- src/zm_video.cpp.orig	2018-12-08 14:22:36 UTC
+++ src/zm_video.cpp
@@ -455,11 +455,12 @@ int X264MP4Writer::x264encodeloop(bool bFlush) {
 
       /* Write the sample */
       if ( !buffer.empty() ) {
+        unsigned int bufSize = buffer.size();
         if ( !MP4WriteSample(
               mp4h,
               mp4vtid,
-              buffer.extract(buffer.size()),
-              buffer.size(),
+              buffer.extract(bufSize),
+              bufSize,
               duration,
               offset,
               prevKeyframe) ) {
