--- cmake/external/onnxruntime_external_deps.cmake.orig	2025-02-10 16:55:12 UTC
+++ cmake/external/onnxruntime_external_deps.cmake
@@ -92,7 +92,7 @@ if (NOT WIN32)
     URL ${DEP_URL_google_nsync}
     URL_HASH SHA1=${DEP_SHA1_google_nsync}
     PATCH_COMMAND ${Patch_EXECUTABLE} --binary --ignore-whitespace -p1 < ${PROJECT_SOURCE_DIR}/patches/nsync/nsync_1.26.0.patch
-    FIND_PACKAGE_ARGS NAMES nsync unofficial-nsync
+    FIND_PACKAGE_ARGS NAMES nsync_cpp unofficial-nsync
   )
   #nsync tests failed on Mac Build
   set(NSYNC_ENABLE_TESTS OFF CACHE BOOL "" FORCE)
