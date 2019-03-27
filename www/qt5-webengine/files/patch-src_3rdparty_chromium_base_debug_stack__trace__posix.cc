--- src/3rdparty/chromium/base/debug/stack_trace_posix.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/debug/stack_trace_posix.cc
@@ -35,7 +35,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -86,7 +86,7 @@ void DemangleSymbols(std::string* text) {
   // Note: code in this function is NOT async-signal safe (std::string uses
   // malloc internally).
 
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !defined(OS_BSD)
   std::string::size_type search_from = 0;
   while (search_from < text->size()) {
     // Look for the start of a mangled symbol, from search_from.
@@ -647,6 +647,11 @@ class SandboxSymbolizeHelper {
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
@@ -664,6 +669,7 @@ class SandboxSymbolizeHelper {
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
