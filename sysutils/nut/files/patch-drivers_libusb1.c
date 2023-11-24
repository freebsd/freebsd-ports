--- drivers/libusb1.c.orig	2023-11-24 07:19:04.377537000 -0800
+++ drivers/libusb1.c	2023-11-24 07:20:06.065188000 -0800
@@ -263,14 +263,7 @@
 			libusb_free_device_list(devlist, 1);
 			fatal_with_errno(EXIT_FAILURE, "Out of memory");
 		}
-		if (bus_num > 0) {
-			sprintf(curDevice->Bus, "%03d", bus_num);
-		} else {
-			upsdebugx(1, "%s: invalid libusb bus number %i",
-				__func__, bus_num);
-			free(curDevice->Bus);
-			curDevice->Bus = NULL;
-		}
+		sprintf(curDevice->Bus, "%03d", bus_num);
 
 		device_addr = libusb_get_device_address(device);
 		curDevice->Device = (char *)malloc(4);
