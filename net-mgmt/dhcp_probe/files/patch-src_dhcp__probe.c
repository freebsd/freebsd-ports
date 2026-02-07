--- src/dhcp_probe.c.orig	2021-01-18 19:17:29 UTC
+++ src/dhcp_probe.c
@@ -70,7 +70,7 @@ pcap_dumper_t *pcap_dump_d = NULL;	/* libpcap - dump d
 enum dhcp_flavor_t packet_flavors[] = {BOOTP, DHCP_INIT, DHCP_SELECTING, DHCP_INIT_REBOOT, DHCP_REBINDING};
 
 char *ifname;
-struct ether_addr my_eaddr;
+struct libnet_ether_addr my_eaddr;
 
 int use_8021q = 0;
 int vlan_id = 0;
@@ -95,7 +95,7 @@ main(int argc, char **argv)
 	/* for libpcap */
 	struct bpf_program bpf_code;
 	int linktype;
-	char pcap_errbuf[PCAP_ERRBUF_SIZE], pcap_errbuf2[PCAP_ERRBUF_SIZE];
+	char pcap_errbuf[PCAP_ERRBUF_SIZE];
 
 	/* get progname = last component of argv[0] */
 	prog = strrchr(argv[0], '/');
@@ -416,7 +416,7 @@ main(int argc, char **argv)
 		*/
 		pcap_errbuf[0] = '\0'; /* so we can tell if a warning was produced on success */
 		if ((pd_template = pcap_open_live(ifname, snaplen, 0, 1, pcap_errbuf)) == NULL) {
-			report(LOG_ERR, "pcap_open_live %s: %s", ifname, pcap_errbuf2);
+			report(LOG_ERR, "pcap_open_live %s: %s", ifname, pcap_errbuf);
 			my_exit(1, 1, 1);
 		}
 		if (pcap_errbuf[0] != '\0')
@@ -485,8 +485,8 @@ main(int argc, char **argv)
 		   it's possible there's a server out there that does it wrong, and might therefore mistakenly
 		   send responses to ether_src.  So lets also listen promiscuously if ether_src != my_eaddr.
 		*/
-		if (bcmp(GetChaddr(), &my_eaddr, sizeof(struct ether_addr)) ||
-		    bcmp(GetEther_src(), &my_eaddr, sizeof(struct ether_addr)))
+		if (bcmp(GetChaddr(), &my_eaddr, sizeof(struct libnet_ether_addr)) ||
+		    bcmp(GetEther_src(), &my_eaddr, sizeof(struct libnet_ether_addr)))
 			promiscuous = 1;
 		else
 			promiscuous = 0;
@@ -775,9 +775,9 @@ process_response(u_char *user, const struct pcap_pkthd
    When we return, control returns to pcap_dispatch() so it can continue capturing packets.
 */
 
-	struct ether_header *ether_header; /* access ethernet header */
+	struct libnet_ethernet_hdr *ether_header; /* access ethernet header */
 	struct my_ether_vlan_header *my_ether_vlan_header; /* possibly access ethernet 802.1Q header */
-	struct ip *ip_header;				/* access ip header */
+	struct libnet_ipv4_hdr *ip_header;				/* access ip header */
 	bpf_u_int32 ether_len;		/* bpf_u_int32 from pcap.h */
 	struct udphdr *udp_header; /* access UDP header */
 	struct bootp *bootp_pkt; /* access bootp/dhcp packet */
@@ -787,10 +787,10 @@ process_response(u_char *user, const struct pcap_pkthd
 	int isLegalServer;			/* boolean */
 
 	/* fields parsed out from packet*/
-	struct ether_addr ether_dhost, ether_shost;
+	struct libnet_ether_addr ether_dhost, ether_shost;
 	uint16_t ether_type, ether_type_inner;
 	uint16_t ether_vid;
-	size_t ether_or_vlan_header_len; 	/* = sizeof(struct ether_header) or sizeof(struct my_ether_vlan_header) depending on response packet */
+	size_t ether_or_vlan_header_len; 	/* = sizeof(struct libnet_ethernet_hdr) or sizeof(struct my_ether_vlan_header) depending on response packet */
 	struct in_addr ip_src, ip_dst, yiaddr;
 	/* string versions of same */
 	char ether_dhost_str[MAX_ETHER_ADDR_STR], ether_shost_str[MAX_ETHER_ADDR_STR];
@@ -810,13 +810,13 @@ process_response(u_char *user, const struct pcap_pkthd
 		return;
 	}
 
-	if ((ether_len < sizeof(struct ether_header)) && (debug > 1)) {
+	if ((ether_len < sizeof(struct libnet_ethernet_hdr)) && (debug > 1)) {
 		report(LOG_WARNING, "interface %s, short packet (got %d bytes, smaller than an Ethernet header)", ifname, ether_len);
 		return;
 	}
 
 	/* we use ether_header to access the Ethernet header */
-	ether_header = (struct ether_header *) packet;
+	ether_header = (struct libnet_ethernet_hdr *) packet;
 
     /* we may use my_ether_vlan_header to access the Ethernet 801.Q header */
     my_ether_vlan_header = (struct my_ether_vlan_header *) packet;
@@ -835,7 +835,7 @@ process_response(u_char *user, const struct pcap_pkthd
 		report(LOG_DEBUG, "     interface %s, from ether %s to %s type %s", ifname, ether_shost_str, ether_dhost_str, ether_type_str);
 
 	if (ether_type == ETHERTYPE_IP) {
-		ether_or_vlan_header_len = sizeof(struct ether_header);
+		ether_or_vlan_header_len = sizeof(struct libnet_ethernet_hdr);
 
 	} else if (ether_type == ETHERTYPE_VLAN) {
 
@@ -880,13 +880,13 @@ process_response(u_char *user, const struct pcap_pkthd
 	   Else if the frame is tagged, ether_or_vlan_header_len is now set to the length of the ethernet VLAN header.
 	*/
 
-	if (ether_len < ether_or_vlan_header_len + sizeof(struct ip)) {
+	if (ether_len < ether_or_vlan_header_len + sizeof(struct libnet_ipv4_hdr)) {
 		report(LOG_WARNING, "interface %s, ether src %s type %s: short packet (got %d bytes, smaller than IP header in Ethernet)", ifname, ether_shost_str, ether_type_str, ether_len);
 		return;
 	}	
 
 	/* we use ip_header to access the IP header */
-	ip_header = (struct ip *) (packet + ether_or_vlan_header_len);
+	ip_header = (struct libnet_ipv4_hdr *) (packet + ether_or_vlan_header_len);
 
 	/* parse fields out of ip header for easier access */
 	bcopy(&(ip_header->ip_src), &ip_src, sizeof(ip_header->ip_src));
@@ -953,7 +953,7 @@ process_response(u_char *user, const struct pcap_pkthd
 
 	if (bcmp(bootp_pkt->bootp_chaddr, GetChaddr(), HLEN_ETHER)) {
 		if (debug > 10) {
-			struct ether_addr ether_tmp;
+			struct libnet_ether_addr ether_tmp;
 			char ether_tmp_str[MAX_ETHER_ADDR_STR];
 
 			/* create printable version of bootp_pkt->bootp_chaddr */
