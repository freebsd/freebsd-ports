--- src/netspeed.c.orig	Sat Feb  8 23:21:50 2003
+++ src/netspeed.c	Sat Feb  8 23:22:42 2003
@@ -20,6 +20,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -260,6 +261,7 @@
 		devinfo->ip = NULL;
 /* Get the hardware/physical adress/ MAC
  */
+#ifndef __FreeBSD__
 	if (ioctl(fd, SIOCGIFHWADDR, &request) == 0)
 	{
 		unsigned char hwaddr[6];
@@ -275,12 +277,17 @@
 #endif		
 }
 	else
+#endif
 		devinfo->hwaddr = NULL;
 /* Get the subnetmask
  */
 	if (ioctl(fd, SIOCGIFNETMASK, &request) == 0)
 	{
+#ifdef __FreeBSD__
+		struct sockaddr_in *address = (struct sockaddr_in*)&request.ifr_addr;
+#else
 		struct sockaddr_in *address = (struct sockaddr_in*)&request.ifr_netmask;
+#endif
 		devinfo->netmask = g_strdup_printf("%s", inet_ntoa(address->sin_addr));
 	}
 	else
