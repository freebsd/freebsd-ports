--- src/libcec/cmake/SetBuildInfo.cmake.orig	2018-12-21 21:34:45 UTC
+++ src/libcec/cmake/SetBuildInfo.cmake
@@ -15,10 +15,6 @@ else()
 
   # add git revision to compile info
   find_program(HAVE_GIT_BIN git /bin /usr/bin /usr/local/bin)
-  if(HAVE_GIT_BIN)
-    exec_program(${CMAKE_CURRENT_SOURCE_DIR}/cmake/git-rev.sh HEAD OUTPUT_VARIABLE GIT_REVISION)
-    message(STATUS "git found: ${GIT_REVISION}")
-  endif()
   if (GIT_REVISION)
     set(LIB_INFO "git revision: ${GIT_REVISION},")
   endif()
