--- configure.cmake.orig	2022-09-26 10:05:50 UTC
+++ configure.cmake
@@ -59,7 +59,7 @@ endif()
 endif()
 
 #### Tests
-if(LINUX)
+if(LINUX OR FREEBSD)
    check_for_ulimit()
 endif()
 
@@ -403,7 +403,7 @@ qt_feature("webengine-ozone-x11" PRIVATE
 
 qt_feature("webengine-ozone-x11" PRIVATE
     LABEL "Support GLX on qpa-xcb"
-    CONDITION LINUX
+    CONDITION LINUX OR FREEBSD
         AND TARGET Qt::Gui
         AND QT_FEATURE_xcb
         AND X11_FOUND
@@ -440,12 +440,12 @@ add_check_for_support(
 )
 add_check_for_support(
    MODULES QtWebEngine
-   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS
+   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR FREEBSD
    MESSAGE "Build can be done only on Linux, Windows or macOS."
 )
 add_check_for_support(
    MODULES QtPdf
-   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR IOS
+   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR IOS OR FREEBSD
    MESSAGE "Build can be done only on Linux, Windows, macOS or iOS."
 )
 if(LINUX AND CMAKE_CROSSCOMPILING)
@@ -546,6 +546,8 @@ add_check_for_support(
    CONDITION
        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL GNU) OR
        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL Clang) OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL GNU) OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL Clang) OR
        (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL MSVC) OR
        (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL Clang AND
           CMAKE_CXX_SIMULATE_ID STREQUAL MSVC) OR
