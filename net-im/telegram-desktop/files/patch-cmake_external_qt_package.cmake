--- cmake/external/qt/package.cmake.orig	2025-05-01 07:59:09 UTC
+++ cmake/external/qt/package.cmake
@@ -69,6 +69,8 @@ if (QT_VERSION_MAJOR GREATER_EQUAL 6)
 
 if (QT_VERSION_MAJOR GREATER_EQUAL 6)
     find_package(Qt${QT_VERSION_MAJOR} COMPONENTS OpenGL OpenGLWidgets REQUIRED)
+else()
+    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ServiceSupport REQUIRED)
 endif()
 
 if (LINUX)
