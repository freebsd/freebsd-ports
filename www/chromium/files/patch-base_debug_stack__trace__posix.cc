--- base/debug/stack_trace_posix.cc.orig	2021-07-19 18:45:05 UTC
+++ base/debug/stack_trace_posix.cc
@@ -35,7 +35,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -667,13 +667,21 @@ class SandboxSymbolizeHelper {
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
+#if defined(OS_BSD)
+      LOG(ERROR) << "Failed to read /proc/curproc/map";
+#else
       LOG(ERROR) << "Failed to read /proc/self/maps";
+#endif
       return false;
     }
 
     // Parses /proc/self/maps.
     if (!ParseProcMaps(contents, &regions_)) {
+#if defined(OS_BSD)
+      LOG(ERROR) << "Failed to parse the contents of /proc/curproc/map";
+#else
       LOG(ERROR) << "Failed to parse the contents of /proc/self/maps";
+#endif
       return false;
     }
 
@@ -704,7 +712,11 @@ class SandboxSymbolizeHelper {
           // Skip regions with empty file names.
           continue;
         }
+#if defined(OS_BSD)
+	if (region.path[0] == '-') {
+#else	
         if (region.path[0] == '[') {
+#endif
           // Skip pseudo-paths, like [stack], [vdso], [heap], etc ...
           continue;
         }
