--- ./content/renderer/media/webrtc_audio_capturer.cc.orig	2014-08-12 21:01:18.000000000 +0200
+++ ./content/renderer/media/webrtc_audio_capturer.cc	2014-08-13 09:56:57.000000000 +0200
@@ -31,9 +31,7 @@
 // will fail if the user selects any rate outside these ranges.
 const int kValidInputRates[] =
     {192000, 96000, 48000, 44100, 32000, 16000, 8000};
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
-const int kValidInputRates[] = {48000, 44100};
-#elif defined(OS_ANDROID)
+#elif defined(OS_POSIX)
 const int kValidInputRates[] = {48000, 44100};
 #else
 const int kValidInputRates[] = {44100};
@@ -452,8 +450,8 @@
 // CaptureCallback.
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
-  // We have a special situation on Linux where the microphone volume can be
+#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+  // We have a special situation on POSIX where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
   // even if the reported maximum levels is N, the actual microphone level can
