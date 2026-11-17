--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2026-11-17 11:49:09 UTC
+++ chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -113,7 +113,7 @@ bool DesktopMediaPickerController::IsSystemAudioCaptur
   } else {
     return media::IsMacCatapSystemLoopbackCaptureSupported();
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
