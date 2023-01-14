--- src/3rdparty/chromium/media/base/supported_types.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/base/supported_types.cc
@@ -205,7 +205,7 @@ bool IsHevcProfileSupported(const VideoType& type) {
     return false;
 
 #if BUILDFLAG(ENABLE_PLATFORM_HEVC)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetSupplementalProfileCache()->IsProfileSupported(type.profile);
 #else
   return true;
