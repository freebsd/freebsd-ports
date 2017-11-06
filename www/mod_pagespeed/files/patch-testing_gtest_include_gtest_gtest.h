--- testing/gtest/include/gtest/gtest.h.orig	2017-10-06 20:33:54 UTC
+++ testing/gtest/include/gtest/gtest.h
@@ -55,6 +55,10 @@
 #include <ostream>
 #include <vector>
 
+#ifndef GTEST_HAS_DEATH_TEST
+#define GTEST_HAS_DEATH_TEST 1
+#endif
+
 #include "gtest/internal/gtest-internal.h"
 #include "gtest/internal/gtest-string.h"
 #include "gtest/gtest-death-test.h"
