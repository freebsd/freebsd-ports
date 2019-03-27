--- src/3rdparty/chromium/content/renderer/media/stream/processed_local_audio_source.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/renderer/media/stream/processed_local_audio_source.cc
@@ -267,7 +267,7 @@ void ProcessedLocalAudioSource::Capture(const media::A
                                         bool key_pressed) {
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_OPENBSD)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
