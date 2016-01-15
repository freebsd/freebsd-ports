--- cpp/fetcher/remote_peer_test.cc.orig	2015-11-20 15:20:24.460754000 +0100
+++ cpp/fetcher/remote_peer_test.cc	2015-11-20 15:22:18.618590000 +0100
@@ -1,5 +1,8 @@
 #include <gflags/gflags.h>
 #include <glog/logging.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 #include "log/etcd_consistent_store.h"
