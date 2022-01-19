--- platform/generic/sifive_fu540.c.orig	2021-12-24 11:57:44 UTC
+++ platform/generic/sifive_fu540.c
@@ -11,6 +11,15 @@
 #include <sbi_utils/fdt/fdt_helper.h>
 #include <sbi_utils/fdt/fdt_fixup.h>
 
+extern int need_pmp_war;
+
+static int sifive_fu540_early_init(bool cold_boot, const struct fdt_match *match)
+{
+	need_pmp_war = TRUE;
+
+	return 0;
+}
+
 static u64 sifive_fu540_tlbr_flush_limit(const struct fdt_match *match)
 {
 	/*
@@ -41,6 +50,7 @@ static const struct fdt_match sifive_fu540_match[] = {
 };
 
 const struct platform_override sifive_fu540 = {
+	.early_init = sifive_fu540_early_init,
 	.match_table = sifive_fu540_match,
 	.tlbr_flush_limit = sifive_fu540_tlbr_flush_limit,
 	.fdt_fixup = sifive_fu540_fdt_fixup,
