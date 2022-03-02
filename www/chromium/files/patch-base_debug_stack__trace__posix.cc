--- base/debug/stack_trace_posix.cc.orig	2022-02-28 16:54:41 UTC
+++ base/debug/stack_trace_posix.cc
@@ -37,7 +37,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -695,6 +695,9 @@ class SandboxSymbolizeHelper {
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if BUILDFLAG(IS_BSD)
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -712,6 +715,7 @@ class SandboxSymbolizeHelper {
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
@@ -868,7 +872,7 @@ size_t CollectStackTrace(void** trace, size_t count) {
   // If we do not have unwind tables, then try tracing using frame pointers.
   return base::debug::TraceStackFramePointers(const_cast<const void**>(trace),
                                               count, 0);
-#elif !defined(__UCLIBC__) && !defined(_AIX)
+#elif !defined(__UCLIBC__) && !defined(_AIX) && !BUILDFLAG(IS_BSD)
   // Though the backtrace API man page does not list any possible negative
   // return values, we take no chance.
   return base::saturated_cast<size_t>(backtrace(trace, count));
