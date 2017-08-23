--- lib/src/facts/posix/collection.cc.orig
+++ lib/src/facts/posix/collection.cc
@@ -29,6 +29,8 @@
             directories.emplace_back("/opt/puppetlabs/facter/facts.d");
             directories.emplace_back("/etc/facter/facts.d");
             directories.emplace_back("/etc/puppetlabs/facter/facts.d");
+            directories.emplace_back("%%PREFIX%%/etc/facter/facts.d");
+            directories.emplace_back("%%PREFIX%%/etc/puppetlabs/facter/facts.d");
         }
         return directories;
     }
