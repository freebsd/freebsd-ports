# Backport FreeBSD broadcast patch
# https://github.com/Silicondust/libhdhomerun/commit/b0e5d5f5c8e2bf37dea34beb014e08ebb598ebf6

--- hdhomerun_discover.c.orig	2019-09-30 16:45:23 UTC
+++ hdhomerun_discover.c
@@ -183,7 +183,8 @@ static bool hdhomerun_discover_send(struct hdhomerun_d
 	unsigned int i;
 	for (i = 1; i < ds->sock_count; i++) {
 		struct hdhomerun_discover_sock_t *dss = &ds->socks[i];
-	
+		uint32_t send_ip = target_ip;
+
 		if (target_ip != 0xFFFFFFFF) {
 			if (dss->subnet_mask == 0) {
 				continue;
@@ -193,7 +194,18 @@ static bool hdhomerun_discover_send(struct hdhomerun_d
 			}
 		}
 
-		result |= hdhomerun_discover_send_internal(ds, dss, target_ip, device_type, device_id);
+#if defined(IP_ONESBCAST)
+		/* FreeBSD special handling - send subnet broadcast */
+		if (target_ip == 0xFFFFFFFF) {
+			send_ip = dss->local_ip | ~dss->subnet_mask;
+
+			if ((send_ip == 0x00000000) || (send_ip == 0xFFFFFFFF)) {
+				continue;
+			}
+		}
+#endif
+
+		result |= hdhomerun_discover_send_internal(ds, dss, send_ip, device_type, device_id);
 	}
 
 	/*
