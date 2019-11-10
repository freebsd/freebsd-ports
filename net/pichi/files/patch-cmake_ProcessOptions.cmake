--- cmake/ProcessOptions.cmake.orig	2019-04-14 16:29:43 UTC
+++ cmake/ProcessOptions.cmake
@@ -83,5 +83,3 @@ if (BUILD_SERVER)
   check_function_exists("setsid" HAS_SETSID)
   check_function_exists("close" HAS_CLOSE)
 endif (BUILD_SERVER)
-
-configure_file(${CMAKE_SOURCE_DIR}/include/config.h.in ${CMAKE_BINARY_DIR}/include/config.h)
