--- getgit.cmake.orig	2020-05-24 12:30:37 UTC
+++ getgit.cmake
@@ -2,10 +2,10 @@
 # please take into account, that the variable 'SOURCE_DIR' has been defined by the caller
 
 # the git.cmake module is part of the standard distribution
-find_package(Git)
-if(NOT GIT_FOUND)
-  MESSAGE(FATAL_ERROR "Git not found!.")
-endif()
+#find_package(Git)
+#if(NOT GIT_FOUND)
+#  MESSAGE(FATAL_ERROR "Git not found!.")
+#endif()
 
 MACRO(History_GET_REVISION variable)
   IF(EXISTS ${CMAKE_SOURCE_DIR}/History.txt)
