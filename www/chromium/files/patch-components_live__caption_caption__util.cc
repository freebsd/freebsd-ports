--- components/live_caption/caption_util.cc.orig	2024-10-22 08:31:56 UTC
+++ components/live_caption/caption_util.cc
@@ -139,7 +139,7 @@ std::string GetCaptionSettingsUrl() {
   return "chrome://os-settings/audioAndCaptions";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #endif  // BUILDFLAG(IS_LINUX)
 
