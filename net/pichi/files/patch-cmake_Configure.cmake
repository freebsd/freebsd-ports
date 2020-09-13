--- cmake/Configure.cmake.orig	1970-01-01 00:00:00 UTC
+++ cmake/Configure.cmake
@@ -104,6 +104,14 @@ else ()
   set(DEPRECATED_RFC2818_CLASS OFF)
 endif ()
 
+if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND
+  CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "11.0.0")
+  # From clang 11.0.0, using std::allocator<void> triggers -Wdeprecated-declarations
+   set(DEPRECATED_ALLOCATOR_VOID ON)
+else ()
+  set(DEPRECATED_ALLOCATOR_VOID OFF)
+endif ()
+
 # TODO check_cxx_compiler_flag command always gets failed when generating for iOS
 if (IOS)
   set(DISABLE_SHORTEN_64_TO_32_WARNING ON)
@@ -125,6 +133,7 @@ if (BUILD_SERVER)
   check_function_exists("close" HAS_CLOSE)
 endif ()
 
-configure_file(${CMAKE_SOURCE_DIR}/include/pichi/config.hpp.in ${CMAKE_BINARY_DIR}/include/pichi/config.hpp)
+configure_file(${CMAKE_SOURCE_DIR}/include/pichi/config.hpp.in
+  ${CMAKE_BINARY_DIR}/include/pichi/config.hpp)
 
 message(STATUS "Generating config.hpp - done")
