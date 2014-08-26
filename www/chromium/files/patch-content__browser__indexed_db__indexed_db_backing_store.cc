--- ./content/browser/indexed_db/indexed_db_backing_store.cc.orig	2014-08-20 21:02:48.000000000 +0200
+++ ./content/browser/indexed_db/indexed_db_backing_store.cc	2014-08-24 10:58:24.000000000 +0200
@@ -2329,7 +2329,7 @@
         // The round-trip can be lossy; round to nearest millisecond.
         int64 delta = (descriptor.last_modified() -
             info.last_modified).InMilliseconds();
-        if (std::abs(delta) > 1)
+        if (std::labs(delta) > 1)
           return false;
       }
       if (!base::TouchFile(path, info.last_accessed, info.last_modified)) {
