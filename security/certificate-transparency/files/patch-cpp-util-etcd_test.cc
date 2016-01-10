--- cpp/util/etcd_test.cc.orig	2015-11-20 15:52:11.557932000 +0100
+++ cpp/util/etcd_test.cc	2015-11-20 15:52:28.585505000 +0100
@@ -1,3 +1,6 @@
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 #include <list>
