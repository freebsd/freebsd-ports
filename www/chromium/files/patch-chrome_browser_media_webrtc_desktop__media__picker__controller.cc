--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -93,7 +93,7 @@ bool DesktopMediaPickerController::IsSystemAudioCaptur
 #if BUILDFLAG(IS_MAC)
  return request_source == Params::RequestSource::kCast ||
      base::FeatureList::IsEnabled(media::kMacLoopbackAudioForScreenShare);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
