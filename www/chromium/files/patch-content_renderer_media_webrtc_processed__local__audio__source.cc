--- content/renderer/media/webrtc/processed_local_audio_source.cc.orig	2016-07-20 22:03:24.000000000 +0300
+++ content/renderer/media/webrtc/processed_local_audio_source.cc	2016-08-01 03:25:27.013281000 +0300
@@ -269,8 +269,8 @@
                                         bool key_pressed) {
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_OPENBSD)
-  // We have a special situation on Linux where the microphone volume can be
+#elif defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+  // We have a special situation on POSIX where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
   // even if the reported maximum levels is N, the actual microphone level can
