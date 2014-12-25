--- Source/WebKit2/PlatformGTK.cmake.orig	2014-12-25 20:23:07.749658406 +0100
+++ Source/WebKit2/PlatformGTK.cmake	2014-12-25 20:23:43.409739634 +0100
@@ -837,7 +837,7 @@
 )
 install(FILES "${CMAKE_BINARY_DIR}/Source/WebKit2/webkit2gtk-${WEBKITGTK_API_VERSION}.pc"
               "${CMAKE_BINARY_DIR}/Source/WebKit2/webkit2gtk-web-extension-${WEBKITGTK_API_VERSION}.pc"
-        DESTINATION "${LIB_INSTALL_DIR}/pkgconfig"
+        DESTINATION "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig"
 )
 install(FILES ${WebKit2GTK_INSTALLED_HEADERS}
               ${WebKit2WebExtension_INSTALLED_HEADERS}
