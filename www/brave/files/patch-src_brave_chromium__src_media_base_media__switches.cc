--- src/brave/chromium_src/media/base/media_switches.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/media/base/media_switches.cc
@@ -9,7 +9,7 @@
 
 namespace media {
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_PLATFORM_HEVC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_PLATFORM_HEVC)
 BASE_FEATURE(kFFmpegSoftwareHEVCDecoder, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
