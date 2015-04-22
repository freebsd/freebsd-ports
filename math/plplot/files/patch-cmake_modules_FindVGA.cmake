--- cmake/modules/FindVGA.cmake.orig	2015-04-12 10:08:04 UTC
+++ cmake/modules/FindVGA.cmake
@@ -6,7 +6,6 @@
 #  VGA_LIBRARIES, the libraries to link against to use the vga library
 #  VGA_LIBRARY_DIRS, the directory where the vga library is found.
 
-if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
 find_path(VGA_INCLUDE_DIR vga.h /usr/local/include /usr/include)
 
 if(VGA_INCLUDE_DIR)
@@ -33,4 +32,3 @@ else(VGA_FOUND)
     message(FATAL_ERROR "FindVGA: Could not find vga.h and/or the vga library")
   endif(VGA_FIND_REQUIRED)
 endif(VGA_FOUND)
-endif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
