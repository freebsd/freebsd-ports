--- cpp/util/etcd_test.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/util/etcd_test.cc
@@ -1,3 +1,6 @@
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 #include <list>
