--- third_party/zlib/arm_features.c.orig	2019-04-30 22:23:35 UTC
+++ third_party/zlib/arm_features.c
@@ -11,20 +11,11 @@
 int ZLIB_INTERNAL arm_cpu_enable_crc32 = 0;
 int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 
-#if !defined(_MSC_VER)
-
 #include <pthread.h>
 #include <stdint.h>
+#include <machine/armreg.h>
+#include <sys/types.h>
 
-#if defined(ARMV8_OS_ANDROID)
-#include <cpu-features.h>
-#elif defined(ARMV8_OS_LINUX)
-#include <asm/hwcap.h>
-#include <sys/auxv.h>
-#else
-#error arm_features.c ARM feature detection in not defined for your platform
-#endif
-
 static pthread_once_t cpu_check_inited_once = PTHREAD_ONCE_INIT;
 
 static void _arm_check_features(void);
@@ -40,54 +31,14 @@ void ZLIB_INTERNAL arm_check_features(void)
  */
 static void _arm_check_features(void)
 {
-#if defined(ARMV8_OS_ANDROID) && defined(__aarch64__)
-    uint64_t features = android_getCpuFeatures();
-    arm_cpu_enable_crc32 = !!(features & ANDROID_CPU_ARM64_FEATURE_CRC32);
-    arm_cpu_enable_pmull = !!(features & ANDROID_CPU_ARM64_FEATURE_PMULL);
-#elif defined(ARMV8_OS_ANDROID) /* aarch32 */
-    uint64_t features = android_getCpuFeatures();
-    arm_cpu_enable_crc32 = !!(features & ANDROID_CPU_ARM_FEATURE_CRC32);
-    arm_cpu_enable_pmull = !!(features & ANDROID_CPU_ARM_FEATURE_PMULL);
-#elif defined(ARMV8_OS_LINUX) && defined(__aarch64__)
-    unsigned long features = getauxval(AT_HWCAP);
-    arm_cpu_enable_crc32 = !!(features & HWCAP_CRC32);
-    arm_cpu_enable_pmull = !!(features & HWCAP_PMULL);
-#elif defined(ARMV8_OS_LINUX) && (defined(__ARM_NEON) || defined(__ARM_NEON__))
-    /* Query HWCAP2 for ARMV8-A SoCs running in aarch32 mode */
-    unsigned long features = getauxval(AT_HWCAP2);
-    arm_cpu_enable_crc32 = !!(features & HWCAP2_CRC32);
-    arm_cpu_enable_pmull = !!(features & HWCAP2_PMULL);
-#endif
-    /* TODO(crbug.com/810125): add ARMV8_OS_ZIRCON support for fucshia */
-}
+#if defined(__aarch64__)
+    uint64_t id_aa64isar0;
 
-#else /* _MSC_VER */
-
-#include <windows.h>
-
-static INIT_ONCE cpu_check_inited_once = INIT_ONCE_STATIC_INIT;
-
-static BOOL CALLBACK _arm_check_features(PINIT_ONCE once,
-                                         PVOID param,
-                                         PVOID *context);
-
-void ZLIB_INTERNAL arm_check_features(void)
-{
-    InitOnceExecuteOnce(&cpu_check_inited_once, _arm_check_features,
-                        NULL, NULL);
-}
-
-static BOOL CALLBACK _arm_check_features(PINIT_ONCE once,
-                                         PVOID param,
-                                         PVOID *context)
-{
-    if (IsProcessorFeaturePresent(PF_ARM_V8_CRC32_INSTRUCTIONS_AVAILABLE))
+    id_aa64isar0 = READ_SPECIALREG(ID_AA64ISAR0_EL1);
+    if (ID_AA64ISAR0_AES(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL)
+         arm_cpu_enable_pmull = 1;
+    if (ID_AA64ISAR0_CRC32(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE)
         arm_cpu_enable_crc32 = 1;
-
-    if (IsProcessorFeaturePresent(PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE))
-        arm_cpu_enable_pmull = 1;
-
-    return TRUE;
+#endif
 }
 
-#endif /* _MSC_VER */
