--- third_party/perfetto/include/perfetto/base/time.h.orig	2023-11-22 14:00:11 UTC
+++ third_party/perfetto/include/perfetto/base/time.h
@@ -166,6 +166,9 @@ inline TimeNanos GetTimeInternalNs(clockid_t clk_id) {
 // Return ns from boot. Conversely to GetWallTimeNs, this clock counts also time
 // during suspend (when supported).
 inline TimeNanos GetBootTimeNs() {
+#if defined(__FreeBSD__)
+  return GetTimeInternalNs(kWallTimeClockSource);
+#else
   // Determine if CLOCK_BOOTTIME is available on the first call.
   static const clockid_t kBootTimeClockSource = [] {
     struct timespec ts = {};
@@ -173,6 +176,7 @@ inline TimeNanos GetBootTimeNs() {
     return res == 0 ? CLOCK_BOOTTIME : kWallTimeClockSource;
   }();
   return GetTimeInternalNs(kBootTimeClockSource);
+#endif
 }
 
 inline TimeNanos GetWallTimeNs() {
@@ -180,7 +184,13 @@ inline TimeNanos GetWallTimeNs() {
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
