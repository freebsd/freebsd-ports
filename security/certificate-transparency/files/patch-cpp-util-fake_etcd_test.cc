--- cpp/util/fake_etcd_test.cc.orig	2015-11-20 15:53:01.290954000 +0100
+++ cpp/util/fake_etcd_test.cc	2015-11-20 15:53:17.991665000 +0100
@@ -4,6 +4,9 @@
 #include <functional>
 #include <gflags/gflags.h>
 #include <glog/logging.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 #include <memory>
