--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -115,7 +115,7 @@ bool DesktopMediaPickerController::IsSystemAudioCaptur
   } else {
     return media::IsMacCatapSystemLoopbackCaptureSupported();
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
