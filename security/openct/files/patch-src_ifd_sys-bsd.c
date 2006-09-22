--- src/ifd/sys-bsd.c.orig	Fri Sep 22 10:25:11 2006
+++ src/ifd/sys-bsd.c	Fri Sep 22 10:25:34 2006
@@ -380,7 +380,7 @@
 				 "usb:/dev/%s", device_info.udi_devnames[0]);
 #endif	/* __OpenBSD__ */
 
-			ifd_(driver, typedev, -1);
+			ifd_spawn_handler(driver, typedev, -1);
 		}
 		close(controller_fd);
 	}
