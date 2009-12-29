--- cmake/modules/FindVGA.cmake.orig	2009-09-06 21:04:43.000000000 +0200
+++ cmake/modules/FindVGA.cmake	2009-12-25 20:27:51.000000000 +0100
@@ -6,7 +6,6 @@
 #  VGA_LIBRARIES, the libraries to link against to use the vga library
 #  VGA_LIBRARY_DIRS, the directory where the vga library is found.
 
-if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
 find_path(VGA_INCLUDE_DIR vga.h /usr/local/include /usr/include)
 
 if(VGA_INCLUDE_DIR)
@@ -33,4 +32,3 @@
     message(FATAL_ERROR "FindVGA: Could not find vga.h and/or the vga library")
   endif(VGA_FIND_REQUIRED)
 endif(VGA_FOUND)
-endif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
