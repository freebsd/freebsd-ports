--- cmake/FindIconv.cmake.orig	2014-06-30 22:48:42.000000000 +0200
+++ cmake/FindIconv.cmake	2014-07-22 12:50:55.000000000 +0200
@@ -18,7 +18,7 @@
 IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
 	FIND_LIBRARY(ICONV_LIBRARIES NAMES iconv libiconv libiconv-2 c HINTS "/opt/local/lib")
 ELSE()
-	FIND_LIBRARY(ICONV_LIBRARIES NAMES iconv libiconv libiconv-2 c)
+	FIND_LIBRARY(ICONV_LIBRARIES NAMES iconv c libiconv libiconv-2)
 ENDIF()
 
 IF(ICONV_INCLUDE_DIR AND ICONV_LIBRARIES)
