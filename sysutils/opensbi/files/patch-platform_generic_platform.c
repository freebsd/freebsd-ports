--- platform/generic/platform.c.orig	2022-06-25 03:42:10 UTC
+++ platform/generic/platform.c
@@ -24,6 +24,8 @@
 #include <sbi_utils/ipi/fdt_ipi.h>
 #include <sbi_utils/reset/fdt_reset.h>
 
+int need_pmp_war = FALSE;
+
 /* List of platform override modules generated at compile time */
 extern const struct platform_override *platform_override_modules[];
 extern unsigned long platform_override_modules_size;
