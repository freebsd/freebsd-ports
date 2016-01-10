--- cpp/log/cluster_state_controller_test.cc.orig	2015-11-20 15:24:59.021489000 +0100
+++ cpp/log/cluster_state_controller_test.cc	2015-11-20 15:25:23.094886000 +0100
@@ -1,3 +1,6 @@
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gtest/gtest.h>
 #include <map>
 #include <memory>
