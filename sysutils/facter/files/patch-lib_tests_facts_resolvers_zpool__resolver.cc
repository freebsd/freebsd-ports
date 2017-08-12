--- lib/tests/facts/resolvers/zpool_resolver.cc.orig	2017-07-18 18:49:09 UTC
+++ lib/tests/facts/resolvers/zpool_resolver.cc
@@ -37,7 +37,8 @@ struct test_zpool_resolver : zpool_resol
     {
         data result;
         result.version = "1";
-        result.features = { "1", "2", "3" };
+        result.versions = { "1", "2", "3" };
+        result.feature_flags = { "async_destroy", "lz4_compress", "enabled_txg" };
         return result;
     }
 };
@@ -53,13 +54,16 @@ SCENARIO("using the zpool resolver") {
     WHEN("data is present") {
         facts.add(make_shared<test_zpool_resolver>());
         THEN("flat facts are added") {
-            REQUIRE(facts.size() == 2u);
+            REQUIRE(facts.size() == 3u);
             auto value = facts.get<string_value>(fact::zpool_version);
             REQUIRE(value);
             REQUIRE(value->value() == "1");
-            value = facts.get<string_value>(fact::zpool_featurenumbers);
+            value = facts.get<string_value>(fact::zpool_versionnumbers);
             REQUIRE(value);
             REQUIRE(value->value() == "1,2,3");
+            value = facts.get<string_value>(fact::zpool_featureflags);
+            REQUIRE(value);
+            REQUIRE(value->value() == "async_destroy,lz4_compress,enabled_txg");
         }
     }
 }
