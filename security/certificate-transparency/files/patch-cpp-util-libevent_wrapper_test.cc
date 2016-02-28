--- cpp/util/libevent_wrapper_test.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/util/libevent_wrapper_test.cc
@@ -1,5 +1,8 @@
 #include "util/libevent_wrapper.h"
 
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h; note it's only compiled with "make check".
+#define GTEST_HAS_POSIX_RE 0
 #include <gtest/gtest.h>
 
 #include "util/testing.h"
