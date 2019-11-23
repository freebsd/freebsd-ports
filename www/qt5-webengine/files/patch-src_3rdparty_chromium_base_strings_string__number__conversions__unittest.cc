--- src/3rdparty/chromium/base/strings/string_number_conversions_unittest.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/strings/string_number_conversions_unittest.cc
@@ -829,12 +829,21 @@ TEST(StringNumberConversionsTest, DoubleToString) {
   }
 
   // The following two values were seen in crashes in the wild.
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
   const char input_bytes[8] = {0, 0, 0, 0, '\xee', '\x6d', '\x73', '\x42'};
+#else
+  const char input_bytes[8] = {'\x42', '\x73', '\x6d', '\xee', 0, 0, 0, 0};
+#endif
   double input = 0;
   memcpy(&input, input_bytes, base::size(input_bytes));
   EXPECT_EQ("1335179083776", NumberToString(input));
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
   const char input_bytes2[8] =
       {0, 0, 0, '\xa0', '\xda', '\x6c', '\x73', '\x42'};
+#else
+  const char input_bytes2[8] =
+      {'\x42', '\x73', '\x6c', '\xda', '\xa0', 0, 0, 0};
+#endif
   input = 0;
   memcpy(&input, input_bytes2, base::size(input_bytes2));
   EXPECT_EQ("1334890332160", NumberToString(input));
