--- platform/generic/platform.c.orig	2021-12-24 11:57:44 UTC
+++ platform/generic/platform.c
@@ -23,6 +23,8 @@
 #include <sbi_utils/ipi/fdt_ipi.h>
 #include <sbi_utils/reset/fdt_reset.h>
 
+int need_pmp_war = FALSE;
+
 extern const struct platform_override sifive_fu540;
 extern const struct platform_override sifive_fu740;
 
