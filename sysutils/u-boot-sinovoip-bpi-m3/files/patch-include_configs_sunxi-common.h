--- include/configs/sunxi-common.h.orig	2016-05-16 11:40:32.000000000 -0300
+++ include/configs/sunxi-common.h	2016-07-07 17:00:25.673890000 -0300
@@ -513,4 +513,75 @@
 #define CONFIG_EXTRA_ENV_SETTINGS
 #endif
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+/* Add the API and ELF features needed for ubldr. */
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_API
+#ifndef CONFIG_CMD_ELF
+#define CONFIG_CMD_ELF
+#endif
+#ifndef CONFIG_CMD_ENV_EXISTS
+#define CONFIG_CMD_ENV_EXISTS
+#endif
+#define CONFIG_EFI_PARTITION
+#endif
+
+/* Turn off dcache. */
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_SYS_DCACHE_OFF
+#define CONFIG_CMD_CACHE
+#endif
+
+/* Save the env to the fat partition. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_ENV_IS_NOWHERE
+#undef  CONFIG_ENV_IS_IN_NAND
+#undef  CONFIG_ENV_IS_IN_MMC
+#undef  CONFIG_ENV_IS_IN_SPI_FLASH
+#define CONFIG_ENV_IS_IN_FAT
+#define CONFIG_FAT_WRITE
+#define CONFIG_SYS_MMC_MAX_DEVICE	4
+#define FAT_ENV_INTERFACE		"mmc"
+#define FAT_ENV_DEVICE_AND_PART		"0:1"
+#define FAT_ENV_FILE			"u-boot.env"
+#endif
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	MEM_LAYOUT_ENV_SETTINGS \
+	CONSOLE_STDOUT_SETTINGS \
+	"stdin=serial,usbkbd\0" \
+	"fdtfile=%%MODEL%%.dtb\0" \
+	"console=ttyS0,115200\0" \
+	"Fatboot=" \
+	  "env exists loaderdev || env set loaderdev ${fatdev}; " \
+	  "env exists UserFatboot && run UserFatboot; " \
+	  "echo Booting from: ${fatdev} ${bootfile}; " \
+	  "fatload ${fatdev} ${kernel_addr_r} ${bootfile} && bootelf; " \
+	"\0" \
+	"Netboot=" \
+	  "env exists loaderdev || env set loaderdev net; " \
+	  "env exists UserNetboot && run UserNetboot; " \
+	  "dhcp ${kernel_addr_r} ${bootfile} && bootelf; " \
+	"\0" \
+	"preboot=usb start; " \
+	  "env exists bootfile || env set bootfile ubldr; " \
+	  "env exists SetupFatdev && run SetupFatdev; " \
+	  "env exists UserPreboot && run UserPreboot; " \
+	"\0" \
+	"SetupFatdev=" \
+	  "env exists fatdev || env set fatdev 'mmc 0'; " \
+	"\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND	"run Fatboot"
+#undef  CONFIG_PREBOOT
+#define CONFIG_PREBOOT		"run preboot"
+#endif
+
 #endif /* _SUNXI_COMMON_CONFIG_H */
