--- third_party/boringssl/src/crypto/cpu-aarch64-linux.c.orig	2018-08-08 21:13:09.000000000 +0200
+++ third_party/boringssl/src/crypto/cpu-aarch64-linux.c	2018-12-02 10:28:41.672362000 +0100
@@ -14,49 +14,7 @@
 
 #include <openssl/cpu.h>
 
-#if defined(OPENSSL_AARCH64) && defined(OPENSSL_LINUX) && \
-    !defined(OPENSSL_STATIC_ARMCAP)
-
-#include <sys/auxv.h>
-
-#include <openssl/arm_arch.h>
-
-#include "internal.h"
-
-
-extern uint32_t OPENSSL_armcap_P;
-
+#ifdef __FreeBSD__
 void OPENSSL_cpuid_setup(void) {
-  unsigned long hwcap = getauxval(AT_HWCAP);
-
-  // See /usr/include/asm/hwcap.h on an aarch64 installation for the source of
-  // these values.
-  static const unsigned long kNEON = 1 << 1;
-  static const unsigned long kAES = 1 << 3;
-  static const unsigned long kPMULL = 1 << 4;
-  static const unsigned long kSHA1 = 1 << 5;
-  static const unsigned long kSHA256 = 1 << 6;
-
-  if ((hwcap & kNEON) == 0) {
-    // Matching OpenSSL, if NEON is missing, don't report other features
-    // either.
-    return;
-  }
-
-  OPENSSL_armcap_P |= ARMV7_NEON;
-
-  if (hwcap & kAES) {
-    OPENSSL_armcap_P |= ARMV8_AES;
-  }
-  if (hwcap & kPMULL) {
-    OPENSSL_armcap_P |= ARMV8_PMULL;
-  }
-  if (hwcap & kSHA1) {
-    OPENSSL_armcap_P |= ARMV8_SHA1;
-  }
-  if (hwcap & kSHA256) {
-    OPENSSL_armcap_P |= ARMV8_SHA256;
-  }
 }
-
-#endif  // OPENSSL_AARCH64 && !OPENSSL_STATIC_ARMCAP
+#endif
