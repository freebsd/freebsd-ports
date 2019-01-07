--- third_party/perfetto/include/perfetto/base/time.h.orig	2018-12-16 01:32:46.000000000 +0100
+++ third_party/perfetto/include/perfetto/base/time.h	2018-12-16 01:38:40.852314000 +0100
@@ -123,6 +123,9 @@
 // Return ns from boot. Conversely to GetWallTimeNs, this clock counts also time
 // during suspend (when supported).
 inline TimeNanos GetBootTimeNs() {
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+  return GetTimeInternalNs(kWallTimeClockSource);
+#else
   // Determine if CLOCK_BOOTTIME is available on the first call.
   static const clockid_t kBootTimeClockSource = [] {
     struct timespec ts = {};
@@ -130,6 +133,7 @@
     return res == 0 ? CLOCK_BOOTTIME : kWallTimeClockSource;
   }();
   return GetTimeInternalNs(kBootTimeClockSource);
+#endif
 }
 
 inline TimeNanos GetWallTimeNs() {
