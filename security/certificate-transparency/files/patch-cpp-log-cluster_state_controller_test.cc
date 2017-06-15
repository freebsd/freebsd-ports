--- cpp/log/cluster_state_controller_test.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/log/cluster_state_controller_test.cc
@@ -1,3 +1,6 @@
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gtest/gtest.h>
 #include <map>
 #include <memory>
