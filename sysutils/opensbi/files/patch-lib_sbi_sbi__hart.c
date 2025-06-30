--- lib/sbi/sbi_hart.c.orig	2025-06-30 03:07:30 UTC
+++ lib/sbi/sbi_hart.c
@@ -567,6 +567,16 @@ int sbi_hart_pmp_configure(struct sbi_scratch *scratch
 	if (!pmp_count)
 		return 0;
 
+	/*
+	 * Disable the PMP for the sifive/fu540 platform, required to work
+	 * around a hardware errata.
+	 */
+	extern int need_pmp_war;
+	if (need_pmp_war) {
+		pmp_set(0, PMP_R | PMP_W | PMP_X, -1, __riscv_xlen);
+		return 0;
+	}
+
 	pmp_log2gran = sbi_hart_pmp_log2gran(scratch);
 	pmp_bits = sbi_hart_pmp_addrbits(scratch) - 1;
 	pmp_addr_max = (1UL << pmp_bits) | ((1UL << pmp_bits) - 1);
