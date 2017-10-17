--- testing/gtest/include/gtest/internal/gtest-port.h.orig	2017-10-06 21:19:08 UTC
+++ testing/gtest/include/gtest/internal/gtest-port.h
@@ -211,6 +211,7 @@
 #include <iostream>  // NOLINT
 #include <sstream>  // NOLINT
 #include <string>  // NOLINT
+#include <vector>
 
 #define GTEST_DEV_EMAIL_ "googletestframework@@googlegroups.com"
 #define GTEST_FLAG_PREFIX_ "gtest_"
