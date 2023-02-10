--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/base/time.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/base/time.h
@@ -142,6 +142,9 @@ inline TimeNanos GetBootTimeNs() {
 // Return ns from boot. Conversely to GetWallTimeNs, this clock counts also time
 // during suspend (when supported).
 inline TimeNanos GetBootTimeNs() {
+#if defined(__FreeBSD__)
+  return GetTimeInternalNs(kWallTimeClockSource);
+#else
   // Determine if CLOCK_BOOTTIME is available on the first call.
   static const clockid_t kBootTimeClockSource = [] {
     struct timespec ts = {};
@@ -149,6 +152,7 @@ inline TimeNanos GetBootTimeNs() {
     return res == 0 ? CLOCK_BOOTTIME : kWallTimeClockSource;
   }();
   return GetTimeInternalNs(kBootTimeClockSource);
+#endif
 }
 
 inline TimeNanos GetWallTimeNs() {
