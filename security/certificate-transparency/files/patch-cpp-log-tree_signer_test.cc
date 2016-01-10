--- cpp/log/tree_signer_test.cc.orig	2015-11-20 15:50:58.101424000 +0100
+++ cpp/log/tree_signer_test.cc	2015-11-20 15:51:15.216405000 +0100
@@ -1,4 +1,7 @@
 /* -*- indent-tabs-mode: nil -*- */
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gtest/gtest.h>
 #include <memory>
 #include <stdint.h>
