--- media/base/supported_types.cc.orig	2022-07-22 17:30:31 UTC
+++ media/base/supported_types.cc
@@ -205,7 +205,7 @@ bool IsHevcProfileSupported(const VideoType& type) {
     return false;
 
 #if BUILDFLAG(ENABLE_PLATFORM_HEVC)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS_LACROS)
   // TODO(b/171813538): For Lacros, the supplemental profile cache will be
   // asking lacros-gpu, but we will be doing decoding in ash-gpu. Until the
