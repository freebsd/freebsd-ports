--- cmake/FindIconv.cmake.orig	2014-09-03 02:19:35 UTC
+++ cmake/FindIconv.cmake
@@ -40,7 +40,7 @@
 	DOC   "Path to the ${ICONV_H} file"
 )
 
-find_library(Iconv_LIBRARY NAMES iconv
+find_library(Iconv_LIBRARY NAMES iconv c
 	PATHS  /usr/local/lib
 	       /usr/lib
 	       NO_DEFAULT_PATH
