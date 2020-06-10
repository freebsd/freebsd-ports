--- third_party/zlib/cpu_features.c.orig	2020-05-18 20:40:28 UTC
+++ third_party/zlib/cpu_features.c
@@ -24,11 +24,20 @@ int ZLIB_INTERNAL x86_cpu_enable_simd = 0;
 
 #ifndef CPU_NO_SIMD
 
-#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA)
+#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_FREEBSD)
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
@@ -49,7 +58,7 @@ int ZLIB_INTERNAL x86_cpu_enable_simd = 0;
 static void _cpu_check_features(void);
 #endif
 
-#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA) || defined(X86_NOT_WINDOWS)
+#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA) || defined(X86_NOT_WINDOWS) || defined(ARMV8_OS_FREEBSD)
 static pthread_once_t cpu_check_inited_once = PTHREAD_ONCE_INIT;
 void ZLIB_INTERNAL cpu_check_features(void)
 {
@@ -108,6 +117,13 @@ static void _cpu_check_features(void)
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
 #endif
 }
 #endif
@@ -145,4 +161,4 @@ static void _cpu_check_features(void)
 }
 #endif
 #endif
-#endif
\ No newline at end of file
+#endif
