--- content/renderer/media/stream/processed_local_audio_source.cc.orig	2018-07-19 12:34:51.152323000 +0200
+++ content/renderer/media/stream/processed_local_audio_source.cc	2018-07-19 12:35:37.574081000 +0200
@@ -282,7 +282,7 @@
                                         bool key_pressed) {
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_OPENBSD)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
