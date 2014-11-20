--- content/browser/indexed_db/indexed_db_backing_store.cc.orig	2014-10-10 09:15:31 UTC
+++ content/browser/indexed_db/indexed_db_backing_store.cc
@@ -2377,7 +2377,7 @@
         // The round-trip can be lossy; round to nearest millisecond.
         int64 delta = (descriptor.last_modified() -
             info.last_modified).InMilliseconds();
-        if (std::abs(delta) > 1)
+        if (std::labs(delta) > 1)
           return false;
       }
       if (!base::TouchFile(path, info.last_accessed, info.last_modified)) {
