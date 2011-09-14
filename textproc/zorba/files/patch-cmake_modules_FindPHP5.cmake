--- cmake_modules/FindPHP5.cmake.orig	2010-07-14 15:23:17.000000000 +0200
+++ cmake_modules/FindPHP5.cmake	2011-08-19 09:45:39.000000000 +0200
@@ -26,15 +26,11 @@
 SET(PHP5_FOUND "NO")
 
 SET(PHP5_POSSIBLE_INCLUDE_PATHS
-  /usr/include/php5
-  /usr/local/include/php5
-  /usr/include/php
-  /usr/local/include/php
-  /usr/local/apache/php
+	%%LOCALBASE%%/include/php
   )
 
 SET(PHP5_POSSIBLE_LIB_PATHS
-  /usr/lib
+  %%LOCALBASE%%/lib/php
   )
 
 #FIND_PATH(PHP5_FOUND_INCLUDE_PATH main/php.h
@@ -51,8 +47,7 @@
 FIND_PROGRAM(PHP5_EXECUTABLE
   NAMES php5 php
   PATHS
-  /usr/bin
-  /usr/local/bin
+  %%LOCALBASE%%/bin
   )
 
 MARK_AS_ADVANCED(
@@ -103,9 +98,11 @@
 FIND_PROGRAM(PHP5_CONFIG_EXECUTABLE
   NAMES php5-config php-config
   PATHS
-  /usr/bin
-  /usr/local/bin
+  %%LOCALBASE%%/bin
   )
+IF(NOT PHP5_CONFIG_EXECUTABLE)
+	MESSAGE(FATAL_ERROR "PHP config executable not found")
+ENDIF(NOT PHP5_CONFIG_EXECUTABLE)
 
 EXECUTE_PROCESS(COMMAND ${PHP5_CONFIG_EXECUTABLE} --version
    OUTPUT_VARIABLE PHP5_VERSION)
