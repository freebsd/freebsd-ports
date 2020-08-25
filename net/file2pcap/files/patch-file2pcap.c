--- file2pcap.c.orig	2019-11-21 15:44:46 UTC
+++ file2pcap.c
@@ -61,6 +61,8 @@ const int packetLen4 = (sizeof(SRC_ETHER)-1 + sizeof(D
 const int packetLen6 = (sizeof(SRC_ETHER)-1 + sizeof(DST_ETHER)-1 + sizeof(PROTO_ETHER6)-1 + sizeof(struct ip6_hdr) + sizeof(struct tcphdr));
 
 
+struct pcap_packet_header ph;
+unsigned short srcport, dstport;
 struct handover hoFtp;
 	
 
