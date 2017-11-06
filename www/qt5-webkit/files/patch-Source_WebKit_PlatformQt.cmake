--- Source/WebKit/PlatformQt.cmake.orig	2017-06-15 23:36:48 UTC
+++ Source/WebKit/PlatformQt.cmake
@@ -481,6 +481,7 @@ if (NOT MACOS_BUILD_FRAMEWORKS)
         BASE_NAME Qt5WebKit
         DEPS "${WEBKIT_PKGCONGIG_DEPS}"
         FILENAME_VAR WebKit_PKGCONFIG_FILENAME
+        DESCRIPTION "Qt WebKit module"
     )
     set(ECM_PKGCONFIG_INSTALL_DIR "${LIB_INSTALL_DIR}/pkgconfig" CACHE PATH "The directory where pkgconfig will be installed to.")
     install(FILES ${WebKit_PKGCONFIG_FILENAME} DESTINATION ${ECM_PKGCONFIG_INSTALL_DIR} COMPONENT Data)
@@ -671,6 +672,7 @@ if (NOT MACOS_BUILD_FRAMEWORKS)
         BASE_NAME Qt5WebKitWidgets
         DEPS "${WEBKITWIDGETS_PKGCONFIG_DEPS}"
         FILENAME_VAR WebKitWidgets_PKGCONFIG_FILENAME
+        DESCRIPTION "Qt WebKitWidgets module"
     )
     install(FILES ${WebKitWidgets_PKGCONFIG_FILENAME} DESTINATION ${ECM_PKGCONFIG_INSTALL_DIR} COMPONENT Data)
 endif ()
