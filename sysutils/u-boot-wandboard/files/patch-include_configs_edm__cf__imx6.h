--- include/configs/edm_cf_imx6.h.orig	2014-06-12 07:50:48 UTC
+++ include/configs/edm_cf_imx6.h
@@ -338,4 +338,64 @@
 #define CONFIG_CMD_CACHE
 #endif
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+#define CONFIG_API
+#define CONFIG_CMD_ELF
+#define CONFIG_CMD_ENV_EXISTS
+#define CONFIG_EFI_PARTITION
+#define CONFIG_PREBOOT
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
+	"board=wandboard\0" \
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
+	  "env set fdt_file ${soc}-${board}.dtb" \
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
