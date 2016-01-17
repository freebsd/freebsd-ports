--- cpp/log/etcd_consistent_store_test.cc.orig	2015-11-20 15:30:32.679028000 +0100
+++ cpp/log/etcd_consistent_store_test.cc	2015-11-20 15:30:49.997410000 +0100
@@ -3,6 +3,9 @@
 #include <atomic>
 #include <functional>
 #include <gflags/gflags.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 #include <map>
