--- libfixmath/libfixmath.cmake.orig	2022-09-15 10:24:31 UTC
+++ libfixmath/libfixmath.cmake
@@ -1,6 +1,6 @@
 file(GLOB libfixmath-srcs libfixmath/*.c)
 
-add_library(libfixmath STATIC ${libfixmath-srcs})
+add_library(fixmath ${libfixmath-srcs})
 
-target_include_directories(libfixmath INTERFACE
-  ${CMAKE_CURRENT_SOURCE_DIR})
\ No newline at end of file
+target_include_directories(fixmath INTERFACE
+  ${CMAKE_CURRENT_SOURCE_DIR})
