--- src/3rdparty/chromium/base/metrics/bucket_ranges_unittest.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/metrics/bucket_ranges_unittest.cc
@@ -7,6 +7,7 @@
 #include <stdint.h>
 
 #include "testing/gtest/include/gtest/gtest.h"
+#include "base/sys_byteorder.h"
 
 namespace base {
 namespace {
@@ -64,13 +65,21 @@ TEST(BucketRangesTest, Checksum) {
   ranges.set_range(2, 2);
 
   ranges.ResetChecksum();
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
   EXPECT_EQ(289217253u, ranges.checksum());
+#else
+  EXPECT_EQ(2767231596u, ranges.checksum());
+#endif
 
   ranges.set_range(2, 3);
   EXPECT_FALSE(ranges.HasValidChecksum());
 
   ranges.ResetChecksum();
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
   EXPECT_EQ(2843835776u, ranges.checksum());
+#else
+  EXPECT_EQ(3556223738u, ranges.checksum());
+#endif
   EXPECT_TRUE(ranges.HasValidChecksum());
 }
 
