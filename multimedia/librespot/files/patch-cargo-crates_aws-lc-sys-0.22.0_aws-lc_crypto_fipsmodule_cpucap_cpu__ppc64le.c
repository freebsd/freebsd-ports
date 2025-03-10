--- cargo-crates/aws-lc-sys-0.22.0/aws-lc/crypto/fipsmodule/cpucap/cpu_ppc64le.c.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/aws-lc-sys-0.22.0/aws-lc/crypto/fipsmodule/cpucap/cpu_ppc64le.c
@@ -69,7 +69,11 @@ void OPENSSL_cpuid_setup(void) {
 
 void OPENSSL_cpuid_setup(void) {
 #if defined(AT_HWCAP2)
+# if defined(__linux__)
   OPENSSL_ppc64le_hwcap2 = getauxval(AT_HWCAP2);
+#elif defined(__FreeBSD__)
+  elf_aux_info(AT_HWCAP2, &OPENSSL_ppc64le_hwcap2, sizeof(OPENSSL_ppc64le_hwcap2));
+#endif
 #else
   OPENSSL_ppc64le_hwcap2 = 0;
 #endif
