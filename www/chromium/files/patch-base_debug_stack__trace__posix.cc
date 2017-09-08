--- base/debug/stack_trace_posix.cc.orig	2017-07-25 21:04:48.000000000 +0200
+++ base/debug/stack_trace_posix.cc	2017-08-02 18:45:42.071358000 +0200
@@ -34,7 +34,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -574,6 +574,11 @@
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if defined(OS_BSD)
+    // TODO (rene) avoid link error, implement something?
+    NOTIMPLEMENTED();
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -589,6 +594,7 @@
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
@@ -721,7 +727,7 @@
 // NOTE: This code MUST be async-signal safe (it's used by in-process
 // stack dumping signal handler). NO malloc or stdio is allowed here.
 
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !defined(OS_BSD)
   count = std::min(arraysize(trace_), count);
 
   // Though the backtrace API man page does not list any possible negative
