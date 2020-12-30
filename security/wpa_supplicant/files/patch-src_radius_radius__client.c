--- src/radius/radius_client.c.orig	2019-08-07 06:25:25.000000000 -0700
+++ src/radius/radius_client.c	2020-12-29 20:50:52.923004000 -0800
@@ -814,6 +814,7 @@
 {
 	struct radius_client_data *radius = eloop_ctx;
 	struct hostapd_radius_servers *conf = radius->conf;
+#pragma GCC diagnostic ignored "-Wvoid-pointer-to-enum-cast"
 	RadiusType msg_type = (RadiusType) sock_ctx;
 	int len, roundtrip;
 	unsigned char buf[3000];
