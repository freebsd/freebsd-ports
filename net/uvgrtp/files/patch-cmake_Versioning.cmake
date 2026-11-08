--- cmake/Versioning.cmake.orig	2026-07-28 17:57:17 UTC
+++ cmake/Versioning.cmake
@@ -33,7 +33,8 @@ configure_file(cmake/version.cc.in version.cc
         )
 add_library(${PROJECT_NAME}_version OBJECT
         ${CMAKE_CURRENT_BINARY_DIR}/version.cc)
-        
+set_target_properties(${PROJECT_NAME}_version PROPERTIES
+        POSITION_INDEPENDENT_CODE ${UVGRTP_BUILD_SHARED})
 target_include_directories(${PROJECT_NAME}_version
     PRIVATE
         ${CMAKE_CURRENT_SOURCE_DIR}/include
