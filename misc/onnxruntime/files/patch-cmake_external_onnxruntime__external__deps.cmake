--- cmake/external/onnxruntime_external_deps.cmake.orig	2024-06-24 02:23:28 UTC
+++ cmake/external/onnxruntime_external_deps.cmake
@@ -85,7 +85,7 @@ if (NOT WIN32)
     google_nsync
     URL ${DEP_URL_google_nsync}
     URL_HASH SHA1=${DEP_SHA1_google_nsync}
-    FIND_PACKAGE_ARGS NAMES nsync
+    FIND_PACKAGE_ARGS NAMES nsync_cpp
     )
 endif()
 list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/external)
