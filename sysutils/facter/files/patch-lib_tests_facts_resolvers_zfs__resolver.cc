--- lib/tests/facts/resolvers/zfs_resolver.cc.orig	2017-07-18 18:49:09 UTC
+++ lib/tests/facts/resolvers/zfs_resolver.cc
@@ -37,7 +37,7 @@ struct test_zfs_resolver : zfs_resolver
     {
         data result;
         result.version = "1";
-        result.features = { "1", "2", "3" };
+        result.versions = { "1", "2", "3" };
         return result;
     }
 };
@@ -57,7 +57,7 @@ SCENARIO("using the ZFS resolver") {
             auto value = facts.get<string_value>(fact::zfs_version);
             REQUIRE(value);
             REQUIRE(value->value() == "1");
-            value = facts.get<string_value>(fact::zfs_featurenumbers);
+            value = facts.get<string_value>(fact::zfs_versionnumbers);
             REQUIRE(value);
             REQUIRE(value->value() == "1,2,3");
         }
