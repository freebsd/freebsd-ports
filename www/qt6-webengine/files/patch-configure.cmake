--- configure.cmake.orig	2025-10-02 00:36:39 UTC
+++ configure.cmake
@@ -292,12 +292,12 @@ qt_webengine_configure_check("supported-platform"
 
 qt_webengine_configure_check("supported-platform"
     MODULES QtWebEngine
-    CONDITION LINUX OR WIN32 OR MACOS
+    CONDITION LINUX OR WIN32 OR MACOS OR FREEBSD
     MESSAGE "Build can be done only on Linux, Windows or macOS."
 )
 qt_webengine_configure_check("supported-platform"
     MODULES QtPdf
-    CONDITION LINUX OR WIN32 OR MACOS OR IOS OR ANDROID
+    CONDITION LINUX OR WIN32 OR MACOS OR IOS OR ANDROID OR FREEBSD
     MESSAGE "Build can be done only on Linux, Windows, macO, iOS and Android."
 )
 
@@ -317,15 +317,6 @@ qt_webengine_configure_check("static-build"
     MESSAGE "Static build is not supported."
 )
 
-qt_webengine_configure_check("nodejs"
-    MODULES QtWebEngine
-    CONDITION TARGET Nodejs::Nodejs AND
-        NOT (Nodejs_ARCH STREQUAL "ia32") AND
-        NOT (Nodejs_ARCH STREQUAL "x86") AND
-        NOT (Nodejs_ARCH STREQUAL "arm")
-    MESSAGE "64-bit Node.js ${QT_CONFIGURE_CHECK_nodejs_version} version or later is required."
-    DOCUMENTATION "64-bit Nodejs ${QT_CONFIGURE_CHECK_nodejs_version} version or later."
-)
 qt_webengine_configure_check("python3"
     MODULES QtWebEngine QtPdf
     CONDITION Python3_FOUND
@@ -456,6 +447,8 @@ qt_webengine_configure_check("compiler"
     CONDITION MSVC OR
         (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
         (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+        (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+        (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
         (MACOS AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
     MESSAGE
         "${CMAKE_CXX_COMPILER_ID} compiler is not supported."
@@ -465,6 +458,8 @@ qt_webengine_configure_check("compiler"
     CONDITION MSVC OR
         (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
         (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+        (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+        (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
         (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang") OR
         (ANDROID AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
         (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
@@ -727,7 +722,7 @@ qt_feature("webengine-ozone-x11" PRIVATE
 
 qt_feature("webengine-ozone-x11" PRIVATE
     LABEL "Support X11 on qpa-xcb"
-    CONDITION LINUX
+    CONDITION LINUX OR FREEBSD
         AND TARGET Qt::Gui
         AND QT_FEATURE_xcb
         AND qpa_xcb_support_check
