--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -101,7 +101,7 @@ bool DesktopMediaPickerController::IsSystemAudioCaptur
             base::FeatureList::IsEnabled(
                 media::kMacCatapLoopbackAudioForScreenShare));
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
