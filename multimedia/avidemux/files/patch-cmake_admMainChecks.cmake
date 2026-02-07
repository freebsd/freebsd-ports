--- cmake/admMainChecks.cmake.orig	2019-08-15 07:25:40 UTC
+++ cmake/admMainChecks.cmake
@@ -117,7 +117,7 @@ ELSE (WIN32)
 ENDIF (WIN32)
 
 if (CMAKE_COMPILER_IS_GNUCC)
-	add_definitions("-Werror=attributes") 
+	add_definitions("-Wattributes") 
 endif (CMAKE_COMPILER_IS_GNUCC)
 # MacOsX stuff
 IF(APPLE)
