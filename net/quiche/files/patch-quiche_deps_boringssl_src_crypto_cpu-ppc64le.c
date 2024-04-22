--- quiche/deps/boringssl/src/crypto/cpu-ppc64le.c.orig	2024-04-12 01:38:29 UTC
+++ quiche/deps/boringssl/src/crypto/cpu-ppc64le.c
@@ -28,7 +28,11 @@ void OPENSSL_cpuid_setup(void) {
 #endif
 
 void OPENSSL_cpuid_setup(void) {
+#ifdef __linux__
   OPENSSL_ppc64le_hwcap2 = getauxval(AT_HWCAP2);
+#else
+  elf_aux_info(AT_HWCAP2, &OPENSSL_ppc64le_hwcap2, sizeof(OPENSSL_ppc64le_hwcap2));
+#endif
 }
 
 int CRYPTO_is_PPC64LE_vcrypto_capable(void) {
