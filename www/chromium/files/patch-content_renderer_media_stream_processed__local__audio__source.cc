--- content/renderer/media/stream/processed_local_audio_source.cc.orig	2018-12-12 22:56:07.000000000 +0100
+++ content/renderer/media/stream/processed_local_audio_source.cc	2019-01-09 12:08:00.136944000 +0100
@@ -35,7 +35,7 @@
     const_cast<void**>(&kProcessedLocalAudioSourceIdentifier);

 bool ApmInAudioServiceEnabled() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return base::FeatureList::IsEnabled(features::kWebRtcApmInAudioService);
 #else
   return false;
@@ -341,7 +341,7 @@
     bool key_pressed) {
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_OPENBSD)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
