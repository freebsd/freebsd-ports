--- tcptraceroute.c.orig	Tue Oct  7 16:04:50 2003
+++ tcptraceroute.c	Tue Oct  7 16:05:22 2003
@@ -391,9 +391,9 @@
 void usage(void)
 {
 	printf("\n%s\n%s\n", VERSION, BANNER);
-    fatal("Usage: %s [-nNFSAE] [-i <interface>] [-f <first ttl>]
-       [-l <packet length>] [-q <number of queries>] [-t <tos>]
-       [-m <max ttl>] [-pP] <source port>] [-s <source address>]
+    fatal("Usage: %s [-nNFSAE] [-i <interface>] [-f <first ttl>] \
+       [-l <packet length>] [-q <number of queries>] [-t <tos>] \
+       [-m <max ttl>] [-pP] <source port>] [-s <source address>] \
        [-w <wait time>] <host> [destination port] [packet length]\n\n", name);
 }
 
@@ -1182,8 +1182,8 @@
 	if (! (pcap = pcap_open_live(device, offset + SNAPLEN, 0, 10, errbuf)))
 		fatal("pcap_open_live failed: %s", errbuf);
 
-	safe_snprintf(filter, TEXTSIZE, "
-		(tcp and src host %s and src port %d and dst host %s)
+	safe_snprintf(filter, TEXTSIZE, " \
+		(tcp and src host %s and src port %d and dst host %s) \
 		or ((icmp[0] == 11 or icmp[0] == 3) and dst host %s)",
 			iptos(dst_ip), dst_prt, iptos(src_ip), iptos(src_ip));
 
