--- cmake/FindTBB.cmake.orig	2021-02-05 19:21:38 UTC
+++ cmake/FindTBB.cmake
@@ -93,7 +93,6 @@ endif()
 set(_TBB_COMPONENT_LIST
   tbb
   tbbmalloc
-  tbbmalloc_proxy
 )
 
 if(TBB_FIND_COMPONENTS)
