--- cmake/Dependencies.cmake.orig	2026-09-02 17:43:46 UTC
+++ cmake/Dependencies.cmake
@@ -373,14 +373,14 @@ if(USE_NNPACK OR USE_PYTORCH_QNNPACK OR USE_XNNPACK)
       set(DISABLE_NNPACK_AND_FAMILY ON)
     endif()
   else()
-    if(NOT IOS AND NOT (CMAKE_SYSTEM_NAME MATCHES "^(Android|Linux|Darwin|Windows)$"))
+    if(NOT IOS AND NOT (CMAKE_SYSTEM_NAME MATCHES "^(Android|Linux|FreeBSD|Darwin|Windows)$"))
       message(WARNING
         "Target platform \"${CMAKE_SYSTEM_NAME}\" is not supported in {Q/X}NNPACK. "
         "Supported platforms are Android, iOS, Linux, and macOS. "
         "Turn this warning off by USE_{Q/X}NNPACK=OFF.")
       set(DISABLE_NNPACK_AND_FAMILY ON)
     endif()
-    if(NOT IOS AND NOT (CMAKE_SYSTEM_PROCESSOR MATCHES "^(i686|AMD64|x86_64|armv[0-9].*|arm64|aarch64)$"))
+    if(NOT IOS AND NOT (CMAKE_SYSTEM_PROCESSOR MATCHES "^(i686|AMD64|amd64|x86_64|armv[0-9].*|arm64|aarch64)$"))
       message(WARNING
         "Target architecture \"${CMAKE_SYSTEM_PROCESSOR}\" is not supported in {Q/X}NNPACK. "
         "Supported architectures are x86, x86-64, ARM, and ARM64. "
