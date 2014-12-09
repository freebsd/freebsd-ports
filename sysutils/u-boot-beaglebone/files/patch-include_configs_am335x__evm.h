--- include/configs/am335x_evm.h.orig	2014-10-14 08:47:15 UTC
+++ include/configs/am335x_evm.h
@@ -479,4 +479,82 @@
 #endif
 #endif  /* NOR support */
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+/* No watchdog.  (Why?) */
+#undef  CONFIG_HW_WATCHDOG
+#undef  CONFIG_OMAP_WATCHDOG
+#undef  CONFIG_SPL_WATCHDOG_SUPPORT
+
+/* Add the API and ELF features needed for ubldr. */
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_API
+#define CONFIG_CMD_ELF
+#define CONFIG_CMD_ENV_EXISTS
+#define CONFIG_EFI_PARTITION
+#define CONFIG_PREBOOT
+#define CONFIG_SYS_MMC_MAX_DEVICE 2
+#endif
+
+/* SPL loads bb-uboot.img. */
+#ifdef CONFIG_SPL_BUILD
+#undef  CONFIG_SPL_FAT_LOAD_PAYLOAD_NAME
+#define CONFIG_SPL_FAT_LOAD_PAYLOAD_NAME	"bb-uboot.img"
+#endif
+
+/* Save the env to the fat partition. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_ENV_IS_NOWHERE
+#undef  CONFIG_ENV_IS_IN_NAND
+#define CONFIG_ENV_IS_IN_FAT
+#define CONFIG_FAT_WRITE
+#define FAT_ENV_INTERFACE	"mmc"
+#define FAT_ENV_DEVICE_AND_PART	"0"
+#define FAT_ENV_FILE		"uboot.env"
+#endif
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	"bootfile=bbubldr\0" \
+	"fdt_file=undefined\0" \
+	"fatdev=mmc 0:1\0" \
+	"loadaddr=0x88000000\0" \
+	"loaderdev=disk\0" \
+	"uenv_file=bb-uEnv.txt\0" \
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
+	"setfdt=" \
+	  "if test ${board_name} = A335BONE; then " \
+	      "env set fdt_file bbone.dtb; " \
+	  "elif test ${board_name} = A335BNLT; then " \
+	      "env set fdt_file bboneblk.dtb; " \
+	  "else " \
+	       "echo WARNING: Could not determine device tree to use; " \
+	  "fi; " \
+	"\0" \
+	"uenv_import=" \
+	  "fatload ${fatdev} ${loadaddr} ${uenv_file} && " \
+	    "env import -t ${loadaddr} ${filesize}; " \
+	"\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND "run fatboot"
+#endif
+
 #endif	/* ! __CONFIG_AM335X_EVM_H */
