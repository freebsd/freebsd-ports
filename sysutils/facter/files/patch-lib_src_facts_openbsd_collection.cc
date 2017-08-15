--- lib/src/facts/openbsd/collection.cc.orig	2017-06-27 17:42:22 UTC
+++ lib/src/facts/openbsd/collection.cc
@@ -11,7 +11,7 @@
 #include <internal/facts/posix/kernel_resolver.hpp>
 #include <internal/facts/posix/ssh_resolver.hpp>
 #include <internal/facts/posix/timezone_resolver.hpp>
-#include <internal/facts/resolvers/operating_system_resolver.hpp>
+#include <internal/facts/posix/operating_system_resolver.hpp>
 
 using namespace std;
 
@@ -20,7 +20,7 @@ namespace facter { namespace facts {
     void collection::add_platform_facts()
     {
         add(make_shared<posix::kernel_resolver>());
-        add(make_shared<resolvers::operating_system_resolver>());
+        add(make_shared<posix::operating_system_resolver>());
         add(make_shared<bsd::uptime_resolver>());
         add(make_shared<bsd::filesystem_resolver>());
         add(make_shared<posix::ssh_resolver>());
