--- src/3rdparty/chromium/media/base/supported_types.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/media/base/supported_types.cc
@@ -206,7 +206,7 @@ bool IsHevcProfileSupported(const VideoType& type) {
 
 #if BUILDFLAG(ENABLE_PLATFORM_HEVC)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS_LACROS)
   // TODO(b/171813538): For Lacros, the supplemental profile cache will be
   // asking lacros-gpu, but we will be doing decoding in ash-gpu. Until the
