--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2026-08-13 16:48:13 UTC
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
