--- cmake/FindFmt.cmake.orig	2024-04-30 16:44:38 UTC
+++ cmake/FindFmt.cmake
@@ -2,7 +2,7 @@ target_include_directories(fmt::fmt-header-only
 
 target_include_directories(fmt::fmt-header-only
     INTERFACE
-        ${CMAKE_CURRENT_LIST_DIR}/../third-party/fmt/include)
+    	${CMAKE_INSTALL_PREFIX}/include)
 
 target_compile_definitions(fmt::fmt-header-only
     INTERFACE
