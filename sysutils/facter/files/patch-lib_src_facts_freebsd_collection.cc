--- lib/src/facts/freebsd/collection.cc.orig	2017-07-18 18:49:09 UTC
+++ lib/src/facts/freebsd/collection.cc
@@ -8,8 +8,12 @@
 #include <internal/facts/posix/kernel_resolver.hpp>
 #include <internal/facts/posix/ssh_resolver.hpp>
 #include <internal/facts/posix/timezone_resolver.hpp>
-#include <internal/facts/resolvers/operating_system_resolver.hpp>
+#include <internal/facts/freebsd/operating_system_resolver.hpp>
 #include <internal/facts/freebsd/networking_resolver.hpp>
+#include <internal/facts/freebsd/virtualization_resolver.hpp>
+#include <internal/facts/freebsd/memory_resolver.hpp>
+#include <internal/facts/freebsd/zfs_resolver.hpp>
+#include <internal/facts/freebsd/zpool_resolver.hpp>
 
 using namespace std;
 
@@ -18,7 +22,7 @@ namespace facter { namespace facts {
     void collection::add_platform_facts()
     {
         add(make_shared<posix::kernel_resolver>());
-        add(make_shared<resolvers::operating_system_resolver>());
+        add(make_shared<freebsd::operating_system_resolver>());
         add(make_shared<freebsd::networking_resolver>());
         add(make_shared<bsd::uptime_resolver>());
         add(make_shared<bsd::filesystem_resolver>());
@@ -28,6 +32,10 @@ namespace facter { namespace facts {
         add(make_shared<glib::load_average_resolver>());
         add(make_shared<freebsd::processor_resolver>());
         add(make_shared<freebsd::dmi_resolver>());
+        add(make_shared<freebsd::virtualization_resolver>());
+        add(make_shared<freebsd::memory_resolver>());
+        add(make_shared<freebsd::zfs_resolver>());
+        add(make_shared<freebsd::zpool_resolver>());
     }
 
 }}  // namespace facter::facts
