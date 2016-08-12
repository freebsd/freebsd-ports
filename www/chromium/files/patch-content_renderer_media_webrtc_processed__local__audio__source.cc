--- ./content/renderer/media/webrtc/processed_local_audio_source.cc.orig	2016-08-03 12:48:04.721257000 -0400
+++ ./content/renderer/media/webrtc/processed_local_audio_source.cc	2016-08-03 12:48:34.201210000 -0400
@@ -269,7 +269,7 @@
                                         bool key_pressed) {
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_OPENBSD)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
