--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/time.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/time.h
@@ -123,6 +123,9 @@ inline TimeNanos GetTimeInternalNs(clockid_t clk_id) {
 // Return ns from boot. Conversely to GetWallTimeNs, this clock counts also time
 // during suspend (when supported).
 inline TimeNanos GetBootTimeNs() {
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+  return GetTimeInternalNs(kWallTimeClockSource);
+#else
   // Determine if CLOCK_BOOTTIME is available on the first call.
   static const clockid_t kBootTimeClockSource = [] {
     struct timespec ts = {};
@@ -130,6 +133,7 @@ inline TimeNanos GetBootTimeNs() {
     return res == 0 ? CLOCK_BOOTTIME : kWallTimeClockSource;
   }();
   return GetTimeInternalNs(kBootTimeClockSource);
+#endif
 }
 
 inline TimeNanos GetWallTimeNs() {
