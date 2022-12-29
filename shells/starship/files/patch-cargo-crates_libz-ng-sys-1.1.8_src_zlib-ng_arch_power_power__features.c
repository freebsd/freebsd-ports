--- cargo-crates/libz-ng-sys-1.1.8/src/zlib-ng/arch/power/power_features.c.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/libz-ng-sys-1.1.8/src/zlib-ng/arch/power/power_features.c
@@ -7,6 +7,9 @@
 #ifdef HAVE_SYS_AUXV_H
 #  include <sys/auxv.h>
 #endif
+#ifdef __FreeBSD__
+#include <machine/cpu.h>
+#endif
 #include "../../zbuild.h"
 #include "power_features.h"
 
@@ -17,7 +20,11 @@ Z_INTERNAL int power_cpu_has_arch_3_00 = 0;
 void Z_INTERNAL power_check_features(void) {
 #ifdef PPC_FEATURES
     unsigned long hwcap;
+#ifdef __FreeBSD__
+    elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+#else
     hwcap = getauxval(AT_HWCAP);
+#endif
 
     if (hwcap & PPC_FEATURE_HAS_ALTIVEC)
         power_cpu_has_altivec = 1;
@@ -25,7 +32,11 @@ void Z_INTERNAL power_check_features(void) {
 
 #ifdef POWER_FEATURES
     unsigned long hwcap2;
+#ifdef __FreeBSD__
+    elf_aux_info(AT_HWCAP2, &hwcap2, sizeof(hwcap2));
+#else
     hwcap2 = getauxval(AT_HWCAP2);
+#endif
 
     if (hwcap2 & PPC_FEATURE2_ARCH_2_07)
         power_cpu_has_arch_2_07 = 1;
