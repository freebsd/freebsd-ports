--- content/browser/indexed_db/indexed_db_backing_store.cc.orig	2014-10-02 17:39:47 UTC
+++ content/browser/indexed_db/indexed_db_backing_store.cc
@@ -2375,7 +2375,7 @@
         // The round-trip can be lossy; round to nearest millisecond.
         int64 delta = (descriptor.last_modified() -
             info.last_modified).InMilliseconds();
-        if (std::abs(delta) > 1)
+        if (std::labs(delta) > 1)
           return false;
       }
       if (!base::TouchFile(path, info.last_accessed, info.last_modified)) {
