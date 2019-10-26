--- src/3rdparty/chromium/third_party/boringssl/src/crypto/cpu-aarch64-linux.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/cpu-aarch64-linux.c
@@ -14,49 +14,35 @@
 
 #include <openssl/cpu.h>
 
-#if defined(OPENSSL_AARCH64) && defined(OPENSSL_LINUX) && \
-    !defined(OPENSSL_STATIC_ARMCAP)
+#if defined(OPENSSL_AARCH64)
 
-#include <sys/auxv.h>
-
 #include <openssl/arm_arch.h>
 
 #include "internal.h"
 
-
 extern uint32_t OPENSSL_armcap_P;
 
+#include <sys/types.h>
+#include <machine/armreg.h>
+
 void OPENSSL_cpuid_setup(void) {
-  unsigned long hwcap = getauxval(AT_HWCAP);
+  uint64_t id_aa64isar0;
 
-  // See /usr/include/asm/hwcap.h on an aarch64 installation for the source of
-  // these values.
-  static const unsigned long kNEON = 1 << 1;
-  static const unsigned long kAES = 1 << 3;
-  static const unsigned long kPMULL = 1 << 4;
-  static const unsigned long kSHA1 = 1 << 5;
-  static const unsigned long kSHA256 = 1 << 6;
+  id_aa64isar0 = READ_SPECIALREG(ID_AA64ISAR0_EL1);
 
-  if ((hwcap & kNEON) == 0) {
-    // Matching OpenSSL, if NEON is missing, don't report other features
-    // either.
-    return;
-  }
-
   OPENSSL_armcap_P |= ARMV7_NEON;
 
-  if (hwcap & kAES) {
+  if (ID_AA64ISAR0_AES(id_aa64isar0) == ID_AA64ISAR0_AES_BASE) {
     OPENSSL_armcap_P |= ARMV8_AES;
   }
-  if (hwcap & kPMULL) {
+  if (ID_AA64ISAR0_AES(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL) {
     OPENSSL_armcap_P |= ARMV8_PMULL;
   }
-  if (hwcap & kSHA1) {
+  if (ID_AA64ISAR0_SHA1(id_aa64isar0) == ID_AA64ISAR0_SHA1_BASE) {
     OPENSSL_armcap_P |= ARMV8_SHA1;
   }
-  if (hwcap & kSHA256) {
+  if(ID_AA64ISAR0_SHA2(id_aa64isar0) == ID_AA64ISAR0_SHA2_BASE) {
     OPENSSL_armcap_P |= ARMV8_SHA256;
   }
 }
-
-#endif  // OPENSSL_AARCH64 && !OPENSSL_STATIC_ARMCAP
+#endif  // OPENSSL_AARCH64
