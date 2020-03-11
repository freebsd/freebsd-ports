--- third_party/zlib/arm_features.c.orig	2020-03-03 18:54:06 UTC
+++ third_party/zlib/arm_features.c
@@ -12,10 +12,24 @@
 int ZLIB_INTERNAL arm_cpu_enable_crc32 = 0;
 int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 
+/*
+ * FreeBSD: we implicitly inherit ARMV8_OS_LINUX via zlib/BUILD.gn and
+ * "is_linux," which is true for FreeBSD builds.
+ */
 #if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA)
 #include <pthread.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <machine/armreg.h>
+#ifndef ID_AA64ISAR0_AES_VAL
+#define ID_AA64ISAR0_AES_VAL ID_AA64ISAR0_AES
+#endif
+#ifndef ID_AA64ISAR0_CRC32_VAL
+#define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+#endif
+#else /* !__FreeBSD__ */
 #if defined(ARMV8_OS_ANDROID)
 #include <cpu-features.h>
 #elif defined(ARMV8_OS_LINUX)
@@ -30,6 +44,7 @@ int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 #else
 #error arm_features.c ARM feature detection in not defined for your platform
 #endif
+#endif /* __FreeBSD__ */
 
 static void _arm_check_features(void);
 
@@ -68,14 +83,24 @@ static void _arm_check_features(void)
     arm_cpu_enable_crc32 = !!(features & ANDROID_CPU_ARM_FEATURE_CRC32);
     arm_cpu_enable_pmull = !!(features & ANDROID_CPU_ARM_FEATURE_PMULL);
 #elif defined(ARMV8_OS_LINUX) && defined(__aarch64__)
+#if defined(__FreeBSD__)
+    uint64_t id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+    arm_cpu_enable_pmull =
+        (ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL);
+    arm_cpu_enable_crc32 =
+        (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE);
+#else
     unsigned long features = getauxval(AT_HWCAP);
     arm_cpu_enable_crc32 = !!(features & HWCAP_CRC32);
     arm_cpu_enable_pmull = !!(features & HWCAP_PMULL);
+#endif /* __FreeBSD__ */
 #elif defined(ARMV8_OS_LINUX) && (defined(__ARM_NEON) || defined(__ARM_NEON__))
+#if !defined(__FreeBSD__)
     /* Query HWCAP2 for ARMV8-A SoCs running in aarch32 mode */
     unsigned long features = getauxval(AT_HWCAP2);
     arm_cpu_enable_crc32 = !!(features & HWCAP2_CRC32);
     arm_cpu_enable_pmull = !!(features & HWCAP2_PMULL);
+#endif
 #elif defined(ARMV8_OS_FUCHSIA)
     uint32_t features;
     zx_status_t rc = zx_system_get_features(ZX_FEATURE_KIND_CPU, &features);
