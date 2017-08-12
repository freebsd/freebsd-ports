--- lib/tests/facts/schema.cc.orig	2017-07-18 18:49:09 UTC
+++ lib/tests/facts/schema.cc
@@ -396,7 +396,7 @@ protected:
     {
         data result;
         result.version = 1;
-        result.features = { "1", "2", "3" };
+        result.versions = { "1", "2", "3" };
         return result;
     }
 };
@@ -433,7 +433,8 @@ protected:
     {
         data result;
         result.version = 1;
-        result.features = { "1", "2", "3" };
+        result.versions = { "1", "2", "3" };
+        result.feature_flags = { "async_destroy", "lz4_compress", "enabled_txg" };
         return result;
     }
 };
