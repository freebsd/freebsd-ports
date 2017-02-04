--- board/raspberrypi/rpi/lowlevel_init.S.orig	2017-01-09 16:57:05 UTC
+++ board/raspberrypi/rpi/lowlevel_init.S
@@ -9,10 +9,15 @@
 
 .align 8
 .global fw_dtb_pointer
-fw_dtb_pointer:
+
 #ifdef CONFIG_ARM64
+fw_dtb_pointer:
+	.dword 0x0
+.global reserve_memory
+reserve_memory:	
 	.dword 0x0
 #else
+fw_dtb_pointer:
 	.word 0x0
 #endif
 
@@ -28,6 +33,8 @@ save_boot_params:
 #ifdef CONFIG_ARM64
 	adr	x8, fw_dtb_pointer
 	str	x0, [x8]
+	adr	x8, reserve_memory
+	str	x1, [x8]
 #else
 	str	r2, fw_dtb_pointer
 #endif
