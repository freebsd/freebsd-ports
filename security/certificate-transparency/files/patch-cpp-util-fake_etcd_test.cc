--- cpp/util/fake_etcd_test.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/util/fake_etcd_test.cc
@@ -2,6 +2,9 @@
 
 #include <gflags/gflags.h>
 #include <glog/logging.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 #include <atomic>
