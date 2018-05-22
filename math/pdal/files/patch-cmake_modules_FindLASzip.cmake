--- cmake/modules/FindLASzip.cmake.orig	2018-05-22 16:04:04 UTC
+++ cmake/modules/FindLASzip.cmake
@@ -53,7 +53,7 @@ FIND_LIBRARY(LASZIP_LIBRARY
   ${OSGEO4W_ROOT_DIR}/lib)
 
 # Comment out laszip.hpp version info
-SET(LASZIP_VERSION_H "${LASZIP_INCLUDE_DIR}/laszip/laszip_api_version.h")
+SET(LASZIP_VERSION_H "${LASZIP_INCLUDE_DIR}/laszip_api_version.h")
 IF(LASZIP_INCLUDE_DIR AND EXISTS ${LASZIP_VERSION_H})
   SET(LASZIP_VERSION 0)
 
