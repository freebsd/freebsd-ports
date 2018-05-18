--- Source/WebDriver/PlatformGTK.cmake.orig	2018-02-19 07:45:32 UTC
+++ Source/WebDriver/PlatformGTK.cmake
@@ -5,6 +5,7 @@ add_definitions(-DLIBEXECDIR="${CMAKE_INSTALL_FULL_LIB
 list(APPEND WebDriver_SYSTEM_INCLUDE_DIRECTORIES
     "${GLIB_INCLUDE_DIRS}"
     "${LIBSOUP_INCLUDE_DIRS}"
+    "${ICU_INCLUDE_DIRS}"
 )
 
 list(APPEND WebDriver_SOURCES
@@ -18,4 +19,5 @@ list(APPEND WebDriver_SOURCES
 
 list(APPEND WebDriver_LIBRARIES
     ${LIBSOUP_LIBRARIES}
+    ${ICU_LIBRARIES}
 )
