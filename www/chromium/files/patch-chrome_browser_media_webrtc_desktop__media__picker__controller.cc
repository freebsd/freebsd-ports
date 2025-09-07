--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2025-09-06 10:01:20 UTC
+++ chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -99,7 +99,7 @@ bool DesktopMediaPickerController::IsSystemAudioCaptur
             base::FeatureList::IsEnabled(
                 media::kMacCatapLoopbackAudioForScreenShare));
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
