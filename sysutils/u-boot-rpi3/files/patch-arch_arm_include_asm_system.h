--- arch/arm/include/asm/system.h.orig	2016-11-14 16:27:11 UTC
+++ arch/arm/include/asm/system.h
@@ -201,22 +201,6 @@ void __noreturn psci_system_off(void);
  * void save_boot_params(u32 r0, u32 r1, u32 r2, u32 r3);
  */
 
-/**
- * save_boot_params_ret() - Return from save_boot_params()
- *
- * If you provide save_boot_params(), then you should jump back to this
- * function when done. Try to preserve all registers.
- *
- * If your implementation of save_boot_params() is in C then it is acceptable
- * to simply call save_boot_params_ret() at the end of your function. Since
- * there is no link register set up, you cannot just exit the function. U-Boot
- * will return to the (initialised) value of lr, and likely crash/hang.
- *
- * If your implementation of save_boot_params() is in assembler then you
- * should use 'b' or 'bx' to return to save_boot_params_ret.
- */
-void save_boot_params_ret(void);
-
 #ifdef CONFIG_ARMV7_LPAE
 void switch_to_hypervisor_ret(void);
 #endif
@@ -410,6 +394,22 @@ void mmu_page_table_flush(unsigned long 
 
 #ifndef __ASSEMBLY__
 /**
+ * save_boot_params_ret() - Return from save_boot_params()
+ *
+ * If you provide save_boot_params(), then you should jump back to this
+ * function when done. Try to preserve all registers.
+ *
+ * If your implementation of save_boot_params() is in C then it is acceptable
+ * to simply call save_boot_params_ret() at the end of your function. Since
+ * there is no link register set up, you cannot just exit the function. U-Boot
+ * will return to the (initialised) value of lr, and likely crash/hang.
+ *
+ * If your implementation of save_boot_params() is in assembler then you
+ * should use 'b' or 'bx' to return to save_boot_params_ret.
+ */
+void save_boot_params_ret(void);
+
+/**
  * Change the cache settings for a region.
  *
  * \param start		start address of memory region to change
