--- cpp/log/tree_signer_test.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/log/tree_signer_test.cc
@@ -1,4 +1,7 @@
 /* -*- indent-tabs-mode: nil -*- */
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gtest/gtest.h>
 #include <stdint.h>
 #include <memory>
