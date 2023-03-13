--- base/debug/stack_trace_posix.cc.orig	2023-03-13 07:33:08 UTC
+++ base/debug/stack_trace_posix.cc
@@ -40,7 +40,7 @@
 // execinfo.h and backtrace(3) are really only present in glibc and in macOS
 // libc.
 #if BUILDFLAG(IS_APPLE) || \
-    (defined(__GLIBC__) && !defined(__UCLIBC__) && !defined(__AIX))
+    (defined(__GLIBC__) && !defined(__UCLIBC__) && !defined(__AIX) && !BUILDFLAG(IS_BSD))
 #define HAVE_BACKTRACE
 #include <execinfo.h>
 #endif
@@ -58,7 +58,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -761,6 +761,9 @@ class SandboxSymbolizeHelper {
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if BUILDFLAG(IS_BSD)
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -778,6 +781,7 @@ class SandboxSymbolizeHelper {
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
