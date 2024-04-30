--- src/3rdparty/chromium/components/live_caption/caption_util.h.orig	2023-07-16 15:47:57 UTC
+++ src/3rdparty/chromium/components/live_caption/caption_util.h
@@ -14,7 +14,7 @@ class PrefService;
 namespace captions {
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kCaptionSettingsUrl[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_MAC)
