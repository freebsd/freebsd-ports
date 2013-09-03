--- content/renderer/media/webrtc_audio_capturer.cc.orig	2013-09-02 21:19:59.000000000 +0300
+++ content/renderer/media/webrtc_audio_capturer.cc	2013-09-02 21:22:12.000000000 +0300
@@ -24,7 +24,7 @@
 // The listed rates below adds restrictions and WebRtcAudioDeviceImpl::Init()
 // will fail if the user selects any rate outside these ranges.
 static int kValidInputRates[] = {96000, 48000, 44100, 32000, 16000, 8000};
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 static int kValidInputRates[] = {48000, 44100};
 #elif defined(OS_ANDROID)
 static int kValidInputRates[] = {48000, 44100};
@@ -37,7 +37,7 @@
 #if defined(OS_WIN) || defined(OS_MACOSX)
   // Use a buffer size of 10ms.
   buffer_size = (sample_rate / 100);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Based on tests using the current ALSA implementation in Chrome, we have
   // found that the best combination is 20ms on the input side and 10ms on the
   // output side.
