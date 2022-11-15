--- cmake/custom/main.cmake.orig	2022-10-26 08:49:22 UTC
+++ cmake/custom/main.cmake
@@ -62,5 +62,7 @@ include(${PROJECT_SOURCE_DIR}/external/upstream/fetch_
 set(CMAKE_BUILD_TYPE ${_build_type})
 
 add_subdirectory(src)
-add_subdirectory(python)
+if (BUILD_PYTHON)
+  add_subdirectory(python)
+endif()
 add_subdirectory(pilot)
