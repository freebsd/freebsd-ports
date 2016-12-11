--- cmake/ConfigOptions.cmake.orig	2015-11-29 19:53:58 UTC
+++ cmake/ConfigOptions.cmake
@@ -6,7 +6,7 @@ elseif((CMAKE_SYSTEM_PROCESSOR MATCHES "
 elseif((CMAKE_SYSTEM_PROCESSOR MATCHES "i386") AND (CMAKE_SIZEOF_VOID_P EQUAL 8) AND (APPLE))
 	# Mac is weird like that.
 	set(TARGET_ARCH "x64")
-elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm*")
+elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^arm*")
 	set(TARGET_ARCH "ARM")
 endif()
 
