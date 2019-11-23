--- src/3rdparty/chromium/third_party/abseil-cpp/absl/base/internal/unscaledcycleclock.cc.orig	2019-05-23 14:39:34.000000000 +0200
+++ src/3rdparty/chromium/third_party/abseil-cpp/absl/base/internal/unscaledcycleclock.cc	2019-10-27 21:56:29.777821000 +0100
@@ -20,7 +20,7 @@
 #include <intrin.h>
 #endif
 
-#if defined(__powerpc__) || defined(__ppc__)
+#if (defined(__powerpc__) || defined(__ppc__)) && defined(__GLIBC__)
 #include <sys/platform/ppc.h>
 #endif
 
@@ -53,7 +53,7 @@
   return base_internal::NominalCPUFrequency();
 }
 
-#elif defined(__powerpc__) || defined(__ppc__)
+#elif (defined(__powerpc__) || defined(__ppc__)) && defined(__GLIBC__)
 
 int64_t UnscaledCycleClock::Now() {
   return __ppc_get_timebase();
