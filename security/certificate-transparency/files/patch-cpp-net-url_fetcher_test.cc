--- cpp/net/url_fetcher_test.cc.orig	2015-11-20 15:17:37.750964000 +0100
+++ cpp/net/url_fetcher_test.cc	2015-11-20 15:18:12.043994000 +0100
@@ -8,6 +8,9 @@
 #include <fcntl.h>
 #include <gflags/gflags.h>
 #include <glog/logging.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gtest/gtest.h>
 #ifdef HAVE_NETDB_H
 #  include <netdb.h>
