--- cmake_modules/FindPHP5.cmake.orig	2012-06-21 09:33:11.000000000 +0200
+++ cmake_modules/FindPHP5.cmake	2012-06-21 09:34:40.000000000 +0200
@@ -27,15 +27,11 @@
 SET(PHP5_FOUND "NO")
 
 SET(PHP5_POSSIBLE_INCLUDE_PATHS
-  /usr/include/php5
-  /usr/local/include/php5
-  /usr/include/php
-  /usr/local/include/php
-  /usr/local/apache/php
+  %%LOCALBASE%%/include/php
   )
 
 SET(PHP5_POSSIBLE_LIB_PATHS
-  /usr/lib
+  %%LOCALBASE%%/lib/php
   )
 
 #FIND_PATH(PHP5_FOUND_INCLUDE_PATH main/php.h
@@ -52,8 +48,7 @@
 FIND_PROGRAM(PHP5_EXECUTABLE
   NAMES php5 php
   PATHS
-  /usr/bin
-  /usr/local/bin
+  %%LOCALBASE%%/bin
   ${PHP5_BINARY_DIR}
   )
 MESSAGE(STATUS "Executable: " ${PHP5_EXECUTABLE})
@@ -116,8 +111,7 @@
 FIND_PROGRAM(PHP5_CONFIG_EXECUTABLE
   NAMES php5-config php-config
   PATHS
-  /usr/bin
-  /usr/local/bin
+  %%LOCALBASE%%/bin
   )
 
 EXECUTE_PROCESS(COMMAND ${PHP5_CONFIG_EXECUTABLE} --version
