--- include/configs/rpi.h.orig	2018-03-13 12:02:19 UTC
+++ include/configs/rpi.h
@@ -133,6 +133,7 @@
 
 #define BOOT_TARGET_DEVICES(func) \
 	func(MMC, mmc, 0) \
+	func(MMC, mmc, 1) \
 	func(USB, usb, 0) \
 	func(PXE, pxe, na) \
 	func(DHCP, dhcp, na)
