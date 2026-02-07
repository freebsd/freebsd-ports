--- src/3rdparty/chromium/components/live_caption/caption_util.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/live_caption/caption_util.h
@@ -15,7 +15,7 @@ namespace captions {
 namespace captions {
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kCaptionSettingsUrl[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_MAC)
