--- src/3rdparty/chromium/components/live_caption/caption_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/live_caption/caption_util.cc
@@ -136,7 +136,7 @@ std::string GetCaptionSettingsUrl() {
 std::string GetCaptionSettingsUrl() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chrome://os-settings/audioAndCaptions";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #elif BUILDFLAG(IS_WIN)
   return base::win::GetVersion() >= base::win::Version::WIN10
