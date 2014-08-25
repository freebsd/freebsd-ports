--- ./base/debug/stack_trace_posix.cc.orig	2014-04-30 22:41:43.000000000 +0200
+++ ./base/debug/stack_trace_posix.cc	2014-05-04 15:46:56.000000000 +0200
@@ -586,6 +586,10 @@
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
@@ -601,6 +605,7 @@
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
