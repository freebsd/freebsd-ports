--- include/configs/rpi-common.h.orig	2016-01-12 14:06:54 UTC
+++ include/configs/rpi-common.h
@@ -182,4 +182,55 @@
 
 #define CONFIG_BOOTDELAY 2
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+#define CONFIG_API
+#define CONFIG_EFI_PARTITION
+#define CONFIG_PREBOOT
+
+#define CONFIG_SYS_MMC_MAX_DEVICE 1
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	ENV_MEM_LAYOUT_SETTINGS \
+	"stdin=serial,lcd\0" \
+	"stderr=serial,lcd\0" \
+	"stdout=serial,lcd\0" \
+	\
+	"Fatboot=" \
+	  "env exists bootfile || bootfile=ubldr.bin; " \
+	  "env exists loaderdev || env set loaderdev ${fatdev}; " \
+	  "test ${loaderdev} = net && env exists SetupNetconfig && run SetupNetconfig; " \
+	  "echo Booting from: ${fatdev} ${bootfile}; " \
+	  "fatload ${fatdev} ${loadaddr} ${bootfile} && bootelf || go ${loadaddr}; " \
+	"\0" \
+	"Preboot=" \
+	  "fdt addr 0x100; " \
+	  "env exists uenv_file || uenv_file=uEnv.txt; " \
+	  "env exists SetupFatdev && run SetupFatdev; " \
+	  "env exists SetupUenv && run SetupUenv; " \
+	  "env exists UserPreboot && run UserPreboot; " \
+	"\0" \
+	"SetupFatdev=" \
+	  "env exists fatdev || fatdev='mmc 0'; " \
+	"\0" \
+	"SetupNetconfig=" \
+	 "env exists ethact || usb start; " \
+	 "env exists UserNetconfig && run UserNetconfig; " \
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
+#define CONFIG_CMD_CACHE
+
 #endif
