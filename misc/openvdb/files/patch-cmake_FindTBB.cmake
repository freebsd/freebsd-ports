--- cmake/FindTBB.cmake.orig	2020-08-13 19:15:58 UTC
+++ cmake/FindTBB.cmake
@@ -97,7 +97,6 @@ endif()
 set(_TBB_COMPONENT_LIST
   tbb
   tbbmalloc
-  tbbmalloc_proxy
 )
 
 if(TBB_FIND_COMPONENTS)
