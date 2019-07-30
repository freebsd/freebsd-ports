--- src/aircrack-util/trampoline_ppc.c.orig	2019-07-19 18:16:49 UTC
+++ src/aircrack-util/trampoline_ppc.c
@@ -19,8 +19,10 @@
 #if defined(__ppc__) || defined(__PPC__)
 #ifdef HAS_AUXV
 #include <sys/auxv.h>
+#ifndef __FreeBSD__
 #include <bits/hwcap.h>
 #endif
+#endif
 #else
 #error "The wrong CPU architecture file has been included."
 #endif
@@ -35,7 +37,12 @@ int simd_get_supported_features(void)
 {
 	int result = 0;
 #ifdef HAS_AUXV
+#ifndef __FreeBSD__
 	long hwcaps = getauxval(AT_HWCAP2);
+#else
+	long hwcaps;
+	elf_aux_info(AT_HWCAP2, &hwcaps, sizeof(hwcaps));
+#endif
 
 #if defined(PPC_FEATURE2_ARCH_2_07)
 	if (hwcaps & PPC_FEATURE2_ARCH_2_07)
