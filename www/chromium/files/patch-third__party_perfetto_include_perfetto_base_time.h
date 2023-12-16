--- third_party/perfetto/include/perfetto/base/time.h.orig	2023-12-10 06:10:27 UTC
+++ third_party/perfetto/include/perfetto/base/time.h
@@ -167,6 +167,9 @@ inline TimeNanos GetTimeInternalNs(clockid_t clk_id) {
 // Return ns from boot. Conversely to GetWallTimeNs, this clock counts also time
 // during suspend (when supported).
 inline TimeNanos GetBootTimeNs() {
+#if defined(__FreeBSD__)
+  return GetTimeInternalNs(kWallTimeClockSource);
+#else
   // Determine if CLOCK_BOOTTIME is available on the first call.
   static const clockid_t kBootTimeClockSource = [] {
     struct timespec ts = {};
@@ -174,6 +177,7 @@ inline TimeNanos GetBootTimeNs() {
     return res == 0 ? CLOCK_BOOTTIME : kWallTimeClockSource;
   }();
   return GetTimeInternalNs(kBootTimeClockSource);
+#endif
 }
 
 inline TimeNanos GetWallTimeNs() {
@@ -181,7 +185,13 @@ inline TimeNanos GetWallTimeNs() {
 }
 
 inline TimeNanos GetWallTimeRawNs() {
+#if defined(__OpenBSD__)
+  return GetTimeInternalNs(CLOCK_MONOTONIC);
+#elif defined(__FreeBSD__)
+  return GetTimeInternalNs(CLOCK_MONOTONIC_FAST);
+#else
   return GetTimeInternalNs(CLOCK_MONOTONIC_RAW);
+#endif
 }
 
 inline TimeNanos GetThreadCPUTimeNs() {
