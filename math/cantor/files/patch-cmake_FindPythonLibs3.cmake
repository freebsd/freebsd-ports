--- cmake/FindPythonLibs3.cmake.orig	2020-10-31 16:59:49 UTC
+++ cmake/FindPythonLibs3.cmake
@@ -1,5 +1,5 @@
 find_package(PkgConfig)
-pkg_check_modules(PYTHONLIBS3 QUIET python3)
+pkg_check_modules(PYTHONLIBS3 QUIET python-%%PYTHON_VER%%)
 set(PYTHONLIBS3_DEFINITIONS ${PYTHONLIBS3_CFLAGS_OTHER})
 
 find_path(PYTHONLIBS3_INCLUDE_DIR Python.h
@@ -9,7 +9,7 @@ IF(WIN32)
   find_library(PYTHONLIBS3_LIBRARY NAMES python32 python33 python34 python35 python36 python37 python38
                HINTS ${PYTHONLIBS3_LIBDIR} ${PYTHONLIBS3_LIBRARY_DIRS} )
 ELSE()
-  find_library(PYTHONLIBS3_LIBRARY NAMES python3.2m python3.3m python3.4m python3.5m python3.6m python3.7m python3.8
+  find_library(PYTHONLIBS3_LIBRARY NAMES python%%PYTHON_VER%% python3.7 python3.2m python3.3m python3.4m python3.5m python3.6m python3.7m python3.8
                HINTS ${PYTHONLIBS3_LIBDIR} ${PYTHONLIBS3_LIBRARY_DIRS} )
 ENDIF()
 
