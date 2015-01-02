--- board/technexion/edm_cf_imx6/edm_cf_imx6.c.orig	2014-06-12 07:50:48 UTC
+++ board/technexion/edm_cf_imx6/edm_cf_imx6.c
@@ -63,10 +63,16 @@ enum boot_device get_boot_device(void);
 
 static inline void setup_boot_device(void)
 {
-	uint soc_sbmr = readl(SRC_BASE_ADDR + 0x4);
-	uint bt_mem_ctl = (soc_sbmr & 0x000000FF) >> 4 ;
-	uint bt_mem_type = (soc_sbmr & 0x00000008) >> 3;
-	uint bt_mem_mmc = (soc_sbmr & 0x00001000) >> 12;
+	uint bt_mem_ctl, bt_mem_mmc, bt_mem_type, soc_sbmr;
+
+	/* Use GPR9 if non-zero, else SBMR. */
+	soc_sbmr = readl(SRC_BASE_ADDR + 0x40);
+	if (soc_sbmr == 0)
+		soc_sbmr = readl(SRC_BASE_ADDR + 0x4);
+
+	bt_mem_ctl = (soc_sbmr & 0x000000FF) >> 4 ;
+	bt_mem_type = (soc_sbmr & 0x00000008) >> 3;
+	bt_mem_mmc = (soc_sbmr & 0x00001000) >> 12;
 
 	switch (bt_mem_ctl) {
 	case 0x0:
@@ -623,6 +629,26 @@ static const struct boot_mode board_boot
 
 int board_late_init(void)
 {
+	const char *imxname;
+	uint cpurev, imxtype;
+
+	cpurev = get_cpu_rev();
+	imxtype = (cpurev & 0xFF000) >> 12;
+
+	switch (imxtype){
+	case MXC_CPU_MX6SOLO:
+		imxname = "imx6sx";	
+		break;
+	case MXC_CPU_MX6Q:
+		imxname = "imx6q";	
+		break;
+	case MXC_CPU_MX6DL:
+	default:
+		imxname = "imx6dl";	
+		break;	
+	}
+	setenv("soc", imxname);
+
 #ifdef CONFIG_CMD_BMODE
 	add_board_boot_modes(board_boot_modes);
 #endif
@@ -647,7 +673,7 @@ int board_init(void)
 
 int checkboard(void)
 {
-	puts("Board: edm_cf_imx6\n");
+	puts("Board: Wandboard\n");
 
 	return 0;
 }
