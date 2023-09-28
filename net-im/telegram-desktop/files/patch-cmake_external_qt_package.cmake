--- cmake/external/qt/package.cmake.orig	2023-09-13 17:06:28 UTC
+++ cmake/external/qt/package.cmake
@@ -45,6 +45,8 @@ if (QT_VERSION_MAJOR GREATER_EQUAL 6)
         set(qt_version_6_5_or_greater 1)
     endif()
     find_package(Qt${QT_VERSION_MAJOR} COMPONENTS OpenGL OpenGLWidgets REQUIRED)
+else()
+    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ServiceSupport REQUIRED)
 endif()
 
 # QtWaylandScanner cmake integration from Qt 6 is used
