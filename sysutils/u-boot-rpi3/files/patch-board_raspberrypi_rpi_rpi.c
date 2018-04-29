--- board/raspberrypi/rpi/rpi.c.orig	2018-03-13 12:02:19 UTC
+++ board/raspberrypi/rpi/rpi.c
@@ -273,6 +273,10 @@ static void set_fdt_addr(void)
 		return;
 
 	env_set_hex("fdt_addr", fw_dtb_pointer);
+	/*
+	 * Set fdtcontroladdr too so it can be picked up by boot script
+	 */
+	env_set_hex("fdtcontroladdr", fw_dtb_pointer);
 }
 
 /*
