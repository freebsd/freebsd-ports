--- content/browser/indexed_db/indexed_db_backing_store.cc.orig	2016-03-04 22:40:11.786622515 +0100
+++ content/browser/indexed_db/indexed_db_backing_store.cc	2016-03-04 22:40:23.035622110 +0100
@@ -2455,7 +2455,7 @@
         // The round-trip can be lossy; round to nearest millisecond.
         int64_t delta =
             (descriptor.last_modified() - info.last_modified).InMilliseconds();
-        if (std::abs(delta) > 1)
+        if (std::labs(delta) > 1)
           return false;
       }
       if (!base::TouchFile(path, info.last_accessed, info.last_modified)) {
