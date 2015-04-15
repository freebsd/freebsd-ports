--- cmake/FindIconv.cmake.orig	2010-08-17 10:55:45 UTC
+++ cmake/FindIconv.cmake
@@ -30,45 +30,29 @@
 # also defined, but not for general use are
 # Iconv_LIBRARY, where to find the Iconv library.
 
+include(CheckFunctionExists)
+
 set(ICONV_H iconv.h)
 
 
 find_path(ICONV_INCLUDE_DIR ${ICONV_H}
-	PATHS  /usr/local/include
-	       /usr/include
-	       NO_DEFAULT_PATH
 	DOC   "Path to the ${ICONV_H} file"
 )
 
-find_library(Iconv_LIBRARY NAMES iconv
-	PATHS  /usr/local/lib
-	       /usr/lib
-	       NO_DEFAULT_PATH
-	DOC   "Library for character set conversion"
-)
-
-if(ICONV_INCLUDE_DIR AND Iconv_LIBRARY)
-	set(Iconv_FOUND TRUE)
-else(ICONV_INCLUDE_DIR AND Iconv_LIBRARY)
-	set(Iconv_FOUND FALSE)
-endif(ICONV_INCLUDE_DIR AND Iconv_LIBRARY)
+if(ICONV_INCLUDE_DIR)
+  check_function_exists(iconv Iconv_FOUND)
+  if(NOT Iconv_FOUND)
+    find_library(Iconv_LIBRARY NAMES iconv libiconv libiconv-2)
+    if(Iconv_LIBRARY)
+      set(Iconv_FOUND TRUE)
+    endif(Iconv_LIBRARY)
+  endif(NOT Iconv_FOUND)
+endif(ICONV_INCLUDE_DIR)
 
 if(Iconv_FOUND)
 	if(NOT Iconv_FIND_QUIETLY)
-		message(STATUS "Found Iconv: ${Iconv_LIBARY}")
+		message(STATUS "Found Iconv: ${Iconv_LIBRARY}")
 	endif(NOT Iconv_FIND_QUIETLY)
-else(Iconv_FOUND)
-	if("${CMAKE_SYSTEM_NAME}" MATCHES "FreeBSD")
-		if(NOT Iconv_FIND_QUIETLY)
-			if(Iconv_FIND_REQUIRED)
-				message(FATAL_ERROR "Could not find the Iconv Library")
-			else(Iconv_FIND_REQUIRED)
-				message(STATUS "Could not find the Iconv Library")
-			endif(Iconv_FIND_REQUIRED)
-		endif(NOT Iconv_FIND_QUIETLY)
-	else("${CMAKE_SYSTEM_NAME}" MATCHES "FreeBSD")
-		set(Iconv_LIBRARY "")
-	endif("${CMAKE_SYSTEM_NAME}" MATCHES "FreeBSD")
 endif(Iconv_FOUND)
 
 mark_as_advanced(ICONV_INCLUDE_DIR Iconv_LIBRARY)
