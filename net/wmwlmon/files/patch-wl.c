--- ./wl.c.orig	2006-05-10 06:57:57.000000000 +0300
+++ ./wl.c	2008-05-10 11:03:57.000000000 +0300
@@ -261,7 +261,8 @@
 		uint8_t *vp;
 		sr = (struct ieee80211req_scan_result *)cp;
 		vp = (u_int8_t *)(sr + 1);
-		strlcpy(network_id, vp, sr->isr_ssid_len + 1);
+		memcpy(network_id, vp, sr->isr_ssid_len);
+		network_id[sizeof(network_id) - 1] = '\0';
 		if (!strcmp(network_id, network))
 			return (sr->isr_rssi);
 		cp += sr->isr_len;

