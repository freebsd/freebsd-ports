--- external/FindLibObs.cmake.orig	2020-04-05 23:16:36 UTC
+++ external/FindLibObs.cmake
@@ -95,7 +95,7 @@ if(LIBOBS_FOUND)
 
 	set(LIBOBS_INCLUDE_DIRS ${LIBOBS_INCLUDE_DIR} ${W32_PTHREADS_INCLUDE_DIR})
 	set(LIBOBS_LIBRARIES ${LIBOBS_LIB} ${W32_PTHREADS_LIB})
-	include(${LIBOBS_INCLUDE_DIR}/../cmake/external/ObsPluginHelpers.cmake)
+	include(${CMAKE_INSTALL_PREFIX}/lib/cmake/ObsPluginHelpers.cmake)
 
 	# allows external plugins to easily use/share common dependencies that are often included with libobs (such as FFmpeg)
 	if(NOT DEFINED INCLUDED_LIBOBS_CMAKE_MODULES)
