--- board/sunxi/board.c.orig	2016-04-12 02:22:25 UTC
+++ board/sunxi/board.c
@@ -524,6 +524,10 @@ void sunxi_board_init(void)
 	power_failed |= axp_set_fldo(2, CONFIG_AXP_FLDO2_VOLT);
 	power_failed |= axp_set_fldo(3, CONFIG_AXP_FLDO3_VOLT);
 #endif
+
+#ifdef CONFIG_AXP818_POWER
+	power_failed |= axp_set_dc1sw(CONFIG_AXP_DC1SW_EN);
+#endif
 #endif
 	printf("DRAM:");
 	ramsize = sunxi_dram_init();
