--- cpp/util/masterelection_test.cc.orig	2015-11-20 15:54:47.351564000 +0100
+++ cpp/util/masterelection_test.cc	2015-11-20 15:55:09.284855000 +0100
@@ -6,6 +6,9 @@
 #include <string>
 #include <gflags/gflags.h>
 #include <glog/logging.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 
