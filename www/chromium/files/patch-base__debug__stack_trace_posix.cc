--- base/debug/stack_trace_posix.cc.orig	2014-10-10 09:15:29 UTC
+++ base/debug/stack_trace_posix.cc
@@ -588,6 +588,10 @@
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if defined(OS_FREEBSD)
+    // TODO (rene) avoid link error, implement something?
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -603,6 +607,7 @@
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
