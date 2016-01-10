--- cpp/log/frontend_test.cc.orig	2015-11-20 15:34:34.528539000 +0100
+++ cpp/log/frontend_test.cc	2015-11-20 15:34:47.368662000 +0100
@@ -1,5 +1,8 @@
 /* -*- indent-tabs-mode: nil -*- */
 #include <glog/logging.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 #include <memory>
