--- configure.cmake.orig	2024-11-21 04:36:37 UTC
+++ configure.cmake
@@ -73,7 +73,7 @@ endif()
 endif()
 
 #### Tests
-if(LINUX)
+if(LINUX OR FREEBSD)
    check_for_ulimit()
 endif()
 
@@ -434,7 +434,7 @@ qt_feature("webengine-ozone-x11" PRIVATE
 
 qt_feature("webengine-ozone-x11" PRIVATE
     LABEL "Support X11 on qpa-xcb"
-    CONDITION LINUX
+    CONDITION LINUX OR FREEBSD
         AND TARGET Qt::Gui
         AND QT_FEATURE_xcb
         AND X11_FOUND
@@ -474,12 +474,12 @@ add_check_for_support(
 )
 add_check_for_support(
    MODULES QtWebEngine
-   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS
+   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR FREEBSD
    MESSAGE "Build can be done only on Linux, Windows or macOS."
 )
 add_check_for_support(
    MODULES QtPdf
-   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR IOS OR ANDROID
+   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR IOS OR ANDROID OR FREEBSD
    MESSAGE "Build can be done only on Linux, Windows, macO, iOS and Android."
 )
 if(LINUX AND CMAKE_CROSSCOMPILING)
@@ -502,13 +502,6 @@ add_check_for_support(
    MESSAGE "node.js version 14 or later is required."
 )
 add_check_for_support(
-    MODULES QtWebEngine
-    CONDITION NOT (Nodejs_ARCH STREQUAL "ia32") AND
-              NOT (Nodejs_ARCH STREQUAL "x86") AND
-              NOT (Nodejs_ARCH STREQUAL "arm")
-    MESSAGE "32bit version of Nodejs is not supported."
-)
-add_check_for_support(
    MODULES QtWebEngine QtPdf
    CONDITION Python3_EXECUTABLE
    MESSAGE "Python version 3.8 or later is required."
@@ -572,8 +565,8 @@ add_check_for_support(
 add_check_for_support(
    MODULES QtWebEngine
    CONDITION MSVC OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
        (MACOS AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    MESSAGE
        "${CMAKE_CXX_COMPILER_ID} compiler is not supported."
@@ -582,8 +575,8 @@ add_check_for_support(
 add_check_for_support(
    MODULES QtPdf
    CONDITION MSVC OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
        (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang") OR
        (ANDROID AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
        (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
