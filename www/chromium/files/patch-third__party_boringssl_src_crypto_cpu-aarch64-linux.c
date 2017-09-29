--- third_party/boringssl/src/crypto/cpu-aarch64-linux.c.orig	2017-09-11 03:00:27.842983000 +0200
+++ third_party/boringssl/src/crypto/cpu-aarch64-linux.c	2017-09-11 03:02:56.830632000 +0200
@@ -16,7 +16,9 @@
 
 #if defined(OPENSSL_AARCH64) && !defined(OPENSSL_STATIC_ARMCAP)
 
+#if defined(OPENSSL_LINUX)
 #include <sys/auxv.h>
+#endif
 
 #include <openssl/arm_arch.h>
 
@@ -26,6 +28,7 @@
 extern uint32_t OPENSSL_armcap_P;
 
 void OPENSSL_cpuid_setup(void) {
+#if defined(OPENSSL_LINUX)
   unsigned long hwcap = getauxval(AT_HWCAP);
 
   /* See /usr/include/asm/hwcap.h on an aarch64 installation for the source of
@@ -41,9 +44,11 @@
      * either. */
     return;
   }
+#endif
 
   OPENSSL_armcap_P |= ARMV7_NEON;
 
+#if defined(OPENSSL_LINUX)
   if (hwcap & kAES) {
     OPENSSL_armcap_P |= ARMV8_AES;
   }
@@ -56,6 +61,7 @@
   if (hwcap & kSHA256) {
     OPENSSL_armcap_P |= ARMV8_SHA256;
   }
+#endif
 }
 
 #endif /* OPENSSL_AARCH64 && !OPENSSL_STATIC_ARMCAP */
