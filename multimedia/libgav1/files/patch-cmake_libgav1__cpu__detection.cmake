- Don't enable NEON on armv6 as it requires runtime detection

--- cmake/libgav1_cpu_detection.cmake.orig	2020-07-15 02:27:54 UTC
+++ cmake/libgav1_cpu_detection.cmake
@@ -21,7 +21,7 @@ set(LIBGAV1_CMAKE_LIBGAV1_CPU_DETECTION_CMAKE_ 1)
 macro(libgav1_optimization_detect)
   if(LIBGAV1_ENABLE_OPTIMIZATIONS)
     string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" cpu_lowercase)
-    if(cpu_lowercase MATCHES "^arm|^aarch64")
+    if(cpu_lowercase MATCHES "^arm|^aarch64" AND NOT cpu_lowercase MATCHES "^armv6")
       set(libgav1_have_neon ON)
     elseif(cpu_lowercase MATCHES "^x86|amd64")
       set(libgav1_have_sse4 ON)
