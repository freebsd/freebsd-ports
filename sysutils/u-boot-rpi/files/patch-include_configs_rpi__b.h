--- include/configs/rpi_b.h.orig	2012-11-28 01:28:06 UTC
+++ include/configs/rpi_b.h
@@ -183,4 +183,57 @@
 #define CONFIG_INITRD_TAG
 #define CONFIG_CMD_BMP
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+//#define CONFIG_API
+//#define CONFIG_CMD_ELF
+#define CONFIG_CMD_ENV_EXISTS
+#define CONFIG_EFI_PARTITION
+#define CONFIG_PREBOOT
+
+/* Save the env to the fat partition. */
+#undef  CONFIG_ENV_IS_NOWHERE
+#define CONFIG_ENV_IS_IN_FAT
+#define CONFIG_FAT_WRITE
+#define FAT_ENV_INTERFACE	"mmc"
+#define FAT_ENV_DEVICE		0
+#define FAT_ENV_PART		1
+#define FAT_ENV_FILE		"uboot.env"
+#define CONFIG_CMD_SAVEENV
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	"bootfile=ubldr\0" \
+	"fatdev=mmc 0:1\0" \
+	"loaderdev=disk\0" \
+	"stdin=serial\0" \
+	"stderr=serial,lcd\0" \
+	"stdout=serial,lcd\0" \
+	"uenv_file=uEnv.txt\0" \
+	\
+	"fatboot=" \
+	  "env exists user_fatboot && run user_fatboot; " \
+	  "fatload ${fatdev} ${loadaddr} ${bootfile} && bootelf; " \
+	"\0" \
+	"netboot=" \
+	  "env exists ethact || usb start; " \
+	  "env exists user_netboot && run user_netboot; " \
+	  "dhcp ${loadaddr} ${bootfile} && bootelf; " \
+	"\0" \
+	"preboot=" \
+	  "fdt addr 0x100; " \
+	  "env exists uenv_import && run uenv_import; " \
+	  "env exists user_preboot && run user_preboot; " \
+	"\0" \
+	"uenv_import=" \
+	  "fatload ${fatdev} ${loadaddr} ${uenv_file} && " \
+	    "env import -t ${loadaddr} ${filesize}; " \
+	"\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND "run fatboot"
+
 #endif
