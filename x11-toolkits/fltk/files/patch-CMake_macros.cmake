--- CMake/macros.cmake.orig	2019-03-03 08:40:23 UTC
+++ CMake/macros.cmake
@@ -90,11 +90,6 @@ function(CREATE_EXAMPLE NAME SOURCES LIBRARIES)
 
     set (tname ${NAME})		# target name
 
-    # rename reserved target name "help" (CMake 2.8.12 and later)
-    if (${tname} MATCHES "^help$")
-        set (tname "test_help")
-    endif (${tname} MATCHES "^help$")
-
     foreach(src ${SOURCES})
         if ("${src}" MATCHES "\\.fl$")
             list(APPEND flsrcs ${src})
