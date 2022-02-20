--- chromecast/media/base/default_monotonic_clock.cc.orig	2022-02-07 13:39:41 UTC
+++ chromecast/media/base/default_monotonic_clock.cc
@@ -11,7 +11,7 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chromecast/media/base/buildflags.h"
 #endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
 
@@ -27,7 +27,7 @@ std::unique_ptr<MonotonicClock> MonotonicClock::Create
   return std::make_unique<DefaultMonotonicClock>();
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 int64_t MonotonicClockNow() {
   timespec now = {0, 0};
 #if BUILDFLAG(MEDIA_CLOCK_MONOTONIC_RAW)
