--- ext/arm32-neon-salsa2012-asm/salsa2012.h.orig	2018-07-27 21:14:09 UTC
+++ ext/arm32-neon-salsa2012-asm/salsa2012.h
@@ -5,8 +5,10 @@
 #include <sys/auxv.h>
 #include <asm/hwcap.h>
 #define zt_arm_has_neon() ((getauxval(AT_HWCAP) & HWCAP_NEON) != 0)
-#else
+#elif defined(__ARM_NEON__) || defined(__ARM_NEON)
 #define zt_arm_has_neon() (true)
+#else
+#define zt_arm_has_neon() (false)
 #endif
 
 #ifdef __cplusplus
