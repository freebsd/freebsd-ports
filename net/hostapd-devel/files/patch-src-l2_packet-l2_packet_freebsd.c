--- src/l2_packet/l2_packet_freebsd.c.orig	2022-03-14 01:42:11.000000000 -0700
+++ src/l2_packet/l2_packet_freebsd.c	2022-04-14 07:36:24.999713000 -0700
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
@@ -76,24 +79,27 @@
 {
 	struct l2_packet_data *l2 = eloop_ctx;
 	pcap_t *pcap = sock_ctx;
-	struct pcap_pkthdr hdr;
+	struct pcap_pkthdr *hdr;
 	const u_char *packet;
 	struct l2_ethhdr *ethhdr;
 	unsigned char *buf;
 	size_t len;
 
-	packet = pcap_next(pcap, &hdr);
+	if (pcap_next_ex(pcap, &hdr, &packet) == -1) {
+		wpa_printf(MSG_ERROR, "Error reading packet, has device disappeared?");
+		eloop_terminate();
+	}
 
-	if (!l2->rx_callback || !packet || hdr.caplen < sizeof(*ethhdr))
+	if (!l2->rx_callback || !packet || hdr->caplen < sizeof(*ethhdr))
 		return;
 
 	ethhdr = (struct l2_ethhdr *) packet;
 	if (l2->l2_hdr) {
 		buf = (unsigned char *) ethhdr;
-		len = hdr.caplen;
+		len = hdr->caplen;
 	} else {
 		buf = (unsigned char *) (ethhdr + 1);
-		len = hdr.caplen - sizeof(*ethhdr);
+		len = hdr->caplen - sizeof(*ethhdr);
 	}
 	l2->rx_callback(l2->rx_callback_ctx, ethhdr->h_source, buf, len);
 }
