commit 14947c04b3c19b5eb04a683081742b14c1d32786
Author: Konstantin Tokarev <annulen@yandex.ru>
Date:   Sat Oct 7 17:38:32 2017 +0300

    [cmake] Fix build with CMake 3.10: -frtti was enabled for wrong file path
    
    Change-Id: I65d4f491f21c17f6d99a14259988d2ddb0d67105

--- Source/WebKit/PlatformQt.cmake.orig	2018-10-07 11:03:32 UTC
+++ Source/WebKit/PlatformQt.cmake
@@ -481,6 +481,8 @@ if (NOT MACOS_BUILD_FRAMEWORKS)
         BASE_NAME Qt5WebKit
         DEPS "${WEBKIT_PKGCONGIG_DEPS}"
         FILENAME_VAR WebKit_PKGCONFIG_FILENAME
+        INCLUDE_INSTALL_DIR "${KDE_INSTALL_INCLUDEDIR}/QtWebKit"
+        DESCRIPTION "Qt WebKit module"
     )
     set(ECM_PKGCONFIG_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig" CACHE PATH "The directory where pkgconfig will be installed to.")
     install(FILES ${WebKit_PKGCONFIG_FILENAME} DESTINATION ${ECM_PKGCONFIG_INSTALL_DIR} COMPONENT Data)
@@ -671,6 +673,8 @@ if (NOT MACOS_BUILD_FRAMEWORKS)
         BASE_NAME Qt5WebKitWidgets
         DEPS "${WEBKITWIDGETS_PKGCONFIG_DEPS}"
         FILENAME_VAR WebKitWidgets_PKGCONFIG_FILENAME
+        INCLUDE_INSTALL_DIR "${KDE_INSTALL_INCLUDEDIR}/QtWebKitWidgets"
+        DESCRIPTION "Qt WebKitWidgets module"
     )
     install(FILES ${WebKitWidgets_PKGCONFIG_FILENAME} DESTINATION ${ECM_PKGCONFIG_INSTALL_DIR} COMPONENT Data)
 endif ()
@@ -786,6 +790,7 @@ if (COMPILER_IS_GCC_OR_CLANG)
     set_source_files_properties(
         qt/Api/qwebdatabase.cpp
         qt/Api/qwebelement.cpp
+        qt/Api/qwebfullscreenrequest.cpp
         qt/Api/qwebhistory.cpp
         qt/Api/qwebhistoryinterface.cpp
         qt/Api/qwebpluginfactory.cpp
@@ -795,7 +800,6 @@ if (COMPILER_IS_GCC_OR_CLANG)
 
         qt/WidgetApi/qgraphicswebview.cpp
         qt/WidgetApi/qwebframe.cpp
-        qt/WidgetApi/qwebfullscreenrequest.cpp
         qt/WidgetApi/qwebinspector.cpp
         qt/WidgetApi/qwebpage.cpp
         qt/WidgetApi/qwebview.cpp
