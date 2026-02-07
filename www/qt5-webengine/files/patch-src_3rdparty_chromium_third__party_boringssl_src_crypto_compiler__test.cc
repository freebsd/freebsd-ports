--- src/3rdparty/chromium/third_party/boringssl/src/crypto/compiler_test.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/compiler_test.cc
@@ -40,9 +40,13 @@ static void CheckRepresentation(T value) {
   UnsignedT value_u = static_cast<UnsignedT>(value);
   EXPECT_EQ(sizeof(UnsignedT), sizeof(T));
 
-  // Integers must be little-endian.
+  // Integers must be either big-endian or little-endian.
   uint8_t expected[sizeof(UnsignedT)];
+#ifdef OPENSSL_BIGENDIAN
+  for (size_t i = sizeof(UnsignedT); i-- > 0; ) {
+#else
   for (size_t i = 0; i < sizeof(UnsignedT); i++) {
+#endif
     expected[i] = static_cast<uint8_t>(value_u);
     // Divide instead of right-shift to appease compilers that warn if |T| is a
     // char. The explicit cast is also needed to appease MSVC if integer
