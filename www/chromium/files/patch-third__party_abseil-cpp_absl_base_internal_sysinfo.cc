--- third_party/abseil-cpp/absl/base/internal/sysinfo.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/abseil-cpp/absl/base/internal/sysinfo.cc
@@ -30,7 +30,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -308,9 +308,11 @@ static double GetNominalCPUFrequency() {
   // a new mode (turbo mode). Essentially, those frequencies cannot
   // always be relied upon. The same reasons apply to /proc/cpuinfo as
   // well.
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) // pledge violation
   if (ReadLongFromFile("/sys/devices/system/cpu/cpu0/tsc_freq_khz", &freq)) {
     return freq * 1e3;  // Value is kHz.
   }
+#endif
 
 #if defined(ABSL_INTERNAL_UNSCALED_CYCLECLOCK_FREQUENCY_IS_CPU_FREQUENCY)
   // On these platforms, the TSC frequency is the nominal CPU
