--- src/dhcp_probe.c.orig	2015-01-03 11:16:23.000000000 -0500
+++ src/dhcp_probe.c	2015-01-17 11:44:33.000000000 -0500
@@ -69,7 +69,7 @@
 enum dhcp_flavor_t packet_flavors[] = {BOOTP, DHCP_INIT, DHCP_SELECTING, DHCP_INIT_REBOOT, DHCP_REBINDING};
 
 char *ifname;
-struct ether_addr my_eaddr;
+struct libnet_ether_addr my_eaddr;
 
 int use_8021q = 0;
 int vlan_id = 0;
@@ -96,7 +96,7 @@
 	bpf_u_int32 netnumber,  netmask;
 	struct bpf_program bpf_code;
 	int linktype;
-	char pcap_errbuf[PCAP_ERRBUF_SIZE], pcap_errbuf2[PCAP_ERRBUF_SIZE];
+	char pcap_errbuf[PCAP_ERRBUF_SIZE];
 
 	/* for libnet */
 	char libnet_errbuf[LIBNET_ERRBUF_SIZE];
@@ -228,6 +228,7 @@
 		/* ignore SIGHUP */
 		sigemptyset(&sa.sa_mask);
 		sa.sa_handler = SIG_IGN;
+		sa.sa_flags = 0;
 		if (sigaction(SIGHUP, &sa, NULL) < 0) {
 			report(LOG_ERR, "sigaction: %s", get_errmsg());
 			my_exit(1, 0, 1);
@@ -236,6 +237,7 @@
 	/* ignore SIGUSR1 */
 	sigemptyset(&sa.sa_mask);
 	sa.sa_handler = SIG_IGN;
+	sa.sa_flags = 0;
 	if (sigaction(SIGUSR1, &sa, NULL) < 0) {
 		report(LOG_ERR, "sigaction: %s", get_errmsg());
 		my_exit(1, 0, 1);
@@ -243,12 +245,12 @@
 	/* ignore SIGUSR2 */
 	sigemptyset(&sa.sa_mask);
 	sa.sa_handler = SIG_IGN;
+	sa.sa_flags = 0;
 	if (sigaction(SIGUSR2, &sa, NULL) < 0) {
 		report(LOG_ERR, "sigaction: %s", get_errmsg());
 		my_exit(1, 0, 1);
 	}
 
-
 	/* write pid file as soon as possible after (possibly) forking */
 	if ((pid_fp = open_for_writing(pid_file)) == NULL) {
 		report(LOG_ERR, "could not open pid file %s for writing", pid_file);
@@ -401,7 +403,7 @@
 		*/
 		pcap_errbuf[0] = '\0'; /* so we can tell if a warning was produced on success */
 		if ((pd_template = pcap_open_live(ifname, snaplen, 0, 1, pcap_errbuf)) == NULL) {
-			report(LOG_ERR, "pcap_open_live %s: %s", ifname, pcap_errbuf2);
+			report(LOG_ERR, "pcap_open_live %s: %s", ifname, pcap_errbuf);
 			my_exit(1, 1, 1);
 		}
 		if (pcap_errbuf[0] != '\0')
@@ -470,8 +472,8 @@
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
@@ -699,8 +701,8 @@
    When we return, control returns to pcap_dispatch() so it can continue capturing packets.
 */
 
-	struct ether_header *ether_header; /* access ethernet header */
-	struct ip *ip_header;				/* access ip header */
+	struct libnet_ethernet_hdr *ether_header; /* access ethernet header */
+	struct libnet_ipv4_hdr *ip_header;				/* access ip header */
 	bpf_u_int32 ether_len;		/* bpf_u_int32 from pcap.h */
 	struct udphdr *udp_header; /* access UDP header */
 	struct bootp *bootp_pkt; /* access bootp/dhcp packet */
@@ -710,7 +712,7 @@
 	int isLegalServer;			/* boolean */
 
 	/* fields parsed out from packet*/
-	struct ether_addr ether_dhost, ether_shost;
+	struct libnet_ether_addr ether_dhost, ether_shost;
 	struct in_addr ip_src, ip_dst, yiaddr;
 	/* string versions of same */
 	char ether_dhost_str[MAX_ETHER_ADDR_STR], ether_shost_str[MAX_ETHER_ADDR_STR];
@@ -729,13 +731,13 @@
 		return;
 	}
 
-	if ((ether_len < sizeof(sizeof(struct ether_header))) && (debug > 1)) {
+	if ((ether_len < sizeof(sizeof(struct libnet_ethernet_hdr))) && (debug > 1)) {
 		report(LOG_WARNING, "interface %s, short packet (got %d bytes, smaller than an Ethernet header)", ifname, ether_len);
 		return;
 	}
 
 	/* we use ether_header to access the Ethernet header */
-	ether_header = (struct ether_header *) packet;
+	ether_header = (struct libnet_ethernet_hdr *) packet;
 
 	/* parse fields out of ethernet header for easier access */
 	bcopy(&(ether_header->ether_dhost), &ether_dhost, sizeof(ether_dhost));
@@ -747,13 +749,13 @@
 	if (debug > 10)
 		report(LOG_DEBUG, "     interface %s, from ether %s to %s", ifname, ether_shost_str, ether_dhost_str);
 
-	if (ether_len < sizeof(sizeof(struct ether_header)) + sizeof(struct ip)) {
+	if (ether_len < sizeof(sizeof(struct libnet_ethernet_hdr)) + sizeof(struct libnet_ipv4_hdr)) {
 		report(LOG_WARNING, "interface %s, ether src %s: short packet (got %d bytes, smaller than IP header in Ethernet)", ifname, ether_shost_str, ether_len);
 		return;
 	}	
 
 	/* we use ip_header to access the IP header */
-	ip_header = (struct ip *) (packet + sizeof(struct ether_header));
+	ip_header = (struct libnet_ipv4_hdr *) (packet + sizeof(struct libnet_ethernet_hdr));
 
 	/* parse fields out of ip header for easier access */
 	bcopy(&(ip_header->ip_src), &ip_src, sizeof(ip_header->ip_src));
@@ -768,15 +770,15 @@
 	ip_header_len_bytes = ip_header->ip_hl << 2;
 
 	/* Repeat the packet size check (through IP header), but taking into account ip_header_len_bytes */
-	if (ether_len < sizeof(sizeof(struct ether_header)) + ip_header_len_bytes) {
+	if (ether_len < sizeof(sizeof(struct libnet_ethernet_hdr)) + ip_header_len_bytes) {
 		report(LOG_WARNING, "interface %s, short packet (got %d bytes, smaller than IP header in Ethernet)", ifname, ether_len);
 		return;
 	}	
 
 	/* we use udp_header to access the UDP header */
-	udp_header = (struct udphdr *) (packet + sizeof(struct ether_header) + ip_header_len_bytes);
+	udp_header = (struct udphdr *) (packet + sizeof(struct libnet_ethernet_hdr) + ip_header_len_bytes);
 
-	if (ether_len <  sizeof(sizeof(struct ether_header)) + ip_header_len_bytes + sizeof(struct udphdr)) {
+	if (ether_len <  sizeof(sizeof(struct libnet_ethernet_hdr)) + ip_header_len_bytes + sizeof(struct udphdr)) {
 		report(LOG_WARNING, "interface %s ether src %s: short packet (got %d bytes, smaller than UDP/IP header in Ethernet)", ifname, ether_shost_str, ether_len);
 		return;
 	}	
@@ -800,7 +802,7 @@
 	}
 
 	/* we use bootp_pkt to access the bootp/dhcp packet */
-	bootp_pkt = (struct bootp *) (packet + sizeof(struct ether_header) + ip_header_len_bytes + sizeof(struct udphdr));
+	bootp_pkt = (struct bootp *) (packet + sizeof(struct libnet_ethernet_hdr) + ip_header_len_bytes + sizeof(struct udphdr));
 
 	/* Make sure the packet is in response to our query, otherwise ignore it.
 	   Our query had bootp_htype=HTYPE_ETHER, bootp_hlen=HLEN_ETHER, and bootp_chaddr=GetChaddr().
@@ -820,7 +822,7 @@
 
 	if (bcmp(bootp_pkt->bootp_chaddr, GetChaddr(), HLEN_ETHER)) {
 		if (debug > 10) {
-			struct ether_addr ether_tmp;
+			struct libnet_ether_addr ether_tmp;
 			char ether_tmp_str[MAX_ETHER_ADDR_STR];
 
 			/* create printable version of bootp_pkt->bootp_chaddr */
