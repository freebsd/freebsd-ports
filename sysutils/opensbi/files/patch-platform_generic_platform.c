--- platform/generic/platform.c.orig	2021-01-30 20:29:48 UTC
+++ platform/generic/platform.c
@@ -22,6 +22,8 @@
 #include <sbi_utils/ipi/fdt_ipi.h>
 #include <sbi_utils/reset/fdt_reset.h>
 
+int need_pmp_war = FALSE;
+
 extern const struct platform_override sifive_fu540;
 
 static const struct platform_override *special_platforms[] = {
