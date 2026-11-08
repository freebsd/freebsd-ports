--- src/brave/chromium_src/media/base/media_switches.h.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/media/base/media_switches.h
@@ -12,7 +12,7 @@
 
 namespace media {
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_PLATFORM_HEVC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_PLATFORM_HEVC)
 // Killswitch for the bundled FFmpeg HEVC software decoder on Linux. Enabled by
 // default; lets us disable HEVC decoding remotely (via Griffin) or locally
 // (via brave://flags) without rebuilding if a regression shows up.
