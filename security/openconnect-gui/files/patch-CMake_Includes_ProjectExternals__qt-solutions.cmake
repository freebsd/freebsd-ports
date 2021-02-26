--- CMake/Includes/ProjectExternals_qt-solutions.cmake.orig	2018-03-25 21:49:15 UTC
+++ CMake/Includes/ProjectExternals_qt-solutions.cmake
@@ -9,10 +9,7 @@ ExternalProject_Add(qt-solutions-${qt-solutions-TAG}
     UPDATE_DISCONNECTED 0
     UPDATE_COMMAND ""
     
-    GIT_REPOSITORY https://code.qt.io/qt-solutions/qt-solutions.git
-    GIT_TAG ${qt-solutions-TAG}
-    GIT_SHALLOW 1
-    
+    SOURCE_DIR ${CMAKE_BINARY_DIR}/external/src/qt-solutions-master
     BUILD_IN_SOURCE 1
         
     PATCH_COMMAND ${CMAKE_COMMAND} -E copy_if_different
@@ -21,14 +18,14 @@ ExternalProject_Add(qt-solutions-${qt-solutions-TAG}
         CMAKE_COMMAND ${CMAKE_CROSS_COMMAND} -DCMAKE_OSX_DEPLOYMENT_TARGET=${CMAKE_OSX_DEPLOYMENT_TARGET}
 
     # Note: ninja-1.8.2 & cmake-3.10.2 failed in find/install this dependency wo next 2 lines :(
-    BUILD_BYPRODUCTS ${CMAKE_BINARY_DIR}/external/lib/libqtsingleapplication.a
-    INSTALL_COMMAND ${CMAKE_COMMAND} --build . --target install
+    BUILD_BYPRODUCTS ${CMAKE_BINARY_DIR}/external/src/qt-solutions-master/libqtsingleapplication.a
+    INSTALL_COMMAND ${CMAKE_COMMAND} --build .
 )
 
 add_library(qt-solutions::qtsingleapplication STATIC IMPORTED)
 set_target_properties(qt-solutions::qtsingleapplication PROPERTIES
-    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/external/include"
-    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/external/lib/libqtsingleapplication.a
+    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/external/src/qt-solutions-master/qtsingleapplication/src"
+    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/external/src/qt-solutions-master/libqtsingleapplication.a
 )
 set_property(TARGET qt-solutions::qtsingleapplication PROPERTY
     DEPENDS qt-solutions-${qt-solutions-TAG}
