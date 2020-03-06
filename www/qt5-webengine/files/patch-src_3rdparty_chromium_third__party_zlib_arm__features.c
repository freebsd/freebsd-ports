--- src/3rdparty/chromium/third_party/zlib/arm_features.c.orig	2019-10-21 10:14:54 UTC
+++ src/3rdparty/chromium/third_party/zlib/arm_features.c
@@ -8,83 +8,36 @@
 
 #include "zutil.h"
 
-int ZLIB_INTERNAL arm_cpu_enable_crc32 = 0;
-int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
-
-#if !defined(_MSC_VER)
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
-#error ### No ARM CPU features detection in your platform/OS
-#endif
+int ZLIB_INTERNAL arm_cpu_enable_crc32 = 0;
+int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 
 static pthread_once_t cpu_check_inited_once = PTHREAD_ONCE_INIT;
 
 static void init_arm_features(void)
 {
-    uint64_t flag_crc32 = 0, flag_pmull = 0, capabilities = 0;
-
-#if defined(ARMV8_OS_ANDROID)
-    flag_crc32 = ANDROID_CPU_ARM_FEATURE_CRC32;
-    flag_pmull = ANDROID_CPU_ARM_FEATURE_PMULL;
-    capabilities = android_getCpuFeatures();
-#elif defined(ARMV8_OS_LINUX)
-    #if defined(__aarch64__)
-        flag_crc32 = HWCAP_CRC32;
-        flag_pmull = HWCAP_PMULL;
-        capabilities = getauxval(AT_HWCAP);
-    #elif defined(__ARM_NEON) || defined(__ARM_NEON__)
-        /* The use of HWCAP2 is for getting features of newer ARMv8-A SoCs
-         * while running in 32bits mode (i.e. aarch32).
-         */
-        flag_crc32 = HWCAP2_CRC32;
-        flag_pmull = HWCAP2_PMULL;
-        capabilities = getauxval(AT_HWCAP2);
-    #endif
+#if defined (__aarch64__)
+#ifndef ID_AA64ISAR0_AES_VAL
+#define ID_AA64ISAR0_AES_VAL ID_AA64ISAR0_AES
 #endif
+#ifndef ID_AA64ISAR0_CRC32_VAL
+#define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+#endif
+    uint64_t id_aa64isar0;
 
-    if (capabilities & flag_crc32)
-        arm_cpu_enable_crc32 = 1;
-
-    if (capabilities & flag_pmull)
+    id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+    if (ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL)
         arm_cpu_enable_pmull = 1;
+    if (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE)
+        arm_cpu_enable_crc32 = 1;
+#endif
 }
 
 void ZLIB_INTERNAL arm_check_features(void)
 {
     pthread_once(&cpu_check_inited_once, init_arm_features);
 }
-#else
-#include <windows.h>
-
-static BOOL CALLBACK _arm_check_features(PINIT_ONCE once,
-                                         PVOID param,
-                                         PVOID *context);
-static INIT_ONCE cpu_check_inited_once = INIT_ONCE_STATIC_INIT;
-
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
-        arm_cpu_enable_crc32 = 1;
-
-    if (IsProcessorFeaturePresent(PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE))
-        arm_cpu_enable_pmull = 1;
-
-    return TRUE;
-}
-#endif /* _MSC_VER */
