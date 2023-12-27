--- cmake/Dependencies.cmake.orig	2023-12-15 02:03:27 UTC
+++ cmake/Dependencies.cmake
@@ -340,7 +340,7 @@ if(USE_NNPACK OR USE_QNNPACK OR USE_PYTORCH_QNNPACK OR
       set(DISABLE_NNPACK_AND_FAMILY ON)
     endif()
   else()
-    if(NOT IOS AND NOT (CMAKE_SYSTEM_NAME MATCHES "^(Android|Linux|Darwin|Windows)$"))
+    if(NOT IOS AND NOT (CMAKE_SYSTEM_NAME MATCHES "^(Android|Linux|FreeBSD|Darwin|Windows)$"))
       message(WARNING
         "Target platform \"${CMAKE_SYSTEM_NAME}\" is not supported in {Q/X}NNPACK. "
         "Supported platforms are Android, iOS, Linux, and macOS. "
