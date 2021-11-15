--- cmake/FindTBB.cmake.orig	2021-10-30 02:55:40 UTC
+++ cmake/FindTBB.cmake
@@ -110,7 +110,6 @@ endif()
 set(_TBB_COMPONENT_LIST
   tbb
   tbbmalloc
-  tbbmalloc_proxy
 )
 
 if(TBB_FIND_COMPONENTS)
