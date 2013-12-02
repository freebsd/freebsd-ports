--- src/lavfmuxer.cpp~	2013-06-16 11:57:51.000000000 +0200
+++ src/lavfmuxer.cpp	2013-11-29 22:24:36.075415060 +0100
@@ -40,6 +40,10 @@
 	#define CODEC_TYPE_AUDIO AVMEDIA_TYPE_AUDIO
 #endif
 
+#ifndef AVCODEC_MAX_AUDIO_FRAME_SIZE
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000 // 1 second of 48khz 32bit audio
+#endif
+
 lavfmuxer::lavfmuxer(const char *format, uint32_t audiostreammask, mpgfile &mpg, const char *filename)
     : muxer(), avfc(0), fileopened(false)
   {
