--- lib/inc/internal/facts/resolvers/zpool_resolver.hpp.orig	2017-07-18 18:49:09 UTC
+++ lib/inc/internal/facts/resolvers/zpool_resolver.hpp
@@ -43,9 +43,13 @@ namespace facter { namespace facts { nam
              */
             std::string version;
             /**
-             * Stores the zpool feature numbers.
+             * Stores the zpool feature flags.
              */
-            std::vector<std::string> features;
+            std::vector<std::string> feature_flags;
+            /**
+             * Stores the zpool version numbers.
+             */
+            std::vector<std::string> versions;
         };
 
         /**
