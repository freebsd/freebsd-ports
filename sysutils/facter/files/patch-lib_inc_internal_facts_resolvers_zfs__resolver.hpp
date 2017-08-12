--- lib/inc/internal/facts/resolvers/zfs_resolver.hpp.orig	2017-07-18 18:49:09 UTC
+++ lib/inc/internal/facts/resolvers/zfs_resolver.hpp
@@ -43,9 +43,9 @@ namespace facter { namespace facts { nam
              */
             std::string version;
             /**
-             * Stores the ZFS feature numbers.
+             * Stores the ZFS version numbers.
              */
-            std::vector<std::string> features;
+            std::vector<std::string> versions;
         };
 
         /**
