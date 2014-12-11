--- include/configs/edm_cf_imx6.h.orig	2014-08-14 14:51:10 UTC
+++ include/configs/edm_cf_imx6.h
@@ -338,4 +338,54 @@
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
+	"boardname=wandboard\0" \
+	"bootfile=ubldr\0" \
+	"fatdev=mmc 0:1\0" \
+	"loaderdev=disk\0" \
+	"uenv_file=uEnv.txt\0" \
+	\
+	"fatboot=" \
+	  "env exists user_fatboot && run user_fatboot; " \
+	  "fatload ${fatdev} ${loadaddr} ${bootfile} && bootelf; " \
+	"\0" \
+	"netboot=" \
+	  "env exists user_netboot && run user_netboot; " \
+	  "dhcp ${loadaddr} ${bootfile} && bootelf; " \
+	"\0" \
+	"preboot=" \
+	  "env exists setfdt && run setfdt; " \
+	  "env exists uenv_import && run uenv_import; " \
+	  "env exists user_preboot && run user_preboot; " \
+	"\0" \
+	"setfdt=env set fdt_file ${imxname}-${boardname}.dtb\0" \
+	"uenv_import=" \
+	  "fatload ${fatdev} ${loadaddr} ${uenv_file} && " \
+	    "env import -t ${loadaddr} ${filesize}; " \
+	"\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND "run fatboot"
+
 #endif			       /* __CONFIG_H * */
