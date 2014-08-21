--- ./plex/CMakeModules/CMakeConfig.cmake.orig	2014-06-02 09:15:38.258729436 +0800
+++ ./plex/CMakeModules/CMakeConfig.cmake	2014-06-02 09:38:39.849710021 +0800
@@ -31,7 +31,7 @@
   elseif(WIN32)
     set(TARGET_PLATFORM "WIN32")
   elseif(UNIX)
-    set(TARGET_PLATFORM "LINUX")
+    set(TARGET_PLATFORM ${CMAKE_SYSTEM_NAME})
   endif()
 endif()
 
@@ -47,6 +47,9 @@
   set(TARGET_COMMON_LINUX 1 CACHE BOOL "Common Linux platforms")
   set(TARGET_LINUX 1 CACHE BOOL "Target is Linux")
   set(TARGET_POSIX 1 CACHE BOOL "POSIX platform")
+elseif(${TARGET_PLATFORM} STREQUAL "FREEBSD")
+  set(TARGET_FREEBSD 1 CACHE BOOL "Target is FreeBSD")
+  set(TARGET_POSIX 1 CACHE BOOL "POSIX platform")
 elseif(${TARGET_PLATFORM} STREQUAL "RPI")
   set(TARGET_RPI 1 CACHE BOOL "Target in RaspberryPI")
   set(TARGET_COMMON_LINUX 1 CACHE BOOL "Common Linux platforms")
@@ -76,6 +79,8 @@
   set(BUILD_TAG "macosx-${OSX_ARCH}")
 elseif(TARGET_WIN32)
   set(BUILD_TAG "windows-x86")
+elseif(TARGET_FREEBSD)
+  set(BUILD_TAG "freebsd-${ARCH}")
 elseif(TARGET_LINUX)
   if(DEFINED ENV{ARCH} AND DEFINED ENV{PROJECT})
     set(BUILD_TAG "$ENV{PROJECT}-$ENV{ARCH}")
