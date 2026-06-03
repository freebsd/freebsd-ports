--- src/wps/wps_upnp.c.orig	2024-07-20 18:04:37 UTC
+++ src/wps/wps_upnp.c
@@ -963,7 +963,8 @@ int get_netif_info(const char *net_if, unsigned *ip_ad
 		goto fail;
 	}
 	os_memcpy(mac, req.ifr_addr.sa_data, 6);
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__APPLE__) \
+	|| defined(__DragonFly__)
 	if (eth_get(net_if, mac) < 0) {
 		wpa_printf(MSG_ERROR, "WPS UPnP: Failed to get MAC address");
 		goto fail;
