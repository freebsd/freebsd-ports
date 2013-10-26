--- src/mgui/ffviewer.cpp.orig	2013-10-24 20:27:18.405577708 +0200
+++ src/mgui/ffviewer.cpp	2013-10-24 20:29:52.933598308 +0200
@@ -406,7 +406,7 @@
 
 #else // CALC_FF_TAG
 
-static std::string CodecID2Str(CodecID codec_id)
+static std::string CodecID2Str(AVCodecID codec_id)
 {
     return Int2Str(codec_id);
 }
