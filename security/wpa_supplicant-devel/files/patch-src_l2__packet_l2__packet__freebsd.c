--- src/l2_packet/l2_packet_freebsd.c.orig	2023-09-05 10:38:47.000000000 -0700
+++ src/l2_packet/l2_packet_freebsd.c	2023-09-11 22:06:24.154851000 -0700
@@ -8,7 +8,10 @@
  */
 
 #include "includes.h"
-#if defined(__APPLE__) || defined(__GLIBC__)
+#if defined(__FreeBSD__) \
+ || defined(__DragonFly__) \
+ || defined(__APPLE__) \
+ || defined(__GLIBC__)
 #include <net/bpf.h>
 #endif /* __APPLE__ */
 #include <pcap.h>
@@ -82,7 +85,10 @@
 	unsigned char *buf;
 	size_t len;
 
-	packet = pcap_next(pcap, &hdr);
+	if (pcap_next_ex(pcap, &hdr, &packet) == -1) {
+		wpa_printf(MSG_ERROR, "Error reading packet, has device disappeared?");
+		eloop_terminate();
+	}
 
 	if (!l2->rx_callback || !packet || hdr.caplen < sizeof(*ethhdr))
 		return;
