--- src/3rdparty/chromium/base/time/time_now_posix.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/time/time_now_posix.cc
@@ -27,7 +27,7 @@
 #endif
 
 // NaCl doesn't support CLOCK_MONOTONIC_COARSE.
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
 #define TIMETICKS_LOW_RESOLUTION_CLOCK CLOCK_MONOTONIC
 #else
 #define TIMETICKS_LOW_RESOLUTION_CLOCK CLOCK_MONOTONIC_COARSE
