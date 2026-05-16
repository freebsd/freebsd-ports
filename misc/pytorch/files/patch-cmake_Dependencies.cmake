--- cmake/Dependencies.cmake.orig	2026-05-13 17:40:38 UTC
+++ cmake/Dependencies.cmake
@@ -1,3 +1,5 @@
+set(CMAKE_CXX_STANDARD 17)
+
 # RPATH stuff
 # see https://cmake.org/Wiki/CMake_RPATH_handling
 if(APPLE)
@@ -1593,7 +1595,8 @@ set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared lib
 set(FMT_INSTALL ON)
 set(TEMP_BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS})
 set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libs" FORCE)
-add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/fmt)
+#add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/fmt)
+find_package(fmt REQUIRED)
 
 # Disable compiler feature checks for `fmt`.
 #
@@ -1602,7 +1605,7 @@ add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/fmt
 # CMAKE_CXX_FLAGS in ways that break feature checks. Since we already know
 # `fmt` is compatible with a superset of the compilers that PyTorch is, it
 # shouldn't be too bad to just disable the checks.
-set_target_properties(fmt-header-only PROPERTIES INTERFACE_COMPILE_FEATURES "")
+#set_target_properties(fmt-header-only PROPERTIES INTERFACE_COMPILE_FEATURES "")
 
 list(APPEND Caffe2_DEPENDENCY_LIBS fmt::fmt-header-only)
 set(BUILD_SHARED_LIBS ${TEMP_BUILD_SHARED_LIBS} CACHE BOOL "Build shared libs" FORCE)
