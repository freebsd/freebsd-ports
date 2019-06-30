--- src/libcec/cmake/SetBuildInfo.cmake.orig	2017-01-28 22:51:30 UTC
+++ src/libcec/cmake/SetBuildInfo.cmake
@@ -14,14 +14,7 @@ else()
   set(LIB_INFO "")
 
   # add git revision to compile info
-  find_program(HAVE_GIT_BIN git /bin /usr/bin /usr/local/bin)
-  if(HAVE_GIT_BIN)
-    exec_program(${CMAKE_CURRENT_SOURCE_DIR}/cmake/git-rev.sh HEAD OUTPUT_VARIABLE GIT_REVISION)
-    message(STATUS "git found: ${GIT_REVISION}")
-  endif()
-  if (GIT_REVISION)
-    set(LIB_INFO "git revision: ${GIT_REVISION},")
-  endif()
+  set(LIB_INFO "git revision: 4.0.4,")
 
   # add compilation date to compile info
   find_program(HAVE_DATE_BIN date /bin /usr/bin /usr/local/bin)
