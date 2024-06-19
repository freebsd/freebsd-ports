--- components/live_caption/caption_util.cc.orig	2024-05-21 18:07:39 UTC
+++ components/live_caption/caption_util.cc
@@ -144,7 +144,7 @@ std::string GetCaptionSettingsUrl() {
   return "chrome://os-settings/audioAndCaptions";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #endif  // BUILDFLAG(IS_LINUX)
 
