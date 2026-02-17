--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -100,7 +100,7 @@ bool DesktopMediaPickerController::IsSystemAudioCaptur
             base::FeatureList::IsEnabled(
                 media::kMacCatapLoopbackAudioForScreenShare));
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
