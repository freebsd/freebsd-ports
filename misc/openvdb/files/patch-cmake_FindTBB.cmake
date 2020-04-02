--- cmake/FindTBB.cmake.orig	2020-04-01 23:48:32 UTC
+++ cmake/FindTBB.cmake
@@ -96,7 +96,6 @@ endif()
 set(_TBB_COMPONENT_LIST
   tbb
   tbbmalloc
-  tbbmalloc_proxy
 )
 
 if(TBB_FIND_COMPONENTS)
