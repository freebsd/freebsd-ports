--- include/configs/cm_fx6.h.orig	2016-02-28 08:48:02 UTC
+++ include/configs/cm_fx6.h
@@ -21,6 +21,7 @@
 #define CONFIG_CMD_GREPENV
 
 /* MMC */
+#define CONFIG_SYS_MMC_MAX_DEVICE	3
 #define CONFIG_SYS_FSL_USDHC_NUM	3
 #define CONFIG_SYS_FSL_ESDHC_ADDR	USDHC2_BASE_ADDR
 
@@ -174,6 +175,8 @@
 
 /* NAND */
 #ifndef CONFIG_SPL_BUILD
+#define CONFIG_CMD_ELF
+#define CONFIG_API
 #define CONFIG_CMD_NAND
 #define CONFIG_SYS_NAND_BASE		0x40000000
 #define CONFIG_SYS_NAND_MAX_CHIPS	1
