--- Source/JavaScriptCore/PlatformGTK.cmake.orig	2014-12-25 20:19:12.049673483 +0100
+++ Source/JavaScriptCore/PlatformGTK.cmake	2014-12-25 20:20:42.328667491 +0100
@@ -10,7 +10,7 @@
 ADD_TYPELIB(${CMAKE_BINARY_DIR}/JavaScriptCore-${WEBKITGTK_API_VERSION}.typelib)
 
 install(FILES "${CMAKE_BINARY_DIR}/Source/JavaScriptCore/javascriptcoregtk-${WEBKITGTK_API_VERSION}.pc"
-        DESTINATION "${LIB_INSTALL_DIR}/pkgconfig"
+        DESTINATION "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig"
 )
 
 install(FILES API/JavaScript.h
