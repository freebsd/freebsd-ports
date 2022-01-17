--- src/wps/wps_upnp.c.orig	2021-03-16 13:50:10.000000000 -0700
+++ src/wps/wps_upnp.c	2021-03-18 12:49:19.537874000 -0700
@@ -963,7 +963,8 @@
 		goto fail;
 	}
 	os_memcpy(mac, req.ifr_addr.sa_data, 6);
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__APPLE__) \
+	|| defined(__DragonFly__)
 	if (eth_get(net_if, mac) < 0) {
 		wpa_printf(MSG_ERROR, "WPS UPnP: Failed to get MAC address");
 		goto fail;
