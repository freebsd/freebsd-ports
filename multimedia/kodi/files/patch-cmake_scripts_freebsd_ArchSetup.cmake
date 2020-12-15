--- cmake/scripts/freebsd/ArchSetup.cmake.orig	2020-12-15 16:30:44 UTC
+++ cmake/scripts/freebsd/ArchSetup.cmake
@@ -19,6 +19,8 @@ else()
   elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
     set(ARCH aarch64-freebsd)
     set(NEON True)
+  elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL powerpc64)
+    set(ARCH powerpc64-freebsd)
   else()
     message(WARNING "unknown CPU: ${CPU}")
   endif()
