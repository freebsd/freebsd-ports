--- cmake/scripts/freebsd/ArchSetup.cmake.orig	2021-01-15 12:42:30 UTC
+++ cmake/scripts/freebsd/ArchSetup.cmake
@@ -20,6 +20,10 @@ else()
   elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
     set(ARCH aarch64-freebsd)
     set(NEON True)
+  elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL powerpc64)
+    set(ARCH powerpc64-freebsd)
+  elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL powerpc64le)
+    set(ARCH powerpc64le-freebsd)
   else()
     message(WARNING "unknown CPU: ${CPU}")
   endif()
