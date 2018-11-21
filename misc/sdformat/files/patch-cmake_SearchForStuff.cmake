--- cmake/SearchForStuff.cmake.orig	2018-11-21 00:19:13 UTC
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
