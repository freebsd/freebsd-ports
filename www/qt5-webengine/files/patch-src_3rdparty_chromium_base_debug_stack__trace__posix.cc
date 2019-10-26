--- src/3rdparty/chromium/base/debug/stack_trace_posix.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/debug/stack_trace_posix.cc
@@ -35,7 +35,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -653,6 +653,11 @@ class SandboxSymbolizeHelper {
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
@@ -670,6 +675,7 @@ class SandboxSymbolizeHelper {
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
