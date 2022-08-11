--- Source/WebDriver/PlatformGTK.cmake.orig	2021-09-16 12:43:07 UTC
+++ Source/WebDriver/PlatformGTK.cmake
@@ -1,10 +1,11 @@
-set(WebDriver_OUTPUT_NAME WebKitWebDriver)
+set(WebDriver_OUTPUT_NAME WebKitWebDriver-5)
 
 add_definitions(-DLIBEXECDIR="${CMAKE_INSTALL_FULL_LIBEXECDIR}")
 
 list(APPEND WebDriver_SYSTEM_INCLUDE_DIRECTORIES
     "${GLIB_INCLUDE_DIRS}"
     "${LIBSOUP_INCLUDE_DIRS}"
+    "${ICU_INCLUDE_DIRS}"
 )
 
 list(APPEND WebDriver_SOURCES
@@ -18,4 +19,5 @@ list(APPEND WebDriver_LIBRARIES
 
 list(APPEND WebDriver_LIBRARIES
     ${LIBSOUP_LIBRARIES}
+    ${ICU_LIBRARIES}
 )
