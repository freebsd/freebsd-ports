--- src/wps/wps_upnp.c.orig	2020-06-08 14:40:50.402529000 -0700
+++ src/wps/wps_upnp.c	2020-06-08 15:48:08.294830000 -0700
@@ -861,7 +861,8 @@
 }
 
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+ || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #include <net/route.h>
 #include <net/if_dl.h>
@@ -950,7 +951,11 @@
 				   errno, strerror(errno));
 			goto fail;
 		}
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+		addr = (struct sockaddr_in *) &req.ifr_addr;
+#else
 		addr = (struct sockaddr_in *) &req.ifr_netmask;
+#endif
 		netmask->s_addr = addr->sin_addr.s_addr;
 	}
 
@@ -962,7 +967,8 @@
 		goto fail;
 	}
 	os_memcpy(mac, req.ifr_addr.sa_data, 6);
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+   || defined(__DragonFly__)
 	if (eth_get(net_if, mac) < 0) {
 		wpa_printf(MSG_ERROR, "WPS UPnP: Failed to get MAC address");
 		goto fail;
