--- ../boringssl-e2a57cf/include/openssl/target.h.orig
+++ ../boringssl-e2a57cf/include/openssl/target.h
@@ -56,6 +56,11 @@
 #define OPENSSL_32_BIT
 #elif defined(__myriad2__)
 #define OPENSSL_32_BIT
+#elif defined(__powerpc64__)
+// PowerPC64 has no BoringSSL assembly; the portable C code is used and the
+// build must define OPENSSL_NO_ASM.  BoringSSL only officially supports
+// little-endian, so big-endian ppc64 is unverified.
+#define OPENSSL_64_BIT
 #else
 // The list above enumerates the platforms that BoringSSL supports. For these
 // platforms we keep a reasonable bar of not breaking them: automated test
