--- src/3rdparty/chromium/content/renderer/media/stream/processed_local_audio_source.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/renderer/media/stream/processed_local_audio_source.cc
@@ -35,7 +35,7 @@ void* const kProcessedLocalAudioSourceIdentifier =
     const_cast<void**>(&kProcessedLocalAudioSourceIdentifier);
 
 bool ApmInAudioServiceEnabled() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return base::FeatureList::IsEnabled(features::kWebRtcApmInAudioService);
 #else
   return false;
@@ -355,7 +355,7 @@ void ProcessedLocalAudioSource::CaptureUsingProcessor(
     bool key_pressed) {
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_OPENBSD)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
