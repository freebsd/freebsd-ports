--- components/live_caption/caption_util.cc.orig	2026-09-25 15:26:43 UTC
+++ components/live_caption/caption_util.cc
@@ -142,7 +142,7 @@ bool IsHeadlessCaptionFeatureSupported() {
 std::string GetCaptionSettingsUrl() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chrome://os-settings/audioAndCaptions";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #elif BUILDFLAG(IS_WIN)
   return base::win::GetVersion() >= base::win::Version::WIN10
