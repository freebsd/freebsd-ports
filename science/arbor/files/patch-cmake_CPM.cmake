--- cmake/CPM.cmake.orig	2025-04-24 10:33:03 UTC
+++ cmake/CPM.cmake
@@ -9,6 +9,9 @@ elseif(DEFINED ENV{CPM_SOURCE_CACHE})
   set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
 elseif(DEFINED ENV{CPM_SOURCE_CACHE})
   set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
+elseif(DEFINED ENV{CPM_REPO})
+  include("$ENV{CPM_REPO}/cmake/CPM.cmake")
+  return()
 else()
   set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
 endif()
