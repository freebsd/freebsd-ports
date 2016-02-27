--- include/configs/cm_fx6.h.orig	2016-02-27 13:29:39 UTC
+++ include/configs/cm_fx6.h
@@ -174,6 +174,9 @@
 
 /* NAND */
 #ifndef CONFIG_SPL_BUILD
+#define CONFIG_CMD_ELF
+#define CONFIG_SYS_MMC_MAX_DEVICE 4
+#define CONFIG_API
 #define CONFIG_CMD_NAND
 #define CONFIG_SYS_NAND_BASE		0x40000000
 #define CONFIG_SYS_NAND_MAX_CHIPS	1
