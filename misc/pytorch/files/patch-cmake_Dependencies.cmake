--- cmake/Dependencies.cmake.orig	2026-07-08 17:44:27 UTC
+++ cmake/Dependencies.cmake
@@ -1636,7 +1636,8 @@ set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared lib
 set(FMT_INSTALL ON)
 set(TEMP_BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS})
 set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libs" FORCE)
-add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/fmt)
+#add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/fmt)
+find_package(fmt REQUIRED)
 
 # Disable compiler feature checks for `fmt`.
 #
@@ -1645,7 +1646,7 @@ add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/fmt
 # CMAKE_CXX_FLAGS in ways that break feature checks. Since we already know
 # `fmt` is compatible with a superset of the compilers that PyTorch is, it
 # shouldn't be too bad to just disable the checks.
-set_target_properties(fmt-header-only PROPERTIES INTERFACE_COMPILE_FEATURES "")
+#set_target_properties(fmt-header-only PROPERTIES INTERFACE_COMPILE_FEATURES "")
 
 # Keep fmt's header-only type layout stable across mixed C++ modes by forcing
 # one no_unique_address spelling for all translation units.
@@ -1654,8 +1655,8 @@ endif()
 else()
   set(_fmt_no_unique_address "[[no_unique_address]]")
 endif()
-target_compile_definitions(fmt PUBLIC "FMT_NO_UNIQUE_ADDRESS=${_fmt_no_unique_address}")
-target_compile_definitions(fmt-header-only INTERFACE "FMT_NO_UNIQUE_ADDRESS=${_fmt_no_unique_address}")
+#target_compile_definitions(fmt PUBLIC "FMT_NO_UNIQUE_ADDRESS=${_fmt_no_unique_address}")
+#target_compile_definitions(fmt-header-only INTERFACE "FMT_NO_UNIQUE_ADDRESS=${_fmt_no_unique_address}")
 unset(_fmt_no_unique_address)
 
 list(APPEND Caffe2_DEPENDENCY_LIBS fmt::fmt-header-only)
