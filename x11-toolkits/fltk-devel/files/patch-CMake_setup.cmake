--- CMake/setup.cmake.orig	2014-02-14 15:09:21.000000000 +0100
+++ CMake/setup.cmake	2014-02-14 15:10:00.000000000 +0100
@@ -56,6 +56,12 @@
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -framework Cocoa")
 endif(APPLE)
 
+if(${CMAKE_SYSTEM_NAME} STREQUAL FreeBSD)
+    set(HAVE_STRTOL 1)
+    set(HAVE_STRCASECMP 1)
+    set(HAVE_DIRENT_H 1)
+endif()
+
 if(WIN32)
    if(MSVC)
       add_definitions(-DWIN32_LEAN_AND_MEAN)
