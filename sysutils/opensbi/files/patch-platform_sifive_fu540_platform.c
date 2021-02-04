--- platform/sifive/fu540/platform.c.orig	2021-01-30 20:28:07 UTC
+++ platform/sifive/fu540/platform.c
@@ -20,6 +20,7 @@
 #include <sbi_utils/sys/clint.h>
 
 /* clang-format off */
+int need_pmp_war = TRUE;
 
 #define FU540_HART_COUNT			5
 
