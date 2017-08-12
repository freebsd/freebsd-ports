--- lib/src/facts/bsd/collection.cc.orig	2017-06-27 17:42:22 UTC
+++ lib/src/facts/bsd/collection.cc
@@ -1,6 +1,6 @@
 #include <facter/facts/collection.hpp>
 #include <internal/facts/posix/kernel_resolver.hpp>
-#include <internal/facts/resolvers/operating_system_resolver.hpp>
+#include <internal/facts/posix/operating_system_resolver.hpp>
 #include <internal/facts/bsd/uptime_resolver.hpp>
 #include <internal/facts/bsd/filesystem_resolver.hpp>
 #include <internal/facts/posix/ssh_resolver.hpp>
@@ -15,7 +15,7 @@ namespace facter { namespace facts {
     void collection::add_platform_facts()
     {
         add(make_shared<posix::kernel_resolver>());
-        add(make_shared<resolvers::operating_system_resolver>());
+        add(make_shared<posix::operating_system_resolver>());
         add(make_shared<bsd::uptime_resolver>());
         add(make_shared<bsd::filesystem_resolver>());
         add(make_shared<posix::ssh_resolver>());
