--- cpp/net/url_fetcher_test.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/net/url_fetcher_test.cc
@@ -7,6 +7,9 @@
 #include <fcntl.h>
 #include <gflags/gflags.h>
 #include <glog/logging.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gtest/gtest.h>
 #include <csignal>
 #ifdef HAVE_NETDB_H
