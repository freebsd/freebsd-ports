--- board/raspberrypi/rpi/rpi.c.orig	2016-11-14 16:27:11 UTC
+++ board/raspberrypi/rpi/rpi.c
@@ -13,6 +13,7 @@
 #include <lcd.h>
 #include <memalign.h>
 #include <mmc.h>
+#include <asm/system.h>
 #include <asm/gpio.h>
 #include <asm/arch/mbox.h>
 #include <asm/arch/sdhci.h>
@@ -253,6 +254,22 @@ static struct mm_region bcm2837_mem_map[
 };
 
 struct mm_region *mem_map = bcm2837_mem_map;
+
+static u64 fw_fdt_address  __attribute__ ((section(".data")));
+static u64 reserve_memory  __attribute__ ((section(".data")));
+
+void save_boot_params(u64 x0, u64 x1, u64 x2, u64 x3)
+{
+	fw_fdt_address = x0;
+	reserve_memory = x1;
+	save_boot_params_ret();
+}
+
+void dram_init_banksize(void)
+{
+	gd->bd->bi_dram[0].start = CONFIG_SYS_SDRAM_BASE + reserve_memory;
+	gd->bd->bi_dram[0].size = get_effective_memsize() - reserve_memory;
+}
 #endif
 
 int dram_init(void)
@@ -362,6 +379,10 @@ int misc_init_r(void)
 	set_board_info();
 #endif
 	set_serial_number();
+#ifdef CONFIG_ARM64
+	if (fw_fdt_address)
+		setenv_hex("fdt_addr_r", (ulong)fw_fdt_address);
+#endif
 
 	return 0;
 }
