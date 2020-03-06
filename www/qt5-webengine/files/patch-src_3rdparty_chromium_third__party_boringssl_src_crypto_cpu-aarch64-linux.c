--- src/3rdparty/chromium/third_party/boringssl/src/crypto/cpu-aarch64-linux.c.orig	2019-10-21 10:14:54 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/cpu-aarch64-linux.c
@@ -14,49 +14,47 @@
 
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
 
-void OPENSSL_cpuid_setup(void) {
-  unsigned long hwcap = getauxval(AT_HWCAP);
+#include <machine/armreg.h>
 
-  // See /usr/include/asm/hwcap.h on an aarch64 installation for the source of
-  // these values.
-  static const unsigned long kNEON = 1 << 1;
-  static const unsigned long kAES = 1 << 3;
-  static const unsigned long kPMULL = 1 << 4;
-  static const unsigned long kSHA1 = 1 << 5;
-  static const unsigned long kSHA256 = 1 << 6;
+#ifndef ID_AA64ISAR0_AES_VAL
+#define ID_AA64ISAR0_AES_VAL ID_AA64ISAR0_AES
+#endif
+#ifndef ID_AA64ISAR0_AES_VAL
+#define ID_AA64ISAR0_AES_VAL ID_AA64ISAR0_AES
+#endif
+#ifndef ID_AA64ISAR0_SHA1_VAL
+#define ID_AA64ISAR0_SHA1_VAL ID_AA64ISAR0_SHA1
+#endif
+#ifndef ID_AA64ISAR0_SHA2_VAL
+#define ID_AA64ISAR0_SHA2_VAL ID_AA64ISAR0_SHA2
+#endif
 
-  if ((hwcap & kNEON) == 0) {
-    // Matching OpenSSL, if NEON is missing, don't report other features
-    // either.
-    return;
-  }
+void OPENSSL_cpuid_setup(void) {
+  uint64_t id_aa64isar0;
 
+  id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+
   OPENSSL_armcap_P |= ARMV7_NEON;
 
-  if (hwcap & kAES) {
+  if (ID_AA64ISAR0_AES_VAL(id_aa64isar0) >= ID_AA64ISAR0_AES_BASE) {
     OPENSSL_armcap_P |= ARMV8_AES;
   }
-  if (hwcap & kPMULL) {
+  if (ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL) {
     OPENSSL_armcap_P |= ARMV8_PMULL;
   }
-  if (hwcap & kSHA1) {
+  if (ID_AA64ISAR0_SHA1_VAL(id_aa64isar0) == ID_AA64ISAR0_SHA1_BASE) {
     OPENSSL_armcap_P |= ARMV8_SHA1;
   }
-  if (hwcap & kSHA256) {
+  if(ID_AA64ISAR0_SHA2_VAL(id_aa64isar0) >= ID_AA64ISAR0_SHA2_BASE) {
     OPENSSL_armcap_P |= ARMV8_SHA256;
   }
 }
-
-#endif  // OPENSSL_AARCH64 && !OPENSSL_STATIC_ARMCAP
+#endif  // OPENSSL_AARCH64
