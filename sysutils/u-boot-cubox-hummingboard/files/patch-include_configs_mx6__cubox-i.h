--- include/configs/mx6_cubox-i.h.orig	2014-09-16 12:12:11 UTC
+++ include/configs/mx6_cubox-i.h
@@ -363,4 +363,65 @@ extern char *config_sys_prompt;
 #define CONFIG_CMD_CACHE
 #endif
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+#ifndef CONFIG_SYS_TEXT_BASE
+#define CONFIG_SYS_TEXT_BASE		0x17800000
+#endif
+
+#define CONFIG_API
+#define CONFIG_CMD_ELF
+#define CONFIG_CMD_ENV_EXISTS
+
+#undef  CONFIG_CMD_BMODE
+#define CONFIG_CMD_BMODE
+
+#undef  CONFIG_SYS_MMC_MAX_DEVICE
+#define CONFIG_SYS_MMC_MAX_DEVICE CONFIG_SYS_FSL_USDHC_NUM
+
+#undef  CONFIG_LOADADDR
+#define CONFIG_LOADADDR 	0x11000000
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	"loadaddr=0x11000000\0" \
+	\
+	"Fatboot=" \
+	  "env exists loaderdev || env set loaderdev ${fatdev}; " \
+	  "env exists UserFatboot && run UserFatboot; " \
+	  "echo Booting from: ${fatdev} ${bootfile}; " \
+	  "fatload ${fatdev} ${loadaddr} ${bootfile} && bootelf; " \
+	"\0" \
+	"Netboot=" \
+	  "env exists loaderdev || env set loaderdev net; " \
+	  "env exists UserNetboot && run UserNetboot; " \
+	  "dhcp ${loadaddr} ${bootfile} && bootelf; " \
+	"\0" \
+	"Preboot=" \
+	  "env exists bootfile || bootfile=ubldr; " \
+	  "env exists uenv_file || uenv_file=uEnv.txt; " \
+	  "env exists SetupFdtfile && run SetupFdtfile; " \
+	  "env exists SetupFatdev && run SetupFatdev; " \
+	  "env exists SetupUenv && run SetupUenv; " \
+	  "env exists UserPreboot && run UserPreboot; " \
+	"\0" \
+	"SetupFdtfile=" \
+	  "env exists fdt_file || env set fdt_file ${fdt_soc}-${fdt_board}.dtb; " \
+	"\0" \
+	"SetupFatdev=" \
+	  "env exists fatdev || fatdev='mmc 0'; " \
+	"\0" \
+	"SetupUenv=" \
+	  "fatload ${fatdev} ${loadaddr} ${uenv_file} && " \
+	    "env import -t ${loadaddr} ${filesize}; " \
+	"\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND	"run Fatboot"
+#undef  CONFIG_PREBOOT
+#define CONFIG_PREBOOT		"run Preboot"
+
 #endif			       /* __CONFIG_H * */
