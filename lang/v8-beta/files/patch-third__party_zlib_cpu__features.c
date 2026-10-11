--- third_party/zlib/cpu_features.c.orig	2026-05-26 06:33:46 UTC
+++ third_party/zlib/cpu_features.c
@@ -39,11 +39,20 @@ int ZLIB_INTERNAL riscv_cpu_enable_vclmul = 0;
 #ifndef CPU_NO_SIMD
 
 #if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || \
-    defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_IOS)
+    defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_IOS) || defined(ARMV8_OS_FREEBSD)
 #include <pthread.h>
 #endif
 
-#if defined(ARMV8_OS_ANDROID)
+#if defined(ARMV8_OS_FREEBSD)
+#include <machine/armreg.h>
+#include <sys/types.h>
+#ifndef ID_AA64ISAR0_AES_VAL
+#define ID_AA64ISAR0_AES_VAL ID_AA64ISAR0_AES
+#endif
+#ifndef ID_AA64ISAR0_CRC32_VAL
+#define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+#endif
+#elif defined(ARMV8_OS_ANDROID)
 #include <cpu-features.h>
 #elif defined(ARMV8_OS_LINUX)
 #include <asm/hwcap.h>
@@ -69,7 +78,7 @@ static void _cpu_check_features(void);
 #if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || \
     defined(ARMV8_OS_MACOS) || defined(ARMV8_OS_FUCHSIA) || \
     defined(X86_NOT_WINDOWS) || defined(ARMV8_OS_IOS) || \
-    defined(RISCV_RVV)
+    defined(RISCV_RVV) || defined(ARMV8_OS_FREEBSD)
 #if !defined(ARMV8_OS_MACOS)
 // _cpu_check_features() doesn't need to do anything on mac/arm since all
 // features are known at build time, so don't call it.
@@ -132,6 +141,13 @@ static void _cpu_check_features(void)
 #elif defined(ARMV8_OS_WINDOWS)
     arm_cpu_enable_crc32 = IsProcessorFeaturePresent(PF_ARM_V8_CRC32_INSTRUCTIONS_AVAILABLE);
     arm_cpu_enable_pmull = IsProcessorFeaturePresent(PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE);
+#elif defined(ARMV8_OS_FREEBSD)
+    uint64_t id_aa64isar0;
+    id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+    if (ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL)
+        arm_cpu_enable_pmull = 1;
+    if (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE)
+        arm_cpu_enable_crc32 = 1;
 #elif defined(ARMV8_OS_IOS)
     // Determine what features are supported dynamically. This code is applicable to macOS
     // as well if we wish to do that dynamically on that platform in the future.
