--- content/renderer/media/webrtc_audio_capturer.cc.orig	2013-08-30 06:45:44.000000000 +0300
+++ content/renderer/media/webrtc_audio_capturer.cc	2013-09-03 21:47:30.139633005 +0300
@@ -26,10 +26,10 @@
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
@@ -39,14 +39,14 @@
 #if defined(OS_WIN) || defined(OS_MACOSX)
   // Use a buffer size of 10ms.
   buffer_size = (sample_rate / 100);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_ANDROID)
+  // TODO(leozwang): Tune and adjust buffer size on Android.
+  buffer_size = 2 * sample_rate / 100;
+#elif defined(OS_POSIX)
   // Based on tests using the current ALSA implementation in Chrome, we have
   // found that the best combination is 20ms on the input side and 10ms on the
   // output side.
   buffer_size = 2 * sample_rate / 100;
-#elif defined(OS_ANDROID)
-  // TODO(leozwang): Tune and adjust buffer size on Android.
-    buffer_size = 2 * sample_rate / 100;
 #endif
   return buffer_size;
 }
@@ -430,7 +430,7 @@
   // CaptureCallback.
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
