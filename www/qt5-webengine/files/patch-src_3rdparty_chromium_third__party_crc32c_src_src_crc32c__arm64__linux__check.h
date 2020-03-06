--- src/3rdparty/chromium/third_party/crc32c/src/src/crc32c_arm64_linux_check.h.orig	2019-10-21 10:14:54 UTC
+++ src/3rdparty/chromium/third_party/crc32c/src/src/crc32c_arm64_linux_check.h
@@ -16,6 +16,29 @@
 
 #if HAVE_ARM64_CRC32C
 
+#if defined(__FreeBSD__)
+#include <machine/armreg.h>
+#ifndef ID_AA64ISAR0_AES_VAL
+#define ID_AA64ISAR0_AES_VAL ID_AA64ISAR0_AES
+#endif
+#ifndef ID_AA64ISAR0_CRC32_VAL
+#define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+#endif
+namespace crc32c {
+
+inline bool CanUseArm64Linux() {
+  uint64_t id_aa64isar0;
+
+  id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+  if ((ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL) && \
+     (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE))
+    return true;
+  return false;
+}
+
+}  // namespace crc32c
+
+#elif defined(__linux__)
 #if HAVE_STRONG_GETAUXVAL
 #include <sys/auxv.h>
 #elif HAVE_WEAK_GETAUXVAL
@@ -43,6 +66,7 @@ inline bool CanUseArm64Linux() {
 
 }  // namespace crc32c
 
+#endif
 #endif  // HAVE_ARM64_CRC32C
 
 #endif  // CRC32C_CRC32C_ARM_LINUX_CHECK_H_
