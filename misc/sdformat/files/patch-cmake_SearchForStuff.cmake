--- cmake/SearchForStuff.cmake.orig	2018-11-14 23:55:43 UTC
+++ cmake/SearchForStuff.cmake
@@ -9,24 +9,24 @@ if (USE_EXTERNAL_TINYXML)
   #################################################
   # Find tinyxml. Only debian distributions package tinyxml with a pkg-config
   # Use pkg_check_modules and fallback to manual detection (needed, at least, for MacOS)
-  pkg_check_modules(tinyxml tinyxml)
+  pkg_check_modules(tinyxml tinyxml2)
   if (NOT tinyxml_FOUND)
-    find_path (tinyxml_include_dirs tinyxml.h ${tinyxml_include_dirs} ENV CPATH)
-    find_library(tinyxml_LIBRARIES NAMES tinyxml)
+    find_path (tinyxml_include_dirs tinyxml2.h ${tinyxml_include_dirs} ENV CPATH)
+    find_library(tinyxml_LIBRARIES NAMES tinyxml2)
     set (tinyxml_FAIL False)
     if (NOT tinyxml_include_dirs)
-      message (STATUS "Looking for tinyxml headers - not found")
+      message (STATUS "Looking for tinyxml2 headers - not found")
       set (tinyxml_FAIL True)
     endif()
     if (NOT tinyxml_LIBRARIES)
-      message (STATUS "Looking for tinyxml library - not found")
+      message (STATUS "Looking for tinyxml2 library - not found")
       set (tinyxml_FAIL True)
     endif()
   endif()
 
   if (tinyxml_FAIL)
-    message (STATUS "Looking for tinyxml.h - not found")
-    BUILD_ERROR("Missing: tinyxml")
+    message (STATUS "Looking for tinyxml2.h - not found")
+    BUILD_ERROR("Missing: tinyxml2")
   endif()
 else()
   # Needed in WIN32 since in UNIX the flag is added in the code installed
@@ -55,6 +55,7 @@ endif()
 if (NOT DEFINED USE_INTERNAL_URDF OR NOT USE_INTERNAL_URDF)
   # check for urdfdom with pkg-config
   pkg_check_modules(URDF urdfdom>=1.0)
+  pkg_check_modules(URDF_h urdfdom_headers>=1.0)
 
   if (NOT URDF_FOUND)
     if (NOT DEFINED USE_INTERNAL_URDF)
@@ -65,7 +66,7 @@ if (NOT DEFINED USE_INTERNAL_URDF OR NOT USE_INTERNAL_
     endif()
   else()
     # what am I doing here? pkg-config and cmake
-    set(URDF_INCLUDE_DIRS ${URDF_INCLUDEDIR})
+    set(URDF_INCLUDE_DIRS ${URDF_INCLUDEDIR} ${URDF_h_INCLUDEDIR})
     set(URDF_LIBRARY_DIRS ${URDF_LIBDIR})
   endif()
 endif()
