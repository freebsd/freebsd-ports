--- base/time/time_now_posix.cc.orig	2025-09-06 10:01:20 UTC
+++ base/time/time_now_posix.cc
@@ -110,7 +110,11 @@ std::optional<TimeTicks> MaybeTimeTicksNowIgnoringOver
 }
 
 TimeTicks TimeTicksLowResolutionNowIgnoringOverride() {
+#if BUILDFLAG(IS_BSD)
+  return TimeTicks() + Microseconds(ClockNow(CLOCK_MONOTONIC));
+#else
   return TimeTicks() + Microseconds(ClockNow(CLOCK_MONOTONIC_COARSE));
+#endif
 }
 }  // namespace subtle
 
