--- cmake/external/qt/package.cmake.orig	2024-05-16 08:52:10 UTC
+++ cmake/external/qt/package.cmake
@@ -41,6 +41,8 @@ find_package(Qt${QT_VERSION_MAJOR} OPTIONAL_COMPONENTS
 
 if (QT_VERSION_MAJOR GREATER_EQUAL 6)
     find_package(Qt${QT_VERSION_MAJOR} COMPONENTS OpenGL OpenGLWidgets REQUIRED)
+else()
+    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ServiceSupport REQUIRED)
 endif()
 
 if (LINUX)
