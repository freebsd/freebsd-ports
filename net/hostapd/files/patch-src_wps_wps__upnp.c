--- src/wps/wps_upnp.c.orig	2015-03-15 17:30:39 UTC
+++ src/wps/wps_upnp.c
@@ -837,7 +837,7 @@ fail:
 }
 
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #include <net/route.h>
 #include <net/if_dl.h>
@@ -924,7 +924,7 @@ int get_netif_info(const char *net_if, u
 		goto fail;
 	}
 	os_memcpy(mac, req.ifr_addr.sa_data, 6);
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 	if (eth_get(net_if, mac) < 0) {
 		wpa_printf(MSG_ERROR, "WPS UPnP: Failed to get MAC address");
 		goto fail;
