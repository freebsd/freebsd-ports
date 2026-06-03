--- components/live_caption/caption_util.cc.orig	2025-11-01 06:40:37 UTC
+++ components/live_caption/caption_util.cc
@@ -139,7 +139,7 @@ bool IsHeadlessCaptionFeatureSupported() {
 std::string GetCaptionSettingsUrl() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chrome://os-settings/audioAndCaptions";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #elif BUILDFLAG(IS_WIN)
   return base::win::GetVersion() >= base::win::Version::WIN10
