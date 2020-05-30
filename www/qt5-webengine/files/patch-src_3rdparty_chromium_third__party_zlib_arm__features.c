--- src/3rdparty/chromium/third_party/zlib/arm_features.c.orig	2020-03-22 20:03:48 UTC
+++ src/3rdparty/chromium/third_party/zlib/arm_features.c
@@ -12,7 +12,7 @@
 int ZLIB_INTERNAL arm_cpu_enable_crc32 = 0;
 int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 
-#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA)
+#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_FREEBSD)
 #include <pthread.h>
 #endif
 
@@ -27,13 +27,22 @@ int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 #include <zircon/types.h>
 #elif defined(ARMV8_OS_WINDOWS)
 #include <windows.h>
+#elif defined(ARMV8_OS_FREEBSD)
+#include <machine/armreg.h>
+#include <sys/types.h>
+#ifndef ID_AA64ISAR0_AES_VAL
+#define ID_AA64ISAR0_AES_VAL ID_AA64ISAR0_AES
+#endif
+#ifndef ID_AA64ISAR0_CRC32_VAL
+#define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+#endif
 #else
 #error arm_features.c ARM feature detection in not defined for your platform
 #endif
 
 static void _arm_check_features(void);
 
-#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA)
+#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_FREEBSD)
 static pthread_once_t cpu_check_inited_once = PTHREAD_ONCE_INIT;
 void ZLIB_INTERNAL arm_check_features(void)
 {
@@ -86,5 +95,12 @@ static void _arm_check_features(void)
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
