--- lib/src/facts/freebsd/zfs_resolver.cc.orig	2017-07-10 16:43:09 UTC
+++ lib/src/facts/freebsd/zfs_resolver.cc
@@ -0,0 +1,12 @@
+#include <internal/facts/freebsd/zfs_resolver.hpp>
+
+using namespace std;
+
+namespace facter { namespace facts { namespace freebsd {
+
+    string zfs_resolver::zfs_command()
+    {
+        return "/sbin/zfs";
+    }
+
+}}}  // namespace facter::facts::freebsd
