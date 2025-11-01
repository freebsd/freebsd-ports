--- cmake/FindFmt.cmake.orig	2025-10-15 08:40:38 UTC
+++ cmake/FindFmt.cmake
@@ -1,10 +1,21 @@ add_library(fmt::fmt-header-only INTERFACE IMPORTED)
 add_library(fmt::fmt-header-only INTERFACE IMPORTED)
 
+set(${CMAKE_FIND_PACKAGE_NAME}_INCLUDE "${CMAKE_INSTALL_PREFIX}/include")
+
 target_include_directories(fmt::fmt-header-only
     INTERFACE
-        ${CMAKE_CURRENT_LIST_DIR}/../third-party/fmt/include)
+     ${${CMAKE_FIND_PACKAGE_NAME}_INCLUDE})
 
+file(READ "${${CMAKE_FIND_PACKAGE_NAME}_INCLUDE}/fmt/base.h" _FMT_BASE_H)
+if(_FMT_BASE_H MATCHES "FMT_VERSION ([0-9]+)([0-9][0-9])([0-9][0-9])")
+    # Use math to skip leading zeros if any.
+    math(EXPR _FMT_VERSION_MAJOR ${CMAKE_MATCH_1})
+    math(EXPR _FMT_VERSION_MINOR ${CMAKE_MATCH_2})
+    math(EXPR _FMT_VERSION_PATCH ${CMAKE_MATCH_3})
+    set(${CMAKE_FIND_PACKAGE_NAME}_VERSION "${_FMT_VERSION_MAJOR}.${_FMT_VERSION_MINOR}.${_FMT_VERSION_PATCH}")
+endif()
+
 target_compile_definitions(fmt::fmt-header-only
     INTERFACE
-        FMT_EXCEPTIONS=0
+    	$<IF:$<VERSION_GREATER_EQUAL:${${CMAKE_FIND_PACKAGE_NAME}_VERSION},11.2.0>,FMT_USE_EXCEPTIONS,FMT_EXCEPTIONS>=0
         FMT_HEADER_ONLY=1)
