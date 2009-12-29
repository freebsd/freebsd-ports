--- cmake/modules/tcl-related.cmake.orig	2009-09-06 21:04:43.000000000 +0200
+++ cmake/modules/tcl-related.cmake	2009-12-25 17:44:43.000000000 +0100
@@ -98,11 +98,13 @@
 	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/cmake/modules
 	OUTPUT_VARIABLE itcl_library_versions)
         message(STATUS "Looking for itcl.h")
-        find_path(ITCL_INCLUDE_PATH itcl.h ${TCL_INCLUDE_PATH})
+        find_path(ITCL_INCLUDE_PATH itcl.h ${TCL_INCLUDE_PATH}/../itcl%%ITCL_VER%%)
         if(ITCL_INCLUDE_PATH)
           message(STATUS "Looking for itcl.h - found")
           message(STATUS "Looking for itcl library")
 	get_filename_component(TCL_LIBRARY_PATH ${TCL_LIBRARY} PATH)
+          find_library(ITCL_LIBRARY itcl PATHS ${TCL_LIBRARY_PATH}
+              PATH_SUFFIXES itcl)
           set(itcl_library_versions 3.4 3.3 3.2 3.1 3.0 2.1 2.0)
           foreach(version ${itcl_library_versions})
             find_library(ITCL_LIBRARY itcl${version} PATHS ${TCL_LIBRARY_PATH}
@@ -158,11 +160,12 @@
     endif(ENABLE_tk)
     if(ENABLE_itk)
       message(STATUS "Looking for itk.h")
-      find_path(ITK_INCLUDE_PATH itk.h ${TK_INCLUDE_PATH})
+      find_path(ITK_INCLUDE_PATH itk.h ${TCL_INCLUDE_PATH}/../itk%%ITCL_VER%%)
       if(ITK_INCLUDE_PATH)
         message(STATUS "Looking for itk.h - found")
         message(STATUS "Looking for itk library")
-        set(itk_library_versions 3.4 3.3 3.2 3.1 3.0 2.1 2.0)
+        find_library(ITK_LIBRARY itk PATH_SUFFIXES itk)
+        set(itk_library_versions "" 3.4 3.3 3.2 3.1 3.0 2.1 2.0)
         foreach(version ${itk_library_versions})
           find_library(ITK_LIBRARY itk${version}
             PATH_SUFFIXES itk${version})
