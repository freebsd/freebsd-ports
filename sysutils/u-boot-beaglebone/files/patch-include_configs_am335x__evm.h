--- include/configs/am335x_evm.h.orig	2014-10-14 08:47:15 UTC
+++ include/configs/am335x_evm.h
@@ -479,4 +479,79 @@
 #endif
 #endif  /* NOR support */
 
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
+#define CONFIG_SYS_MMC_MAX_DEVICE 2
+#ifndef CONFIG_SYS_DCACHE_OFF
+#define CONFIG_CMD_CACHE
+#endif
+#endif
+
+/* Save the env to the fat partition. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_ENV_IS_NOWHERE
+#undef  CONFIG_ENV_IS_IN_NAND
+#undef  CONFIG_ENV_IS_IN_MMC
+#define CONFIG_ENV_IS_IN_FAT
+#define CONFIG_FAT_WRITE
+#define FAT_ENV_INTERFACE	"mmc"
+#define FAT_ENV_DEVICE_AND_PART	"0"
+#define FAT_ENV_FILE		"u-boot.env"
+#endif
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	"loadaddr=88000000\0" \
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
+	  "if test ${board_name} = A335BONE; then " \
+	      "env set fdt_file beaglebone.dtb; " \
+	  "elif test ${board_name} = A335BNLT; then " \
+	      "env set fdt_file beaglebone-black.dtb; " \
+	  "fi; " \
+	"\0" \
+	"SetupFatdev=" \
+	  "env exists fatdev || " \
+	    "fatsize ${fatdev:=mmc 0} ${bootfile} || " \
+	    "fatdev='mmc 1'; " \
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
+#endif
+
 #endif	/* ! __CONFIG_AM335X_EVM_H */
