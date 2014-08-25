--- ./content/renderer/media/webrtc_audio_renderer.cc.orig	2014-08-20 21:02:43.000000000 +0200
+++ ./content/renderer/media/webrtc_audio_renderer.cc	2014-08-22 15:06:26.000000000 +0200
@@ -34,7 +34,7 @@
 // rates below adds restrictions and Initialize() will fail if the user selects
 // any rate outside these ranges.
 const int kValidOutputRates[] = {96000, 48000, 44100, 32000, 16000};
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const int kValidOutputRates[] = {48000, 44100};
 #elif defined(OS_ANDROID)
 // TODO(leozwang): We want to use native sampling rate on Android to achieve
