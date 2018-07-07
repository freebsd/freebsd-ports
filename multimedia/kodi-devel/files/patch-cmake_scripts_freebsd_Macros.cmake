objdump might not be available everywhere; use readelf instead.

find_soname() is used to fill in the blanks in xbmc/DllPaths_generated.h.in

--- cmake/scripts/freebsd/Macros.cmake.orig	2018-06-30 06:25:00 UTC
+++ cmake/scripts/freebsd/Macros.cmake
@@ -78,15 +78,11 @@ function(find_soname lib)
     string(REGEX MATCH ".*lib${liblow}.so" ${lib}_FILENAME ${_TMP_FILENAME})
   endif()
   if(${lib}_FILENAME)
-    execute_process(COMMAND ${CMAKE_OBJDUMP} -p ${${lib}_FILENAME}
-                    COMMAND grep SONAME.*${liblow}
+    execute_process(COMMAND readelf -d ${${lib}_FILENAME}
+                    COMMAND awk "$2 == \"SONAME\" { printf \"%s\", substr($NF, 2, length($NF) - 2) }"
                     ERROR_QUIET
                     OUTPUT_VARIABLE ${lib}_SONAME)
-    string(REPLACE "SONAME " "" ${lib}_SONAME ${${lib}_SONAME})
-    string(STRIP ${${lib}_SONAME} ${lib}_SONAME)
-    if(VERBOSE)
-      message(STATUS "${lib} soname: ${${lib}_SONAME}")
-    endif()
+    message(STATUS "${lib} soname: ${${lib}_SONAME}")
     set(${lib}_SONAME ${${lib}_SONAME} PARENT_SCOPE)
   endif()
   if(arg_REQUIRED AND NOT ${lib}_SONAME)
