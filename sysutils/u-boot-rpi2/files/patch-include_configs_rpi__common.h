--- include/configs/rpi-common.h.orig	2015-04-13 11:53:03.000000000 -0300
+++ include/configs/rpi-common.h
@@ -183,4 +183,63 @@
 
 #define CONFIG_BOOTDELAY 2
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+/* Add the API and ELF features needed for ubldr. */
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_API
+#define CONFIG_CMD_ELF
+#define CONFIG_CMD_ENV_EXISTS
+#define CONFIG_EFI_PARTITION
+#endif
+
+/* Turn off dcache. */
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_SYS_DCACHE_OFF
+#define CONFIG_CMD_CACHE
+#endif
+
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_SYS_MMC_MAX_DEVICE	1
+#endif
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	ENV_DEVICE_SETTINGS \
+	"loadaddr=0x02000000\0" \
+	"scriptaddr=0x00000000\0" \
+	"pxefile_addr_r=0x00100000\0" \
+	"kernel_addr_r=0x01000000\0" \
+	"ramdisk_addr_r=0x02100000\0" \
+	"Fatboot=" \
+	  "env exists loaderdev || env set loaderdev ${fatdev}; " \
+	  "env exists UserFatboot && run UserFatboot; " \
+	  "echo Booting from: ${fatdev} ${bootfile}; " \
+	  "fatload ${fatdev} ${loadaddr} ${bootfile} && bootelf ${loadaddr}; " \
+	"\0" \
+	"Netboot=" \
+	  "env exists ethact || usb start; " \
+	  "env exists loaderdev || env set loaderdev net; " \
+	  "env exists UserNetboot && run UserNetboot; " \
+	  "dhcp ${loadaddr} ${bootfile} && bootelf ${loadaddr}; " \
+	"\0" \
+	"preboot=" \
+	  "fdt addr 0x100; " \
+	  "env exists bootfile || env set bootfile ubldr; " \
+	  "env exists SetupFatdev && run SetupFatdev; " \
+	  "env exists UserPreboot && run UserPreboot; " \
+	"\0" \
+	"SetupFatdev=" \
+	  "env exists fatdev || env set fatdev 'mmc 0'; " \
+	"\0"
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND     "run Fatboot"
+#undef  CONFIG_PREBOOT
+#define CONFIG_PREBOOT         "run preboot"
+#endif
+
 #endif
