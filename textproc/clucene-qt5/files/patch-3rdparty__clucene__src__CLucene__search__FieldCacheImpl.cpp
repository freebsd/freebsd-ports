--- ./3rdparty/clucene/src/CLucene/search/FieldCacheImpl.cpp.orig	2012-12-18 20:04:15.000000000 +0100
+++ ./3rdparty/clucene/src/CLucene/search/FieldCacheImpl.cpp	2013-01-07 11:29:50.837339980 +0100
@@ -11,6 +11,8 @@
 CL_NS_USE(index)
 CL_NS_DEF(search)
 
+using ::wcschr;
+
 FieldCacheImpl::FieldCacheImpl():
     cache(false,true){
 }
