--- third_party/blink/renderer/modules/mediastream/media_stream_audio_processor.cc.orig	2022-01-21 13:38:48 UTC
+++ third_party/blink/renderer/modules/mediastream/media_stream_audio_processor.cc
@@ -677,7 +677,7 @@ absl::optional<double> MediaStreamAudioProcessor::Proc
   // controller.
 #if defined(OS_WIN) || defined(OS_MAC)
   DCHECK_LE(volume, 1.0);
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
