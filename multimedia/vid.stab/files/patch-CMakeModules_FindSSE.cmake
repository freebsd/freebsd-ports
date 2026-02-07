--- CMakeModules/FindSSE.cmake.orig	2022-05-30 15:49:01 UTC
+++ CMakeModules/FindSSE.cmake
@@ -1,10 +1,32 @@ include(CheckCCompilerFlag)
 # Check if SSE instructions are available by the compiler and target platform (be aware of cross compilation)
 include(CheckCCompilerFlag)
 
-check_c_compiler_flag(-msse2 HAVE_SSE2)
-check_c_compiler_flag(-msse3 HAVE_SSE3)
-check_c_compiler_flag(-mssse3 HAVE_SSSE3)
-check_c_compiler_flag(-msse4.1 HAVE_SSE4_1)
+if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+      string(REGEX MATCH "sse2" FREEBSD_SSE2 ${CPUINFO})
+      if(FREEBSD_SSE2)
+            check_c_compiler_flag(-msse2 HAVE_SSE2)
+      endif()
+
+      string(REGEX MATCH "(^|[^s])sse3" FREEBSD_SSE3 ${CPUINFO})
+      if(FREEBSD_SSE3)
+            check_c_compiler_flag(-msse3 HAVE_SSE3)
+      endif()
+
+      string(REGEX MATCH "ssse3" FREEBSD_SSSE3 ${CPUINFO})
+      if(FREEBSD_SSSE3)
+            check_c_compiler_flag(-mssse3 HAVE_SSSE3)
+      endif()
+
+      string(REGEX MATCH "sse41" FREEBSD_SSE41 ${CPUINFO})
+      if(FREEBSD_SSE41)
+            check_c_compiler_flag(-msse4.1 HAVE_SSE4_1)
+      endif()
+else()
+      check_c_compiler_flag(-msse2 HAVE_SSE2)
+      check_c_compiler_flag(-msse3 HAVE_SSE3)
+      check_c_compiler_flag(-mssse3 HAVE_SSSE3)
+      check_c_compiler_flag(-msse4.1 HAVE_SSE4_1)
+endif()
 
 # Some compilers understand SSE flags, even when target platform doesn't support it (Clang with arm target)
 # It is necessary try to compile actual code
