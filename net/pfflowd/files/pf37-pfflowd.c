--- pfflowd.c.orig	2008-05-28 12:28:08.000000000 -0700
+++ pfflowd.c	2008-05-28 12:28:29.000000000 -0700
@@ -231,7 +231,7 @@
 }
 
 static int
-send_netflow_v1(const struct pfsync_state *st, u_int n, int *flows_exp)
+send_netflow_v1(const struct _PFSYNC_STATE *st, u_int n, int *flows_exp)
 {
 	char now_s[64];
 	int i, j, offset, num_packets, err;
@@ -310,13 +310,13 @@
 		}
 
 		flw = (struct NF1_FLOW *)(packet + offset);
-		if (netflow_socket != -1 && st[i].packets[0][0] != 0) {
+		if (netflow_socket != -1 && st[i].packets[0] != 0) {
 			flw->src_ip = src.addr.v4.s_addr;
 			flw->dest_ip = dst.addr.v4.s_addr;
 			flw->src_port = src.port;
 			flw->dest_port = dst.port;
-			flw->flow_packets = st[i].packets[0][0];
-			flw->flow_octets = st[i].bytes[0][0];
+			flw->flow_packets = st[i].packets[0];
+			flw->flow_octets = st[i].bytes[0];
 			flw->flow_start = htonl(uptime_ms - creation);
 			flw->flow_finish = htonl(uptime_ms);
 			flw->protocol = st[i].proto;
@@ -326,13 +326,13 @@
 			hdr->flows++;
 		}
 		flw = (struct NF1_FLOW *)(packet + offset);
-		if (netflow_socket != -1 && st[i].packets[1][0] != 0) {
+		if (netflow_socket != -1 && st[i].packets[1] != 0) {
 			flw->src_ip = dst.addr.v4.s_addr;
 			flw->dest_ip = src.addr.v4.s_addr;
 			flw->src_port = dst.port;
 			flw->dest_port = src.port;
-			flw->flow_packets = st[i].packets[1][0];
-			flw->flow_octets = st[i].bytes[1][0];
+			flw->flow_packets = st[i].packets[1];
+			flw->flow_octets = st[i].bytes[1];
 			flw->flow_start = htonl(uptime_ms - creation);
 			flw->flow_finish = htonl(uptime_ms);
 			flw->protocol = st[i].proto;
@@ -344,10 +344,10 @@
 		flw = (struct NF1_FLOW *)(packet + offset);
 
 		if (verbose_flag) {
-			packets_out = ntohl(st[i].packets[0][0]);
-			packets_in = ntohl(st[i].packets[1][0]);
-			bytes_out = ntohl(st[i].bytes[0][0]);
-			bytes_in = ntohl(st[i].bytes[1][0]);
+			packets_out = ntohl(st[i].packets[0]);
+			packets_in = ntohl(st[i].packets[1]);
+			bytes_out = ntohl(st[i].bytes[0]);
+			bytes_in = ntohl(st[i].bytes[1]);
 
 			creation_tt = now - (creation / 1000);
 			localtime_r(&creation_tt, &creation_tm);
@@ -368,7 +368,6 @@
 				strlcat(dst_s, pbuf, sizeof(dst_s));
 			}
 
-			syslog(LOG_DEBUG, "IFACE %s", st[i].ifname); 
 			syslog(LOG_DEBUG, "GWY %s", rt_s); 
 			syslog(LOG_DEBUG, "FLOW proto %d direction %d", 
 			    st[i].proto, st[i].direction);
@@ -401,9 +400,8 @@
 	return (ntohs(hdr->flows));
 }
 
-
 static int
-send_netflow_v5(const struct pfsync_state *st, u_int n, int *flows_exp)
+send_netflow_v5(const struct _PFSYNC_STATE *st, u_int n, int *flows_exp)
 {
 	char now_s[64];
 	int i, j, offset, num_packets, err;
@@ -483,13 +481,13 @@
 		}
 
 		flw = (struct NF5_FLOW *)(packet + offset);
-		if (netflow_socket != -1 && st[i].packets[0][0] != 0) {
+		if (netflow_socket != -1 && st[i].packets[0] != 0) {
 			flw->src_ip = src.addr.v4.s_addr;
 			flw->dest_ip = dst.addr.v4.s_addr;
 			flw->src_port = src.port;
 			flw->dest_port = dst.port;
-			flw->flow_packets = st[i].packets[0][0];
-			flw->flow_octets = st[i].bytes[0][0];
+			flw->flow_packets = st[i].packets[0];
+			flw->flow_octets = st[i].bytes[0];
 			flw->flow_start = htonl(uptime_ms - creation);
 			flw->flow_finish = htonl(uptime_ms);
 			flw->tcp_flags = 0;
@@ -499,13 +497,13 @@
 			hdr->flows++;
 		}
 		flw = (struct NF5_FLOW *)(packet + offset);
-		if (netflow_socket != -1 && st[i].packets[1][0] != 0) {
+		if (netflow_socket != -1 && st[i].packets[1] != 0) {
 			flw->src_ip = dst.addr.v4.s_addr;
 			flw->dest_ip = src.addr.v4.s_addr;
 			flw->src_port = dst.port;
 			flw->dest_port = src.port;
-			flw->flow_packets = st[i].packets[1][0];
-			flw->flow_octets = st[i].bytes[1][0];
+			flw->flow_packets = st[i].packets[1];
+			flw->flow_octets = st[i].bytes[1];
 			flw->flow_start = htonl(uptime_ms - creation);
 			flw->flow_finish = htonl(uptime_ms);
 			flw->tcp_flags = 0;
@@ -517,10 +515,10 @@
 		flw = (struct NF5_FLOW *)(packet + offset);
 
 		if (verbose_flag) {
-			packets_out = ntohl(st[i].packets[0][0]);
-			packets_in = ntohl(st[i].packets[1][0]);
-			bytes_out = ntohl(st[i].bytes[0][0]);
-			bytes_in = ntohl(st[i].bytes[1][0]);
+			packets_out = ntohl(st[i].packets[0]);
+			packets_in = ntohl(st[i].packets[1]);
+			bytes_out = ntohl(st[i].bytes[0]);
+			bytes_in = ntohl(st[i].bytes[1]);
 
 			creation_tt = now - (creation / 1000);
 			localtime_r(&creation_tt, &creation_tm);
@@ -541,7 +539,6 @@
 				strlcat(dst_s, pbuf, sizeof(dst_s));
 			}
 
-			syslog(LOG_DEBUG, "IFACE %s", st[i].ifname); 
 			syslog(LOG_DEBUG, "GWY %s", rt_s); 
 			syslog(LOG_DEBUG, "FLOW proto %d direction %d", 
 			    st[i].proto, st[i].direction);
@@ -574,32 +571,6 @@
 	return (ntohs(hdr->flows));
 }
 
-static void
-send_flow(const struct pfsync_state *st, u_int n, int *flows_exp)
-{
-	int r = 0;
-
-	switch (export_version) {
-	case 1:
-		r = send_netflow_v1(st, n, flows_exp);
-		break;
-	case 5:
-		r = send_netflow_v5(st, n, flows_exp);
-		break;
-	default:
-		/* should never reach this point */
-		syslog(LOG_DEBUG, "Invalid netflow version, exiting");
-		exit(1);
-	}
-
-	if (r > 0) {
-		flows_exported += r;
-		if (verbose_flag)
-			syslog(LOG_DEBUG, "flows_exported = %d", *flows_exp);
-	}
-
-}
-
 /*
  * Per-packet callback function from libpcap. 
  */
@@ -608,8 +579,8 @@
     const u_char *pkt)
 {
 	const struct pfsync_header *ph = (const struct pfsync_header *)pkt;
-	const struct pfsync_state *st;
-	u_int64_t bytes[2], packets[2]; 
+	const struct _PFSYNC_STATE *st;
+	int r = 0;
 
 	if (phdr->caplen < PFSYNC_HDRLEN) {
 		syslog(LOG_WARNING, "Runt pfsync packet header");
@@ -632,56 +603,25 @@
 		return;
 	}
 
-	st = (const struct pfsync_state *)((const u_int8_t *)ph + sizeof(*ph));
+	st = (const struct _PFSYNC_STATE *)((const u_int8_t *)ph + sizeof(*ph));
 
-	/*
-	 * Check if any members of st->packets or st->bytes overflow
-	 * the 32 bit netflow counters, if so, create as many flow records 
-	 * that are needed to clear the counter. 
-	 */
-	 
-	 pf_state_counter_ntoh(st->packets[0],packets[0]); 
-	 pf_state_counter_ntoh(st->packets[1],packets[1]); 
-	 pf_state_counter_ntoh(st->bytes[0],bytes[0]); 
-	 pf_state_counter_ntoh(st->bytes[1],bytes[1]); 
-
-	 while (bytes[0] > 0 || bytes[1] > 0 || 
-	        packets[0] > 0 || packets[1] > 0) {
-		
-		struct pfsync_state st1;
-
-		memcpy(&st1, st, sizeof(st1));
-
-		if (bytes[0] > UINT_MAX) {
-			st1.bytes[0][0] = 0xffffffff;
-			bytes[0] -= MIN(bytes[0], 0xffffffff);
-		} else {
-			st1.bytes[0][0] = htonl(bytes[0]);
-			bytes[0] = 0;
-		}
-		if (bytes[1] > UINT_MAX) {
-			st1.bytes[1][0] = 0xffffffff;
-			bytes[1] -= MIN(bytes[1], 0xffffffff);
-		} else {
-			st1.bytes[1][0] = htonl(bytes[1]);
-			bytes[1] = 0;
-		}
-		if (packets[0] > UINT_MAX) {
-			st1.packets[0][0] = 0xffffffff;
-			packets[0] -= MIN(packets[0], 0xffffffff);
-		} else {
-			st1.packets[0][0] = htonl(packets[0]);
-			packets[0] = 0;
-		}
-		if (packets[1] > UINT_MAX) {
-			st1.packets[1][0] = 0xffffffff;
-			packets[1] -= MIN(packets[1], 0xffffffff);
-		} else {
-			st1.packets[1][0] = htonl(packets[1]);
-			packets[1] = 0;
-		}
+	switch (export_version) {
+	case 1:
+		r = send_netflow_v1(st, ph->count, &flows_exported);
+		break;
+	case 5:
+		r = send_netflow_v5(st, ph->count, &flows_exported);
+		break;
+	default:
+		/* should never reach this point */
+		syslog(LOG_DEBUG, "Invalid netflow version, exiting");
+		exit(1);
+	}
 
-		send_flow(&st1, ph->count, &flows_exported);
+	if (r > 0) {
+		flows_exported += r;
+		if (verbose_flag)
+			syslog(LOG_DEBUG, "flows_exported = %d", flows_exported);
 	}
 }
 
