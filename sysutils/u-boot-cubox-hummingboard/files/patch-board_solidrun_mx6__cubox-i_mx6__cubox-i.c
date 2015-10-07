--- board/solidrun/mx6_cubox-i/mx6_cubox-i.c.orig	2014-09-16 12:12:11 UTC
+++ board/solidrun/mx6_cubox-i/mx6_cubox-i.c
@@ -443,6 +443,7 @@ static void detect_board(void)
 		hb_cuboxi_ = 1;
 		config_sys_prompt = config_sys_prompt_hummingboard;
 	}
+
 }
 
 int board_early_init_f(void)
@@ -498,15 +499,19 @@ int board_init(void)
 }
 
 static char const *board_type = "uninitialized";
+static char const *fdt_board  = "uninitialized";
 
 int checkboard(void)
 {
+
 	if (hb_cuboxi_ == 0) {
 		puts("Board: MX6-CuBox-i\n");
 		board_type = "mx6-cubox-i";
+		fdt_board = "cubox-i";
 	} else {
 		puts("Board: MX6-HummingBoard\n");
 		board_type = "mx6-hummingboard";
+		fdt_board = "hummingboard";
 	}
 	return 0;
 }
@@ -521,10 +526,20 @@ static const struct boot_mode board_boot
 
 int board_late_init(void)
 {
+        const char *fdt_soc;
         int cpurev = get_cpu_rev();
         setenv("cpu",get_imx_type((cpurev & 0xFF000) >> 12));
         setenv("board",board_type);
 
+	if (((cpurev & 0xFF000) >> 12) == MXC_CPU_MX6Q)
+		fdt_soc = "imx6q";
+	else
+		fdt_soc = "imx6dl";
+	if (getenv("fdt_soc") == NULL)
+		setenv("fdt_soc", fdt_soc);
+	if (getenv("fdt_board") == NULL)
+		setenv("fdt_board", fdt_board);
+
 #ifdef CONFIG_CMD_BMODE
         add_board_boot_modes(board_boot_modes);
 #endif
