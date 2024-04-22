--- lib/src/facts/posix/collection.cc.orig	2022-07-18 15:00:22 UTC
+++ lib/src/facts/posix/collection.cc
@@ -25,6 +25,8 @@ namespace facter { namespace facts {
             directories.emplace_back("/opt/puppetlabs/facter/facts.d");
             directories.emplace_back("/etc/facter/facts.d");
             directories.emplace_back("/etc/puppetlabs/facter/facts.d");
+            directories.emplace_back("%%PREFIX%%/etc/facter/facts.d");
+            directories.emplace_back("%%PREFIX%%/etc/puppetlabs/facter/facts.d");
         }
         return directories;
     }
