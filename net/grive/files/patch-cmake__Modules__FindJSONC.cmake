--- ./cmake/Modules/FindJSONC.cmake.orig	2014-08-20 11:43:11.000000000 -0400
+++ ./cmake/Modules/FindJSONC.cmake	2014-08-20 11:43:25.000000000 -0400
@@ -6,7 +6,7 @@
 #  JSONC_INCLUDE_DIR - The JSON-C include directory.
 #  JSONC_LIBRARY     - The JSON-C library to link against.
 
-FIND_PATH(JSONC_INCLUDE_DIR json/json.h)
+FIND_PATH(JSONC_INCLUDE_DIR json-c/json.h)
 FIND_LIBRARY(JSONC_LIBRARY NAMES json)
 
 IF (JSONC_INCLUDE_DIR AND JSONC_LIBRARY)
