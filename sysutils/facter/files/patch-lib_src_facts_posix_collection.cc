--- lib/src/facts/posix/collection.cc.orig	2017-09-12 21:43:10 UTC
+++ lib/src/facts/posix/collection.cc
@@ -29,6 +29,8 @@ namespace facter { namespace facts {
             directories.emplace_back("/opt/puppetlabs/facter/facts.d");
             directories.emplace_back("/etc/facter/facts.d");
             directories.emplace_back("/etc/puppetlabs/facter/facts.d");
+            directories.emplace_back("%%PREFIX%%/etc/facter/facts.d");
+            directories.emplace_back("%%PREFIX%%/etc/puppetlabs/facter/facts.d");
         }
         return directories;
     }
