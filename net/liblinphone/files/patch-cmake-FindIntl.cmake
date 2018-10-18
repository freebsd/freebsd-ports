--- cmake/FindIntl.cmake.orig	2017-04-06 09:25:59 UTC
+++ cmake/FindIntl.cmake
@@ -41,7 +41,7 @@ if(INTL_INCLUDE_DIRS)
 endif()
 
 set(INTL_ARGS INTL_INCLUDE_DIRS HAVE_LIBINTL_H)
-if(NOT UNIX OR APPLE)
+if(NOT UNIX OR APPLE OR CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly")
 	find_library(INTL_LIBRARIES
 		NAMES intl
 		HINTS ${_INTL_ROOT_PATHS}
