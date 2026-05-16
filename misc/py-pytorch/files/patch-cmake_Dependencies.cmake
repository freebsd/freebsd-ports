--- cmake/Dependencies.cmake.orig	2026-05-13 17:40:38 UTC
+++ cmake/Dependencies.cmake
@@ -354,7 +354,7 @@ if(USE_NNPACK OR USE_PYTORCH_QNNPACK OR USE_XNNPACK)
       set(DISABLE_NNPACK_AND_FAMILY ON)
     endif()
   else()
-    if(NOT IOS AND NOT (CMAKE_SYSTEM_NAME MATCHES "^(Android|Linux|Darwin|Windows)$"))
+    if(NOT IOS AND NOT (CMAKE_SYSTEM_NAME MATCHES "^(Android|Linux|FreeBSD|Darwin|Windows)$"))
       message(WARNING
         "Target platform \"${CMAKE_SYSTEM_NAME}\" is not supported in {Q/X}NNPACK. "
         "Supported platforms are Android, iOS, Linux, and macOS. "
