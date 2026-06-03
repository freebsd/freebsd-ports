--- cmake/Versioning.cmake.orig	2025-03-20 09:59:25 UTC
+++ cmake/Versioning.cmake
@@ -31,6 +31,8 @@ configure_file(cmake/version.cc.in version.cc
         )
 add_library(${PROJECT_NAME}_version OBJECT
         ${CMAKE_CURRENT_BINARY_DIR}/version.cc)
+set_target_properties(${PROJECT_NAME}_version PROPERTIES
+    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS})
 target_include_directories(${PROJECT_NAME}_version
         PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
         )
