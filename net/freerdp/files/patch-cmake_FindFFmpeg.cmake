--- cmake/FindFFmpeg.cmake.orig	2013-03-07 10:38:36.747254870 +0000
+++ cmake/FindFFmpeg.cmake	2013-03-07 10:42:07.891253483 +0000
@@ -8,19 +8,19 @@
 include(FindPkgConfig)
 
 if (PKG_CONFIG_FOUND)
-	pkg_check_modules(AVCODEC libavcodec)
-	pkg_check_modules(AVUTIL libavutil)
+	pkg_check_modules(AVCODEC libavcodec-devel)
+	pkg_check_modules(AVUTIL libavutil-devel)
 endif ( PKG_CONFIG_FOUND )
 
 # avcodec
 find_path(AVCODEC_INCLUDE_DIR avcodec.h PATHS ${AVCODEC_INCLUDE_DIRS}
           PATH_SUFFIXES libavcodec )
-find_library(AVCODEC_LIBRARY avcodec PATHS ${AVCODEC_LIBRARY_DIRS})
+find_library(AVCODEC_LIBRARY avcodec-devel PATHS ${AVCODEC_LIBRARY_DIRS})
 
 # avutil
 find_path(AVUTIL_INCLUDE_DIR avutil.h PATHS ${AVUTIL_INCLUDE_DIRS}
           PATH_SUFFIXES libavutil )
-find_library(AVUTIL_LIBRARY avutil PATHS ${AVUTIL_LIBRARY_DIRS})
+find_library(AVUTIL_LIBRARY avutil-devel PATHS ${AVUTIL_LIBRARY_DIRS})
 
 if(AVCODEC_INCLUDE_DIR AND AVCODEC_LIBRARY)
 	set(AVCODEC_FOUND TRUE)
