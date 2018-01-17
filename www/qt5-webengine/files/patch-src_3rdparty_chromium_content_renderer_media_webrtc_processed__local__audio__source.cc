--- src/3rdparty/chromium/content/renderer/media/webrtc/processed_local_audio_source.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/renderer/media/webrtc/processed_local_audio_source.cc
@@ -269,8 +269,8 @@ void ProcessedLocalAudioSource::Capture(
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
