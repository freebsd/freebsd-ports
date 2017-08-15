--- lib/src/facts/freebsd/zpool_resolver.cc.orig	2017-07-10 16:43:09 UTC
+++ lib/src/facts/freebsd/zpool_resolver.cc
@@ -0,0 +1,12 @@
+#include <internal/facts/freebsd/zpool_resolver.hpp>
+
+using namespace std;
+
+namespace facter { namespace facts { namespace freebsd {
+
+    string zpool_resolver::zpool_command()
+    {
+        return "/sbin/zpool";
+    }
+
+}}}  // namespace facter::facts::freebsd
