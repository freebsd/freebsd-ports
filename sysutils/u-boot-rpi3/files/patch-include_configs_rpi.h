--- include/configs/rpi.h.orig	2018-07-09 14:24:14 UTC
+++ include/configs/rpi.h
@@ -69,6 +69,8 @@
 #define CONFIG_MISC_INIT_R
 #endif
 
+#define CONFIG_SYS_MMC_MAX_DEVICE	2
+
 /* Console configuration */
 #define CONFIG_SYS_CBSIZE		1024
 
@@ -150,6 +152,7 @@
 
 #define BOOT_TARGET_DEVICES(func) \
 	func(MMC, mmc, 0) \
+	func(MMC, mmc, 1) \
 	func(USB, usb, 0) \
 	func(PXE, pxe, na) \
 	func(DHCP, dhcp, na)
