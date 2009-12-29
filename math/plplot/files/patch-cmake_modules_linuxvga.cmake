--- ./cmake/modules/linuxvga.cmake.orig	2009-09-06 21:04:43.000000000 +0200
+++ ./cmake/modules/linuxvga.cmake	2009-12-26 23:58:37.000000000 +0100
@@ -35,7 +35,6 @@
 # set the environment variable CMAKE_LIBRARY_PATH.
 # See cmake documentation for further details.
 
-if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
   if(PLD_linuxvga)
     find_package(VGA)
     if(VGA_FOUND)
@@ -50,6 +49,3 @@
       set(PLD_linuxvga OFF CACHE BOOL "Enable linuxvga device" FORCE)    
     endif(VGA_FOUND)
   endif(PLD_linuxvga)
-else(CMAKE_SYSTEM_NAME STREQUAL "Linux")
-  set(PLD_linuxvga OFF CACHE BOOL "Enable linuxvga device" FORCE)    
-endif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
