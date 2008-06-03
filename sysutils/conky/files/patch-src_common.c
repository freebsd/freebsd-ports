--- src/common.c.orig	2008-03-31 00:56:41.000000000 -0400
+++ src/common.c	2008-06-03 14:30:34.000000000 -0400
@@ -353,9 +353,11 @@
 	if (NEED(INFO_USERS)) {
 		update_users();
 	}
+#ifdef __linux__
 	if (NEED(INFO_GW)) {
 		update_gateway_info();
 	}
+#endif
 	if (NEED(INFO_DNS)) {
 		update_dns_data();
 	}
