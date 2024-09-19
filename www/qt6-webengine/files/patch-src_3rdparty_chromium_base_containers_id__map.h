--- src/3rdparty/chromium/base/containers/id_map.h.orig	2024-06-10 11:34:19 UTC
+++ src/3rdparty/chromium/base/containers/id_map.h
@@ -178,8 +178,8 @@ class IDMap final {
     }
 
     const Iterator& operator=(const Iterator& iter) {
-      map_ = iter.map;
-      iter_ = iter.iter;
+      map_ = iter.map_;
+      iter_ = iter.iter_;
       Init();
       return *this;
     }
