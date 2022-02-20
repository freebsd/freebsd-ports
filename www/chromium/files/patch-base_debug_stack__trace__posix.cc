--- base/debug/stack_trace_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ base/debug/stack_trace_posix.cc
@@ -35,7 +35,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -693,6 +693,9 @@ class SandboxSymbolizeHelper {
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if defined(OS_BSD)
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -710,6 +713,7 @@ class SandboxSymbolizeHelper {
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
@@ -866,7 +870,7 @@ size_t CollectStackTrace(void** trace, size_t count) {
   // If we do not have unwind tables, then try tracing using frame pointers.
   return base::debug::TraceStackFramePointers(const_cast<const void**>(trace),
                                               count, 0);
-#elif !defined(__UCLIBC__) && !defined(_AIX)
+#elif !defined(__UCLIBC__) && !defined(_AIX) && !defined(OS_BSD)
   // Though the backtrace API man page does not list any possible negative
   // return values, we take no chance.
   return base::saturated_cast<size_t>(backtrace(trace, count));
