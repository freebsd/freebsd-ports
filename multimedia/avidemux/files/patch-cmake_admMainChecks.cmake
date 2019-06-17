--- cmake/admMainChecks.cmake.orig	2019-06-17 10:41:06 UTC
+++ cmake/admMainChecks.cmake
@@ -81,7 +81,7 @@ ELSE (WIN32)
 ENDIF (WIN32)
 
 if (CMAKE_COMPILER_IS_GNUCC)
-	add_definitions("-Werror=attributes") 
+	add_definitions("-Wattributes") 
 endif (CMAKE_COMPILER_IS_GNUCC)
 # Clang
 IF(${CMAKE_CXX_COMPILER} MATCHES ".*[cC]lang.*")
