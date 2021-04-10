--- cmake/FindOpenEXR.cmake.orig	2021-02-05 19:21:38 UTC
+++ cmake/FindOpenEXR.cmake
@@ -91,8 +91,7 @@ if(DISABLE_CMAKE_SEARCH_PATHS)
 endif()
 
 set(_OPENEXR_COMPONENT_LIST
-  IlmImf
-  IlmImfUtil
+  OpenEXR
 )
 
 if(OpenEXR_FIND_COMPONENTS)
