--- cmake_support/FindOPENSTRUCTURE.cmake.orig	2018-07-09 03:09:01 UTC
+++ cmake_support/FindOPENSTRUCTURE.cmake
@@ -27,7 +27,7 @@ macro(find_OPENSTRUCTURE OPENSTRUCTURE_R
       NAMES ost_${LIB}
       HINTS "${PYTHON_ROOT}"
       PATH ${OPENSTRUCTURE_ROOT}
-      PATH_SUFFIXES lib lib64
+      PATH_SUFFIXES lib
       NO_SYSTEM_ENVIRONMENT_PATH NO_DEFAULT_PATH
     )
     if (NOT FOUND_LIB)
@@ -84,4 +84,4 @@ else (OPENSTRUCTURE_FOUND)
    if (OPENSTRUCTURE_FIND_REQUIRED)
       message(FATAL_ERROR "Could not find OpenStructure")
    endif () 
-endif ()
\ No newline at end of file
+endif ()
