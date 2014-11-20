--- content/renderer/media/webrtc_audio_capturer.cc.orig	2014-10-10 09:15:31 UTC
+++ content/renderer/media/webrtc_audio_capturer.cc
@@ -448,8 +448,8 @@
 // CaptureCallback.
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_OPENBSD)
-  // We have a special situation on Linux where the microphone volume can be
+#elif defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+  // We have a special situation on POSIX where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
   // even if the reported maximum levels is N, the actual microphone level can
