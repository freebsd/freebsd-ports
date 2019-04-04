--- src/3rdparty/chromium/third_party/zlib/arm_features.c.orig	2019-01-16 11:59:47 UTC
+++ src/3rdparty/chromium/third_party/zlib/arm_features.c
@@ -10,20 +10,33 @@
 #include <pthread.h>
 #include <stdint.h>
 
-#if defined(ARMV8_OS_ANDROID)
+int ZLIB_INTERNAL arm_cpu_enable_crc32 = 0;
+int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
+
+static pthread_once_t cpu_check_inited_once = PTHREAD_ONCE_INIT;
+
+#if defined (__FreeBSD__)
+#include <machine/armreg.h>
+#include <sys/types.h>
+static void init_arm_features(void)
+{
+#if defined (__aarch64__)
+    uint64_t id_aa64isar0;
+
+    id_aa64isar0 = READ_SPECIALREG(ID_AA64ISAR0_EL1);
+    if (ID_AA64ISAR0_AES(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL)
+        arm_cpu_enable_pmull = 1;
+    if (ID_AA64ISAR0_CRC32(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE)
+        arm_cpu_enable_crc32 = 1;
+#endif
+}
+#elif defined(ARMV8_OS_ANDROID)
 #include <cpu-features.h>
 #elif defined(ARMV8_OS_LINUX)
 #include <asm/hwcap.h>
 #include <sys/auxv.h>
-#else
-#error ### No ARM CPU features detection in your platform/OS
-#endif
 
-int ZLIB_INTERNAL arm_cpu_enable_crc32 = 0;
-int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 
-static pthread_once_t cpu_check_inited_once = PTHREAD_ONCE_INIT;
-
 static void init_arm_features(void)
 {
     uint64_t flag_crc32 = 0, flag_pmull = 0, capabilities = 0;
@@ -53,6 +66,9 @@ static void init_arm_features(void)
     if (capabilities & flag_pmull)
         arm_cpu_enable_pmull = 1;
 }
+#else
+#error ### No ARM CPU features detection in your platform/OS
+#endif
 
 void ZLIB_INTERNAL arm_check_features(void)
 {
