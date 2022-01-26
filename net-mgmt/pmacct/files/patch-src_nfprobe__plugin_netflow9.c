--- src/nfprobe_plugin/netflow9.c.orig	2021-11-05 15:03:23 UTC
+++ src/nfprobe_plugin/netflow9.c
@@ -2232,7 +2232,7 @@ send_netflow_v9(struct FLOW **flows, int num_flows, in
 
 		/* Refresh template headers if we need to */
 		if (nf9_pkts_until_template <= 0) {
-			u_int16_t flows = 0, tot_len = 0;
+			u_int16_t flows = 0, tot_len  __attribute__((unused)) = 0;
 
 			memcpy(packet + offset, &v4_template, v4_template.tot_len);
 			offset += v4_template.tot_len;
