--- src/backend.c.orig	Thu Apr 21 11:12:12 2005
+++ src/backend.c	Thu Apr 21 11:23:38 2005
@@ -158,6 +158,7 @@
 	} else devinfo.ip = NULL;
 	
 	/* Get the hardware/physical adress/ MAC */
+#ifndef __FreeBSD__
 	if (ioctl(fd, SIOCGIFHWADDR, &request) == 0) {
 		unsigned char hwaddr[6];
 		struct sockaddr *hwaddress = &request.ifr_hwaddr;
@@ -170,11 +171,17 @@
 #else
 			hwaddr[5], hwaddr[4], hwaddr[3], hwaddr[2], hwaddr[1], hwaddr[0]);
 #endif		
-	} else devinfo.hwaddr = NULL;
+	} else
+#endif
+		devinfo.hwaddr = NULL;
 	
 	/* Get the subnetmask */
 	if (ioctl(fd, SIOCGIFNETMASK, &request) == 0) {
+#ifndef __FreeBSD__
 		struct sockaddr_in *address = (struct sockaddr_in*)&request.ifr_netmask;
+#else
+		struct sockaddr_in *address = (struct sockaddr_in*)&request.ifr_addr;
+#endif
 		devinfo.netmask = g_strdup_printf("%s", inet_ntoa(address->sin_addr));
 	} else devinfo.netmask = NULL;
 
