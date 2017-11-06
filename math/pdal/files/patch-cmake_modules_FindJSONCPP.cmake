--- cmake/modules/FindJSONCPP.cmake.orig	2017-08-11 17:29:28 UTC
+++ cmake/modules/FindJSONCPP.cmake
@@ -77,6 +77,7 @@ find_library(JSONCPP_LIBRARY
 	PATHS
 	"${JSONCPP_ROOT_DIR}/libs"
 	/usr/lib/${CMAKE_LIBRARY_ARCHITECTURE}
+        /usr/local/lib/${CMAKE_LIBRARY_ARCHITECTURE}
 	PATH_SUFFIXES
 	${_pathsuffixes})
 
@@ -86,6 +87,7 @@ find_path(JSONCPP_INCLUDE_DIR
 	PATHS
 	"${JSONCPP_ROOT_DIR}"
 	/usr/include/jsoncpp
+        /usr/local/include/jsoncpp
 	PATH_SUFFIXES
 	include)
 
