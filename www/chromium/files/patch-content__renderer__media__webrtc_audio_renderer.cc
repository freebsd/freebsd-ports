--- content/renderer/media/webrtc_audio_renderer.cc.orig	2013-09-02 21:19:42.000000000 +0300
+++ content/renderer/media/webrtc_audio_renderer.cc	2013-09-02 21:21:52.000000000 +0300
@@ -31,7 +31,7 @@
 // rates below adds restrictions and Initialize() will fail if the user selects
 // any rate outside these ranges.
 const int kValidOutputRates[] = {96000, 48000, 44100, 32000, 16000};
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const int kValidOutputRates[] = {48000, 44100};
 #elif defined(OS_ANDROID)
 // TODO(leozwang): We want to use native sampling rate on Android to achieve
