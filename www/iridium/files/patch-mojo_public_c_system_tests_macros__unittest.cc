--- mojo/public/c/system/tests/macros_unittest.cc.orig	2018-05-09 19:05:53 UTC
+++ mojo/public/c/system/tests/macros_unittest.cc
@@ -34,8 +34,11 @@ TEST(MacrosTest, Alignof) {
   // all the platforms we currently support.
   EXPECT_EQ(1u, MOJO_ALIGNOF(char));
   EXPECT_EQ(4u, MOJO_ALIGNOF(int32_t));
-  EXPECT_EQ(8u, MOJO_ALIGNOF(int64_t));
-  EXPECT_EQ(8u, MOJO_ALIGNOF(double));
+
+  // 'double' and 'int64_t' are usually 8 byte aligned, except some 32-bit x86
+  // platforms, or when -malign-double is passed.
+  EXPECT_TRUE(8u == MOJO_ALIGNOF(int64_t) || 4u == MOJO_ALIGNOF(int64_t));
+  EXPECT_TRUE(8u == MOJO_ALIGNOF(double) || 4u == MOJO_ALIGNOF(double));
 }
 
 // These structs are used in the Alignas test. Define them globally to avoid
