--- media/webrtc/audio_processor.cc.orig	2022-02-28 16:54:41 UTC
+++ media/webrtc/audio_processor.cc
@@ -487,7 +487,7 @@ absl::optional<double> AudioProcessor::ProcessData(
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   DCHECK_LE(volume, 1.0);
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    BUILDFLAG(IS_OPENBSD)
+    BUILDFLAG(IS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
