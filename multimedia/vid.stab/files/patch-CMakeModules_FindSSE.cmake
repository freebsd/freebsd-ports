--- CMakeModules/FindSSE.cmake.orig	2026-01-04 14:53:14 UTC
+++ CMakeModules/FindSSE.cmake
@@ -11,10 +11,32 @@ else()
 
 else()
       # GNU/Clang-like flow
-      check_c_compiler_flag(-msse2 HAVE_SSE2)
-      check_c_compiler_flag(-msse3 HAVE_SSE3)
-      check_c_compiler_flag(-mssse3 HAVE_SSSE3)
-      check_c_compiler_flag(-msse4.1 HAVE_SSE4_1)
+      if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+            string(REGEX MATCH "sse2" FREEBSD_SSE2 ${CPUINFO})
+            if(FREEBSD_SSE2)
+                  check_c_compiler_flag(-msse2 HAVE_SSE2)
+            endif()
+
+            string(REGEX MATCH "(^|[^s])sse3" FREEBSD_SSE3 ${CPUINFO})
+            if(FREEBSD_SSE3)
+                  check_c_compiler_flag(-msse3 HAVE_SSE3)
+            endif()
+
+            string(REGEX MATCH "ssse3" FREEBSD_SSSE3 ${CPUINFO})
+            if(FREEBSD_SSSE3)
+                  check_c_compiler_flag(-mssse3 HAVE_SSSE3)
+            endif()
+
+            string(REGEX MATCH "sse41" FREEBSD_SSE41 ${CPUINFO})
+            if(FREEBSD_SSE41)
+                  check_c_compiler_flag(-msse4.1 HAVE_SSE4_1)
+            endif()
+      else()
+            check_c_compiler_flag(-msse2 HAVE_SSE2)
+            check_c_compiler_flag(-msse3 HAVE_SSE3)
+            check_c_compiler_flag(-mssse3 HAVE_SSSE3)
+            check_c_compiler_flag(-msse4.1 HAVE_SSE4_1)
+      endif()
 
       if(HAVE_SSE2)
             try_compile(SSE_OK "${PROJECT_BINARY_DIR}"
