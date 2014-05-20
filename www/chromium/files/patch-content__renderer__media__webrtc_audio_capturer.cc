--- ./content/renderer/media/webrtc_audio_capturer.cc.orig	2014-04-30 22:41:47.000000000 +0200
+++ ./content/renderer/media/webrtc_audio_capturer.cc	2014-05-04 14:38:47.000000000 +0200
@@ -29,10 +29,10 @@
 // The listed rates below adds restrictions and WebRtcAudioDeviceImpl::Init()
 // will fail if the user selects any rate outside these ranges.
 const int kValidInputRates[] = {96000, 48000, 44100, 32000, 16000, 8000};
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
-const int kValidInputRates[] = {48000, 44100};
 #elif defined(OS_ANDROID)
 const int kValidInputRates[] = {48000, 44100};
+#elif defined(OS_POSIX)
+const int kValidInputRates[] = {48000, 44100};
 #else
 const int kValidInputRates[] = {44100};
 #endif
@@ -430,7 +430,7 @@
 // CaptureCallback.
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
