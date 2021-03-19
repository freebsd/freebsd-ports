--- src/radius/radius_client.c.orig	2019-08-07 06:25:25.000000000 -0700
+++ src/radius/radius_client.c	2021-01-11 08:35:20.860835000 -0800
@@ -814,6 +814,9 @@
 {
 	struct radius_client_data *radius = eloop_ctx;
 	struct hostapd_radius_servers *conf = radius->conf;
+#if defined(__clang_major__) && __clang_major__ >= 11
+#pragma GCC diagnostic ignored "-Wvoid-pointer-to-enum-cast"
+#endif
 	RadiusType msg_type = (RadiusType) sock_ctx;
 	int len, roundtrip;
 	unsigned char buf[3000];
