--- third_party/boringssl/src/crypto/cpu-aarch64-linux.c.orig	2018-09-11 22:58:51 UTC
+++ third_party/boringssl/src/crypto/cpu-aarch64-linux.c
@@ -60,3 +60,8 @@ void OPENSSL_cpuid_setup(void) {
 }
 
 #endif  // OPENSSL_AARCH64 && !OPENSSL_STATIC_ARMCAP
+
+#ifdef __FreeBSD__
+void OPENSSL_cpuid_setup(void) {
+}
+#endif
