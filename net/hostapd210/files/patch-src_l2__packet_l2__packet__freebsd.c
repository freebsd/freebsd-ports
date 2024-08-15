--- src/l2_packet/l2_packet_freebsd.c.orig	2022-01-16 12:51:29.000000000 -0800
+++ src/l2_packet/l2_packet_freebsd.c	2023-09-11 22:21:12.054042000 -0700
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
@@ -20,6 +23,7 @@
 #include <sys/sysctl.h>
 #endif /* __sun__ */
 
+#include <net/ethernet.h>
 #include <net/if.h>
 #include <net/if_dl.h>
 #include <net/route.h>
@@ -76,24 +80,33 @@
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
+		packet = NULL;
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
+		/* handle 8021Q encapsulated frames */
+		if (ethhdr->h_proto == htons(ETH_P_8021Q)) {
+			buf += ETHER_VLAN_ENCAP_LEN;
+			len -= ETHER_VLAN_ENCAP_LEN;
+		}
 	}
 	l2->rx_callback(l2->rx_callback_ctx, ethhdr->h_source, buf, len);
 }
@@ -122,10 +135,10 @@
 	os_snprintf(pcap_filter, sizeof(pcap_filter),
 		    "not ether src " MACSTR " and "
 		    "( ether dst " MACSTR " or ether dst " MACSTR " ) and "
-		    "ether proto 0x%x",
+		    "( ether proto 0x%x or ( vlan 0 and ether proto 0x%x ) )",
 		    MAC2STR(l2->own_addr), /* do not receive own packets */
 		    MAC2STR(l2->own_addr), MAC2STR(pae_group_addr),
-		    protocol);
+		    protocol, protocol);
 	if (pcap_compile(l2->pcap, &pcap_fp, pcap_filter, 1, pcap_netp) < 0) {
 		fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(l2->pcap));
 		return -1;
