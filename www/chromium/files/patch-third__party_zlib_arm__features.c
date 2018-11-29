--- third_party/zlib/arm_features.c.orig	2018-09-11 22:58:25 UTC
+++ third_party/zlib/arm_features.c
@@ -16,12 +16,13 @@
 #include <asm/hwcap.h>
 #include <sys/auxv.h>
 #else
-#error ### No ARM CPU features detection in your platform/OS
+/* #error ### No ARM CPU features detection in your platform/OS */
 #endif
 
 int ZLIB_INTERNAL arm_cpu_enable_crc32 = 0;
 int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 
+#ifdef ARMV8_OS_LINUX
 static pthread_once_t cpu_check_inited_once = PTHREAD_ONCE_INIT;
 
 static void init_arm_features(void)
@@ -53,8 +54,11 @@ static void init_arm_features(void)
     if (capabilities & flag_pmull)
         arm_cpu_enable_pmull = 1;
 }
+#endif
 
 void ZLIB_INTERNAL arm_check_features(void)
 {
+#ifdef ARMV8_OS_LINUX
     pthread_once(&cpu_check_inited_once, init_arm_features);
+#endif
 }
