--- src/lavfmuxer.cpp.orig	2013-06-16 09:57:51 UTC
+++ src/lavfmuxer.cpp
@@ -40,6 +40,10 @@ extern "C" {
 	#define CODEC_TYPE_AUDIO AVMEDIA_TYPE_AUDIO
 #endif
 
+#ifndef AVCODEC_MAX_AUDIO_FRAME_SIZE
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000 // 1 second of 48khz 32bit audio
+#endif
+
 lavfmuxer::lavfmuxer(const char *format, uint32_t audiostreammask, mpgfile &mpg, const char *filename)
     : muxer(), avfc(0), fileopened(false)
   {
