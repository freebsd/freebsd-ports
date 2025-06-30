--- platform/generic/platform.c.orig	2025-06-30 03:07:30 UTC
+++ platform/generic/platform.c
@@ -30,6 +30,8 @@
 #include <sbi_utils/serial/semihosting.h>
 #include <sbi_utils/timer/fdt_timer.h>
 
+int need_pmp_war = false;
+
 /* List of platform override modules generated at compile time */
 extern const struct fdt_driver *const platform_override_modules[];
 
