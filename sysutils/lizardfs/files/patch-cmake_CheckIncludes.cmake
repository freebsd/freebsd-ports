--- cmake/CheckIncludes.cmake.orig	2022-12-24 21:43:32 UTC
+++ cmake/CheckIncludes.cmake
@@ -3,7 +3,9 @@ include(CheckIncludeFiles)
 function(check_includes INCLUDES)
   set(INCLUDE_MISSING FALSE)
   foreach(INCLUDE_FILE ${INCLUDES})
-    check_include_files(${INCLUDE_FILE} ${INCLUDE_FILE}_FOUND)
+    string(MAKE_C_IDENTIFIER "${INCLUDE_FILE}" c_include)
+    check_include_files(${INCLUDE_FILE} ${c_include}_FOUND)
+    set(${INCLUDE_FILE}_FOUND ${${c_include}_FOUND})
     if(NOT ${INCLUDE_FILE}_FOUND)
       set(INCLUDE_MISSING TRUE)
       set(MISSING_INCLUDES ${MISSING_INCLUDES} ${INCLUDE_FILE})
