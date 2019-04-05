--- third_party/crc32c/src/src/crc32c_arm64_linux_check.h.orig	2019-03-11 22:07:59 UTC
+++ third_party/crc32c/src/src/crc32c_arm64_linux_check.h
@@ -29,6 +29,8 @@ extern "C" unsigned long getauxval(unsigned long type)
 namespace crc32c {
 
 inline bool CanUseArm64Linux() {
+return false;
+#if 0
 #if HAVE_STRONG_GETAUXVAL || HAVE_WEAK_GETAUXVAL
   // From 'arch/arm64/include/uapi/asm/hwcap.h' in Linux kernel source code.
   constexpr unsigned long kHWCAP_PMULL = 1 << 4;
@@ -39,6 +41,7 @@ inline bool CanUseArm64Linux() {
 #else
   return false;
 #endif  // HAVE_STRONG_GETAUXVAL || HAVE_WEAK_GETAUXVAL
+#endif
 }
 
 }  // namespace crc32c
