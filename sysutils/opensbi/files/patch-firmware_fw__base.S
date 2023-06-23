--- firmware/fw_base.S.orig	2023-07-17 15:17:18 UTC
+++ firmware/fw_base.S
@@ -309,8 +309,8 @@ _scratch_init:
 	REG_S	a5, SBI_SCRATCH_FW_SIZE_OFFSET(tp)
 
 	/* Store R/W section's offset in scratch space */
-	lla	a4, __fw_rw_offset
-	REG_L	a5, 0(a4)
+	lla	a5, _fw_rw_start
+	sub	a5, a5, a4
 	REG_S	a5, SBI_SCRATCH_FW_RW_OFFSET(tp)
 
 	/* Store fw_heap_offset and fw_heap_size in scratch space */
@@ -536,8 +536,6 @@ _link_end:
 	RISCV_PTR	FW_TEXT_START
 _link_end:
 	RISCV_PTR	_fw_reloc_end
-__fw_rw_offset:
-	RISCV_PTR	_fw_rw_start - _fw_start
 
 	.section .entry, "ax", %progbits
 	.align 3
