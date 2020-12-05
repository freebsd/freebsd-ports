--- chromecast/media/base/default_monotonic_clock.cc.orig	2020-11-13 06:36:40 UTC
+++ chromecast/media/base/default_monotonic_clock.cc
@@ -9,9 +9,9 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chromecast/media/base/buildflags.h"
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_FUCHSIA)
 #include <zircon/syscalls.h>
@@ -20,7 +20,7 @@
 namespace chromecast {
 namespace media {
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 int64_t MonotonicClockNow() {
   timespec now = {0, 0};
 #if BUILDFLAG(MEDIA_CLOCK_MONOTONIC_RAW)
