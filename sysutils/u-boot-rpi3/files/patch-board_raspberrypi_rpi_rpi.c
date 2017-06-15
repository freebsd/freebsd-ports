--- board/raspberrypi/rpi/rpi.c.orig	2017-01-09 16:57:05 UTC
+++ board/raspberrypi/rpi/rpi.c
@@ -14,6 +14,7 @@
 #include <lcd.h>
 #include <memalign.h>
 #include <mmc.h>
+#include <asm/system.h>
 #include <asm/gpio.h>
 #include <asm/arch/mbox.h>
 #include <asm/arch/sdhci.h>
@@ -27,7 +28,7 @@ DECLARE_GLOBAL_DATA_PTR;
 
 /* From lowlevel_init.S */
 extern unsigned long fw_dtb_pointer;
-
+extern unsigned long reserve_memory;
 
 struct msg_get_arm_mem {
 	struct bcm2835_mbox_hdr hdr;
@@ -220,6 +221,12 @@ static struct mm_region bcm2837_mem_map[
 };
 
 struct mm_region *mem_map = bcm2837_mem_map;
+
+void dram_init_banksize(void)
+{
+	gd->bd->bi_dram[0].start = CONFIG_SYS_SDRAM_BASE + reserve_memory;
+	gd->bd->bi_dram[0].size = get_effective_memsize() - reserve_memory;
+}
 #endif
 
 int dram_init(void)
@@ -355,6 +362,10 @@ int misc_init_r(void)
 	set_board_info();
 #endif
 	set_serial_number();
+#ifdef CONFIG_ARM64
+	if (fw_dtb_pointer)
+		setenv_hex("fdt_addr_r", (ulong)fw_dtb_pointer);
+#endif
 
 	return 0;
 }
