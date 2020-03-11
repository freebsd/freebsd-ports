--- third_party/crc32c/src/src/crc32c_arm64_linux_check.h.orig	2020-03-03 18:55:23 UTC
+++ third_party/crc32c/src/src/crc32c_arm64_linux_check.h
@@ -7,8 +7,6 @@
 #ifndef CRC32C_CRC32C_ARM_LINUX_CHECK_H_
 #define CRC32C_CRC32C_ARM_LINUX_CHECK_H_
 
-// X86-specific code checking for the availability of SSE4.2 instructions.
-
 #include <cstddef>
 #include <cstdint>
 
@@ -16,30 +14,25 @@
 
 #if HAVE_ARM64_CRC32C
 
-#if HAVE_STRONG_GETAUXVAL
-#include <sys/auxv.h>
-#elif HAVE_WEAK_GETAUXVAL
-// getauxval() is not available on Android until API level 20. Link it as a weak
-// symbol.
-extern "C" unsigned long getauxval(unsigned long type) __attribute__((weak));
+#include <sys/types.h>
+#include <machine/armreg.h>
 
-#define AT_HWCAP 16
-#endif  // HAVE_STRONG_GETAUXVAL || HAVE_WEAK_GETAUXVAL
+#ifndef ID_AA64ISAR0_AES_VAL
+#define ID_AA64ISAR0_AES_VAL ID_AA64ISAR0_AES
+#endif
+#ifndef ID_AA64ISAR0_CRC32_VAL
+#define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+#endif
 
 namespace crc32c {
 
-inline bool CanUseArm64Linux() {
-#if HAVE_STRONG_GETAUXVAL || HAVE_WEAK_GETAUXVAL
-  // From 'arch/arm64/include/uapi/asm/hwcap.h' in Linux kernel source code.
-  constexpr unsigned long kHWCAP_PMULL = 1 << 4;
-  constexpr unsigned long kHWCAP_CRC32 = 1 << 7;
-  unsigned long hwcap = (&getauxval != nullptr) ? getauxval(AT_HWCAP) : 0;
-  return (hwcap & (kHWCAP_PMULL | kHWCAP_CRC32)) ==
-         (kHWCAP_PMULL | kHWCAP_CRC32);
-#else
-  return false;
-#endif  // HAVE_STRONG_GETAUXVAL || HAVE_WEAK_GETAUXVAL
-}
+  inline bool CanUseArm64Linux() {
+    uint64_t id_aa64isar0;
+  
+    id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+    return ((ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL) &&
+      (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE));
+  }
 
 }  // namespace crc32c
 
