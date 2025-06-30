--- platform/generic/sifive/fu540.c.orig	2025-06-30 03:07:30 UTC
+++ platform/generic/sifive/fu540.c
@@ -11,6 +11,15 @@
 #include <sbi_utils/fdt/fdt_helper.h>
 #include <sbi_utils/fdt/fdt_fixup.h>
 
+extern int need_pmp_war;
+
+static int sifive_fu540_early_init(bool cold_boot)
+{
+	need_pmp_war = true;
+
+	return 0;
+}
+
 static u64 sifive_fu540_tlbr_flush_limit(void)
 {
 	/*
@@ -22,6 +31,7 @@ static int sifive_fu540_platform_init(const void *fdt,
 
 static int sifive_fu540_platform_init(const void *fdt, int nodeoff, const struct fdt_match *match)
 {
+	generic_platform_ops.early_init = sifive_fu540_early_init;
 	generic_platform_ops.get_tlbr_flush_limit = sifive_fu540_tlbr_flush_limit;
 
 	return 0;
