--- src/assistant/3rdparty/clucene/src/CLucene/search/FieldCacheImpl.cpp
+++ src/assistant/3rdparty/clucene/src/CLucene/search/FieldCacheImpl.cpp
@@ -11,6 +11,8 @@
 CL_NS_USE(index)
 CL_NS_DEF(search)
 
+using ::wcschr;
+
 FieldCacheImpl::FieldCacheImpl():
     cache(false,true){
 }
