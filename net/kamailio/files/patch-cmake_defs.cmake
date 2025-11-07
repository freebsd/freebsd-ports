--- cmake/defs.cmake.orig	2025-11-07 10:31:49 UTC
+++ cmake/defs.cmake
@@ -25,6 +25,8 @@ elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64")
   set(TARGET_ARCH "i386")
 elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64")
   set(TARGET_ARCH "x86_64")
+elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "armv7")
+  set(TARGET_ARCH "arm7")
 else()
   set(TARGET_ARCH "${CMAKE_SYSTEM_PROCESSOR}")
 endif()
