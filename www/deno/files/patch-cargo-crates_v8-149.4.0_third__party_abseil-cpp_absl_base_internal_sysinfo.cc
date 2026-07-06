--- cargo-crates/v8-149.4.0/third_party/abseil-cpp/absl/base/internal/sysinfo.cc.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-149.4.0/third_party/abseil-cpp/absl/base/internal/sysinfo.cc
@@ -30,7 +30,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -198,6 +198,7 @@ static double GetNominalCPUFrequency() {
 
 #else
 
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 // Helper function for reading a long from a file. Returns true if successful
 // and the memory location pointed to by value is set to the value read.
 static bool ReadLongFromFile(const char *file, long *value) {
@@ -230,6 +231,7 @@ static bool ReadLongFromFile(const char *file, long *v
   }
   return ret;
 }
+#endif
 
 #if defined(ABSL_INTERNAL_UNSCALED_CYCLECLOCK_FREQUENCY_IS_CPU_FREQUENCY)
 
@@ -328,9 +330,11 @@ static double GetNominalCPUFrequency() {
   // a new mode (turbo mode). Essentially, those frequencies cannot
   // always be relied upon. The same reasons apply to /proc/cpuinfo as
   // well.
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
   if (ReadLongFromFile("/sys/devices/system/cpu/cpu0/tsc_freq_khz", &freq)) {
     return freq * 1e3;  // Value is kHz.
   }
+#endif
 
 #if defined(ABSL_INTERNAL_UNSCALED_CYCLECLOCK_FREQUENCY_IS_CPU_FREQUENCY)
   // On these platforms, the TSC frequency is the nominal CPU
@@ -349,10 +353,12 @@ static double GetNominalCPUFrequency() {
   // If CPU scaling is in effect, we want to use the *maximum*
   // frequency, not whatever CPU speed some random processor happens
   // to be using now.
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
   if (ReadLongFromFile("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq",
                        &freq)) {
     return freq * 1e3;  // Value is kHz.
   }
+#endif
 
   return 1.0;
 #endif  // !ABSL_INTERNAL_UNSCALED_CYCLECLOCK_FREQUENCY_IS_CPU_FREQUENCY
@@ -398,6 +404,12 @@ pid_t GetTID() {
 
 pid_t GetTID() {
   return static_cast<pid_t>(syscall(SYS_gettid));
+}
+
+#elif defined(__OpenBSD__)
+
+pid_t GetTID() {
+  return getthrid();
 }
 
 #elif defined(__akaros__)
