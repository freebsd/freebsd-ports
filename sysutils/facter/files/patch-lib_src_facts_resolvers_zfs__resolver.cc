--- lib/src/facts/resolvers/zfs_resolver.cc.orig	2017-07-18 18:49:09 UTC
+++ lib/src/facts/resolvers/zfs_resolver.cc
@@ -18,7 +18,7 @@ namespace facter { namespace facts { nam
             "ZFS",
             {
                 fact::zfs_version,
-                fact::zfs_featurenumbers
+                fact::zfs_versionnumbers
             })
     {
     }
@@ -30,8 +30,8 @@ namespace facter { namespace facts { nam
         if (!data.version.empty()) {
             facts.add(fact::zfs_version, make_value<string_value>(move(data.version)));
         }
-        if (!data.features.empty()) {
-            facts.add(fact::zfs_featurenumbers, make_value<string_value>(boost::join(data.features, ",")));
+        if (!data.versions.empty()) {
+            facts.add(fact::zfs_versionnumbers, make_value<string_value>(boost::join(data.versions, ",")));
         }
     }
 
@@ -48,12 +48,12 @@ namespace facter { namespace facts { nam
             return true;
         });
 
-        // Get the ZFS features
-        static boost::regex zfs_feature("\\s*(\\d+)[ ]");
+        // Get the ZFS versions
+        static boost::regex zfs_supported_version("^\\s*(\\d+)[ ]");
         each_line(zfs_command(), {"upgrade", "-v"}, [&] (string& line) {
-            string feature;
-            if (re_search(line, zfs_feature, &feature)) {
-                result.features.emplace_back(move(feature));
+            string version;
+            if (re_search(line, zfs_supported_version, &version)) {
+                result.versions.emplace_back(move(version));
             }
             return true;
         });
