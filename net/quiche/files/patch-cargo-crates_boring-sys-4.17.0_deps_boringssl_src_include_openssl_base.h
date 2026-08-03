--- cargo-crates/boring-sys-4.17.0/deps/boringssl/src/include/openssl/base.h.orig	2026-08-03 09:53:19 UTC
+++ cargo-crates/boring-sys-4.17.0/deps/boringssl/src/include/openssl/base.h
@@ -116,6 +116,11 @@ extern "C" {
 #define OPENSSL_32_BIT
 #elif defined(__myriad2__)
 #define OPENSSL_32_BIT
+#elif defined(__powerpc64__)
+// PowerPC64 has no BoringSSL assembly; the portable C code is used and the
+// build must define OPENSSL_NO_ASM.  BoringSSL only officially supports
+// little-endian, so big-endian ppc64 is unverified.
+#define OPENSSL_64_BIT
 #else
 // Note BoringSSL only supports standard 32-bit and 64-bit two's-complement,
 // little-endian architectures. Functions will not produce the correct answer
