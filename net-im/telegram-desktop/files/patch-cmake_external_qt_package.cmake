--- cmake/external/qt/package.cmake.orig	2024-10-11 07:45:28 UTC
+++ cmake/external/qt/package.cmake
@@ -66,6 +66,8 @@ if (QT_VERSION_MAJOR GREATER_EQUAL 6)
 
 if (QT_VERSION_MAJOR GREATER_EQUAL 6)
     find_package(Qt${QT_VERSION_MAJOR} COMPONENTS OpenGL OpenGLWidgets REQUIRED)
+else()
+    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ServiceSupport REQUIRED)
 endif()
 
 if (LINUX)
