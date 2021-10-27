--- a/absl/base/internal/unscaledcycleclock.cc.orig	2021-10-11 21:53:31.946215000 +0200
+++ b/absl/base/internal/unscaledcycleclock.cc	2021-10-11 21:57:54.536557000 +0200
@@ -21,8 +21,15 @@
 #endif
 
 #if defined(__powerpc__) || defined(__ppc__)
+#ifdef __linux__
 #include <sys/platform/ppc.h>
+#else
+#include "absl/base/call_once.h"
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <threads.h>
 #endif
+#endif
 
 #include "absl/base/internal/sysinfo.h"
 
@@ -56,11 +63,28 @@
 #elif defined(__powerpc__) || defined(__ppc__)
 
 int64_t UnscaledCycleClock::Now() {
+#ifdef __linux__
   return __ppc_get_timebase();
+#else
+  int64_t tbr;
+  asm volatile("mfspr %0, 268" : "=r"(tbr));
+  return tbr;
+#endif
 }
 
 double UnscaledCycleClock::Frequency() {
+#ifdef __linux__
   return __ppc_get_timebase_freq();
+#else
+  static once_flag init_timebase_frequency_once;
+  static double timebase_frequency = 0.0;
+  base_internal::LowLevelCallOnce(&init_timebase_frequency_once, [&]() {
+    size_t length = sizeof(timebase_frequency);
+    sysctlbyname("kern.timecounter.tc.timebase.frequency", &timebase_frequency,
+                 &length, nullptr, 0);
+  });
+  return timebase_frequency;
+#endif
 }
 
 #elif defined(__aarch64__)
