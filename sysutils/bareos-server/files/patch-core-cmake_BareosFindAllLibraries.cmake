--- core/cmake/BareosFindAllLibraries.cmake	2019-05-10 00:27:21.421777000 -0500
+++ core/cmake/BareosFindAllLibraries.cmake	2019-05-10 00:28:47.016424000 -0500
@@ -25,13 +25,15 @@
 
 
 if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
-   # make sure we get python 2 not 3
-   set(Python_ADDITIONAL_VERSIONS 2.5 2.6 2.7 2.8 2.9)
-   find_package(PythonInterp)
-   INCLUDE(FindPythonLibs)
+   if (python)
+     # make sure we get python 2 or 3
+     set(Python_ADDITIONAL_VERSIONS 3.5 3.6 3.7 3.8 2.7)
+     find_package(PythonInterp)
+     INCLUDE(FindPythonLibs)
 
-   if (${PYTHONLIBS_FOUND})
-      SET(HAVE_PYTHON 1)
+     if (${PYTHONLIBS_FOUND})
+        SET(HAVE_PYTHON 1)
+     endif()
    endif()
 
    INCLUDE(FindPostgreSQL)
