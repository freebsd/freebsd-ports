--- cpp/log/etcd_consistent_store_test.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/log/etcd_consistent_store_test.cc
@@ -1,6 +1,9 @@
 #include "log/etcd_consistent_store.h"
 
 #include <gflags/gflags.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 #include <atomic>
