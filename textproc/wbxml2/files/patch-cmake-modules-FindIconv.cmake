--- cmake/modules/FindIconv.cmake.orig	2011-01-08 16:22:19 UTC
+++ cmake/modules/FindIconv.cmake
@@ -6,6 +6,8 @@
 #
 #  Copyright (c) 2010 Michael Bell <michael.bell@web.de>
 
+include(CheckFunctionExists)
+
 if (ICONV_INCLUDE_DIR AND ICONV_LIBRARIES)
   # Already in cache, be silent
   set(ICONV_FIND_QUIETLY TRUE)
@@ -13,11 +15,15 @@ endif (ICONV_INCLUDE_DIR AND ICONV_LIBRA
 
 find_path(ICONV_INCLUDE_DIR iconv.h)
 
-find_library(ICONV_LIBRARIES NAMES iconv libiconv libiconv-2 c)
-
-if (ICONV_INCLUDE_DIR AND ICONV_LIBRARIES)
-   set (ICONV_FOUND TRUE)
-endif (ICONV_INCLUDE_DIR AND ICONV_LIBRARIES)
+if (ICONV_INCLUDE_DIR)
+  check_function_exists(iconv ICONV_FOUND)
+  if (NOT ICONV_FOUND)
+    find_library(ICONV_LIBRARIES NAMES iconv libiconv libiconv-2)
+    if (ICONV_LIBRARIES)
+      set (ICONV_FOUND TRUE)
+    endif (ICONV_LIBRARIES)
+  endif (NOT ICONV_FOUND)
+endif (ICONV_INCLUDE_DIR)
 
 set(CMAKE_REQUIRED_INCLUDES ${ICONV_INCLUDE_DIR})
 set(CMAKE_REQUIRED_LIBRARIES ${ICONV_LIBRARIES})
