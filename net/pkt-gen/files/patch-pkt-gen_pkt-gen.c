--- pkt-gen/pkt-gen.c.orig	2017-08-06 18:26:36 UTC
+++ pkt-gen/pkt-gen.c
@@ -186,6 +186,7 @@ const char *indirect_payload="netmap pkt
 	"http://info.iet.unipi.it/~luigi/netmap/ ";
 
 int verbose = 0;
+int normalize = 1;
 
 #define VIRT_HDR_1	10	/* length of a base vnet-hdr */
 #define VIRT_HDR_2	12	/* length of the extenede vnet-hdr */
@@ -204,12 +205,12 @@ struct pkt {
 			struct ip ip;
 			struct udphdr udp;
 			uint8_t body[MAX_BODYSIZE];	/* hardwired */
-		} ipv4;
+		} __attribute__((__packed__)) ipv4;
 		struct {
 			struct ip6_hdr ip;
 			struct udphdr udp;
 			uint8_t body[MAX_BODYSIZE];	/* hardwired */
-		} ipv6;
+		} __attribute__((__packed__)) ipv6;
 	};
 } __attribute__((__packed__));
 
@@ -752,39 +753,39 @@ dump_payload(const char *_p, int len, st
 static void
 update_ip(struct pkt *pkt, struct glob_arg *g)
 {
-	struct ip *ip;
-	struct udphdr *udp;
+	struct ip ip;
+	struct udphdr udp;
 	uint32_t oaddr, naddr;
 	uint16_t oport, nport;
 	uint16_t ip_sum, udp_sum;
 
-	ip = &pkt->ipv4.ip;
-	udp = &pkt->ipv4.udp;
+	memcpy(&ip, &pkt->ipv4.ip, sizeof(ip));
+	memcpy(&udp, &pkt->ipv4.udp, sizeof(udp));
 	do {
 		ip_sum = udp_sum = 0;
-		naddr = oaddr = ntohl(ip->ip_src.s_addr);
-		nport = oport = ntohs(udp->uh_sport);
+		naddr = oaddr = ntohl(ip.ip_src.s_addr);
+		nport = oport = ntohs(udp.uh_sport);
 		if (g->options & OPT_RANDOM_SRC) {
-			ip->ip_src.s_addr = random();
-			udp->uh_sport = random();
-			naddr = ntohl(ip->ip_src.s_addr);
-			nport = ntohs(udp->uh_sport);
+			ip.ip_src.s_addr = random();
+			udp.uh_sport = random();
+			naddr = ntohl(ip.ip_src.s_addr);
+			nport = ntohs(udp.uh_sport);
 			break;
 		}
 		if (oport < g->src_ip.port1) {
 			nport = oport + 1;
-			udp->uh_sport = htons(nport);
+			udp.uh_sport = htons(nport);
 			break;
 		}
 		nport = g->src_ip.port0;
-		udp->uh_sport = htons(nport);
+		udp.uh_sport = htons(nport);
 		if (oaddr < g->src_ip.ipv4.end) {
 			naddr = oaddr + 1;
-			ip->ip_src.s_addr = htonl(naddr);
+			ip.ip_src.s_addr = htonl(naddr);
 			break;
 		}
 		naddr = g->src_ip.ipv4.start;
-		ip->ip_src.s_addr = htonl(naddr);
+		ip.ip_src.s_addr = htonl(naddr);
 	} while (0);
 	/* update checksums if needed */
 	if (oaddr != naddr) {
@@ -798,29 +799,29 @@ update_ip(struct pkt *pkt, struct glob_a
 		udp_sum = cksum_add(udp_sum, nport);
 	}
 	do {
-		naddr = oaddr = ntohl(ip->ip_dst.s_addr);
-		nport = oport = ntohs(udp->uh_dport);
+		naddr = oaddr = ntohl(ip.ip_dst.s_addr);
+		nport = oport = ntohs(udp.uh_dport);
 		if (g->options & OPT_RANDOM_DST) {
-			ip->ip_dst.s_addr = random();
-			udp->uh_dport = random();
-			naddr = ntohl(ip->ip_dst.s_addr);
-			nport = ntohs(udp->uh_dport);
+			ip.ip_dst.s_addr = random();
+			udp.uh_dport = random();
+			naddr = ntohl(ip.ip_dst.s_addr);
+			nport = ntohs(udp.uh_dport);
 			break;
 		}
 		if (oport < g->dst_ip.port1) {
 			nport = oport + 1;
-			udp->uh_dport = htons(nport);
+			udp.uh_dport = htons(nport);
 			break;
 		}
 		nport = g->dst_ip.port0;
-		udp->uh_dport = htons(nport);
+		udp.uh_dport = htons(nport);
 		if (oaddr < g->dst_ip.ipv4.end) {
 			naddr = oaddr + 1;
-			ip->ip_dst.s_addr = htonl(naddr);
+			ip.ip_dst.s_addr = htonl(naddr);
 			break;
 		}
 		naddr = g->dst_ip.ipv4.start;
-		ip->ip_dst.s_addr = htonl(naddr);
+		ip.ip_dst.s_addr = htonl(naddr);
 	} while (0);
 	/* update checksums */
 	if (oaddr != naddr) {
@@ -834,11 +835,13 @@ update_ip(struct pkt *pkt, struct glob_a
 		udp_sum = cksum_add(udp_sum, nport);
 	}
 	if (udp_sum != 0)
-		udp->uh_sum = ~cksum_add(~udp->uh_sum, htons(udp_sum));
+		udp.uh_sum = ~cksum_add(~udp.uh_sum, htons(udp_sum));
 	if (ip_sum != 0) {
-		ip->ip_sum = ~cksum_add(~ip->ip_sum, htons(ip_sum));
-		udp->uh_sum = ~cksum_add(~udp->uh_sum, htons(ip_sum));
+		ip.ip_sum = ~cksum_add(~ip.ip_sum, htons(ip_sum));
+		udp.uh_sum = ~cksum_add(~udp.uh_sum, htons(ip_sum));
 	}
+	memcpy(&pkt->ipv4.ip, &ip, sizeof(ip));
+	memcpy(&pkt->ipv4.udp, &udp, sizeof(udp));
 }
 
 #ifndef s6_addr16
@@ -847,41 +850,41 @@ update_ip(struct pkt *pkt, struct glob_a
 static void
 update_ip6(struct pkt *pkt, struct glob_arg *g)
 {
-	struct ip6_hdr *ip6;
-	struct udphdr *udp;
+	struct ip6_hdr ip6;
+	struct udphdr udp;
 	uint16_t udp_sum;
 	uint16_t oaddr, naddr;
 	uint16_t oport, nport;
 	uint8_t group;
 
-	ip6 = &pkt->ipv6.ip;
-	udp = &pkt->ipv6.udp;
+	memcpy(&ip6, &pkt->ipv6.ip, sizeof(ip6));
+	memcpy(&udp, &pkt->ipv6.udp, sizeof(udp));
 	do {
 		udp_sum = 0;
 		group = g->src_ip.ipv6.sgroup;
-		naddr = oaddr = ntohs(ip6->ip6_src.s6_addr16[group]);
-		nport = oport = ntohs(udp->uh_sport);
+		naddr = oaddr = ntohs(ip6.ip6_src.s6_addr16[group]);
+		nport = oport = ntohs(udp.uh_sport);
 		if (g->options & OPT_RANDOM_SRC) {
-			ip6->ip6_src.s6_addr16[group] = random();
-			udp->uh_sport = random();
-			naddr = ntohs(ip6->ip6_src.s6_addr16[group]);
-			nport = ntohs(udp->uh_sport);
+			ip6.ip6_src.s6_addr16[group] = random();
+			udp.uh_sport = random();
+			naddr = ntohs(ip6.ip6_src.s6_addr16[group]);
+			nport = ntohs(udp.uh_sport);
 			break;
 		}
 		if (oport < g->src_ip.port1) {
 			nport = oport + 1;
-			udp->uh_sport = htons(nport);
+			udp.uh_sport = htons(nport);
 			break;
 		}
 		nport = g->src_ip.port0;
-		udp->uh_sport = htons(nport);
+		udp.uh_sport = htons(nport);
 		if (oaddr < ntohs(g->src_ip.ipv6.end.s6_addr16[group])) {
 			naddr = oaddr + 1;
-			ip6->ip6_src.s6_addr16[group] = htons(naddr);
+			ip6.ip6_src.s6_addr16[group] = htons(naddr);
 			break;
 		}
 		naddr = ntohs(g->src_ip.ipv6.start.s6_addr16[group]);
-		ip6->ip6_src.s6_addr16[group] = htons(naddr);
+		ip6.ip6_src.s6_addr16[group] = htons(naddr);
 	} while (0);
 	/* update checksums if needed */
 	if (oaddr != naddr)
@@ -891,29 +894,29 @@ update_ip6(struct pkt *pkt, struct glob_
 		    cksum_add(~oport, nport));
 	do {
 		group = g->dst_ip.ipv6.egroup;
-		naddr = oaddr = ntohs(ip6->ip6_dst.s6_addr16[group]);
-		nport = oport = ntohs(udp->uh_dport);
+		naddr = oaddr = ntohs(ip6.ip6_dst.s6_addr16[group]);
+		nport = oport = ntohs(udp.uh_dport);
 		if (g->options & OPT_RANDOM_DST) {
-			ip6->ip6_dst.s6_addr16[group] = random();
-			udp->uh_dport = random();
-			naddr = ntohs(ip6->ip6_dst.s6_addr16[group]);
-			nport = ntohs(udp->uh_dport);
+			ip6.ip6_dst.s6_addr16[group] = random();
+			udp.uh_dport = random();
+			naddr = ntohs(ip6.ip6_dst.s6_addr16[group]);
+			nport = ntohs(udp.uh_dport);
 			break;
 		}
 		if (oport < g->dst_ip.port1) {
 			nport = oport + 1;
-			udp->uh_dport = htons(nport);
+			udp.uh_dport = htons(nport);
 			break;
 		}
 		nport = g->dst_ip.port0;
-		udp->uh_dport = htons(nport);
+		udp.uh_dport = htons(nport);
 		if (oaddr < ntohs(g->dst_ip.ipv6.end.s6_addr16[group])) {
 			naddr = oaddr + 1;
-			ip6->ip6_dst.s6_addr16[group] = htons(naddr);
+			ip6.ip6_dst.s6_addr16[group] = htons(naddr);
 			break;
 		}
 		naddr = ntohs(g->dst_ip.ipv6.start.s6_addr16[group]);
-		ip6->ip6_dst.s6_addr16[group] = htons(naddr);
+		ip6.ip6_dst.s6_addr16[group] = htons(naddr);
 	} while (0);
 	/* update checksums */
 	if (oaddr != naddr)
@@ -923,7 +926,9 @@ update_ip6(struct pkt *pkt, struct glob_
 		udp_sum = cksum_add(udp_sum,
 		    cksum_add(~oport, nport));
 	if (udp_sum != 0)
-		udp->uh_sum = ~cksum_add(~udp->uh_sum, udp_sum);
+		udp.uh_sum = ~cksum_add(~udp.uh_sum, udp_sum);
+	memcpy(&pkt->ipv6.ip, &ip6, sizeof(ip6));
+	memcpy(&pkt->ipv6.udp, &udp, sizeof(udp));
 }
 
 static void
@@ -944,9 +949,10 @@ initialize_packet(struct targ *targ)
 {
 	struct pkt *pkt = &targ->pkt;
 	struct ether_header *eh;
-	struct ip6_hdr *ip6;
-	struct ip *ip;
-	struct udphdr *udp;
+	struct ip6_hdr ip6;
+	struct ip ip;
+	struct udphdr udp;
+	void *udp_ptr;
 	uint16_t paylen;
 	uint32_t csum;
 	const char *payload = targ->g->options & OPT_INDIRECT ?
@@ -978,7 +984,7 @@ initialize_packet(struct targ *targ)
 #endif
 
 	paylen = targ->g->pkt_size - sizeof(*eh) -
-	    (targ->g->af == AF_INET ? sizeof(*ip): sizeof(*ip6));
+	    (targ->g->af == AF_INET ? sizeof(ip): sizeof(ip6));
 
 	/* create a nice NUL-terminated string */
 	for (i = 0; i < paylen; i += l0) {
@@ -995,56 +1001,61 @@ initialize_packet(struct targ *targ)
 
 	if (targ->g->af == AF_INET) {
 		eh->ether_type = htons(ETHERTYPE_IP);
-		ip = &pkt->ipv4.ip;
-		udp = &pkt->ipv4.udp;
-		ip->ip_v = IPVERSION;
-		ip->ip_hl = sizeof(*ip) >> 2;
-		ip->ip_id = 0;
-		ip->ip_tos = IPTOS_LOWDELAY;
-		ip->ip_len = htons(targ->g->pkt_size - sizeof(*eh));
-		ip->ip_id = 0;
-		ip->ip_off = htons(IP_DF); /* Don't fragment */
-		ip->ip_ttl = IPDEFTTL;
-		ip->ip_p = IPPROTO_UDP;
-		ip->ip_dst.s_addr = htonl(targ->g->dst_ip.ipv4.start);
-		ip->ip_src.s_addr = htonl(targ->g->src_ip.ipv4.start);
-		ip->ip_sum = wrapsum(checksum(ip, sizeof(*ip), 0));
+		memcpy(&ip, &pkt->ipv4.ip, sizeof(ip));
+		udp_ptr = &pkt->ipv4.udp;
+		ip.ip_v = IPVERSION;
+		ip.ip_hl = sizeof(ip) >> 2;
+		ip.ip_id = 0;
+		ip.ip_tos = IPTOS_LOWDELAY;
+		ip.ip_len = htons(targ->g->pkt_size - sizeof(*eh));
+		ip.ip_id = 0;
+		ip.ip_off = htons(IP_DF); /* Don't fragment */
+		ip.ip_ttl = IPDEFTTL;
+		ip.ip_p = IPPROTO_UDP;
+		ip.ip_dst.s_addr = htonl(targ->g->dst_ip.ipv4.start);
+		ip.ip_src.s_addr = htonl(targ->g->src_ip.ipv4.start);
+		ip.ip_sum = wrapsum(checksum(&ip, sizeof(ip), 0));
+		memcpy(&pkt->ipv4.ip, &ip, sizeof(ip));
 	} else {
 		eh->ether_type = htons(ETHERTYPE_IPV6);
-		ip6 = &pkt->ipv6.ip;
-		udp = &pkt->ipv6.udp;
-		ip6->ip6_flow = 0;
-		ip6->ip6_plen = htons(paylen);
-		ip6->ip6_vfc = IPV6_VERSION;
-		ip6->ip6_nxt = IPPROTO_UDP;
-		ip6->ip6_hlim = IPV6_DEFHLIM;
-		ip6->ip6_src = targ->g->src_ip.ipv6.start;
-		ip6->ip6_dst = targ->g->dst_ip.ipv6.start;
+		memcpy(&ip6, &pkt->ipv4.ip, sizeof(ip6));
+		udp_ptr = &pkt->ipv6.udp;
+		ip6.ip6_flow = 0;
+		ip6.ip6_plen = htons(paylen);
+		ip6.ip6_vfc = IPV6_VERSION;
+		ip6.ip6_nxt = IPPROTO_UDP;
+		ip6.ip6_hlim = IPV6_DEFHLIM;
+		ip6.ip6_src = targ->g->src_ip.ipv6.start;
+		ip6.ip6_dst = targ->g->dst_ip.ipv6.start;
 	}
+	memcpy(&udp, udp_ptr, sizeof(udp));
 
-	udp->uh_sport = htons(targ->g->src_ip.port0);
-	udp->uh_dport = htons(targ->g->dst_ip.port0);
-	udp->uh_ulen = htons(paylen);
+	udp.uh_sport = htons(targ->g->src_ip.port0);
+	udp.uh_dport = htons(targ->g->dst_ip.port0);
+	udp.uh_ulen = htons(paylen);
 	if (targ->g->af == AF_INET) {
 		/* Magic: taken from sbin/dhclient/packet.c */
-		udp->uh_sum = wrapsum(
-		    checksum(udp, sizeof(*udp),	/* udp header */
+		udp.uh_sum = wrapsum(
+		    checksum(&udp, sizeof(udp),	/* udp header */
                     checksum(pkt->ipv4.body,	/* udp payload */
-		    paylen - sizeof(*udp),
+		    paylen - sizeof(udp),
 		    checksum(&pkt->ipv4.ip.ip_src, /* pseudo header */
 			2 * sizeof(pkt->ipv4.ip.ip_src),
-			IPPROTO_UDP + (u_int32_t)ntohs(udp->uh_ulen)))));
+			IPPROTO_UDP + (u_int32_t)ntohs(udp.uh_ulen)))));
+		memcpy(&pkt->ipv4.ip, &ip, sizeof(ip));
 	} else {
 		/* Save part of pseudo header checksum into csum */
 		csum = IPPROTO_UDP << 24;
 		csum = checksum(&csum, sizeof(csum), paylen);
-		udp->uh_sum = wrapsum(
-		    checksum(udp, sizeof(*udp),	/* udp header */
+		udp.uh_sum = wrapsum(
+		    checksum(udp_ptr, sizeof(udp),	/* udp header */
 		    checksum(pkt->ipv6.body,	/* udp payload */
-		    paylen - sizeof(*udp),
+		    paylen - sizeof(udp),
 		    checksum(&pkt->ipv6.ip.ip6_src, /* pseudo header */
 			2 * sizeof(pkt->ipv6.ip.ip6_src), csum))));
+		memcpy(&pkt->ipv6.ip, &ip6, sizeof(ip6));
 	}
+	memcpy(udp_ptr, &udp, sizeof(udp));
 
 	bzero(&pkt->vh, sizeof(pkt->vh));
 	// dump_payload((void *)pkt, targ->g->pkt_size, NULL, 0);
@@ -1864,6 +1875,7 @@ txseq_body(void *data)
 		unsigned int space;
 		unsigned int head;
 		int fcnt;
+		uint16_t sum;
 
 		if (!rate_limit) {
 			budget = targ->g->burst;
@@ -1910,19 +1922,19 @@ txseq_body(void *data)
 				sent < limit; sent++, sequence++) {
 			struct netmap_slot *slot = &ring->slot[head];
 			char *p = NETMAP_BUF(ring, slot->buf_idx);
-			uint16_t *w = (uint16_t *)PKT(pkt, body, targ->g->af), t,
-				 *sum = (uint16_t *)(targ->g->af == AF_INET ?
-						 &pkt->ipv4.udp.uh_sum : &pkt->ipv6.udp.uh_sum);
+			uint16_t *w = (uint16_t *)PKT(pkt, body, targ->g->af), t;
+
+			memcpy(&sum, targ->g->af == AF_INET ? &pkt->ipv4.udp.uh_sum : &pkt->ipv6.udp.uh_sum, sizeof(sum));
 
 			slot->flags = 0;
 			t = *w;
 			PKT(pkt, body, targ->g->af)[0] = sequence >> 24;
 			PKT(pkt, body, targ->g->af)[1] = (sequence >> 16) & 0xff;
-			*sum = ~cksum_add(~*sum, cksum_add(~t, *w));
+			sum = ~cksum_add(~sum, cksum_add(~t, *w));
 			t = *++w;
 			PKT(pkt, body, targ->g->af)[2] = (sequence >> 8) & 0xff;
 			PKT(pkt, body, targ->g->af)[3] = sequence & 0xff;
-			*sum = ~cksum_add(~*sum, cksum_add(~t, *w));
+			sum = ~cksum_add(~sum, cksum_add(~t, *w));
 			nm_pkt_copy(frame, p, size);
 			if (fcnt == frags) {
 				update_addresses(pkt, targ->g);
@@ -1952,6 +1964,7 @@ txseq_body(void *data)
 				budget--;
 			}
 		}
+		memcpy(targ->g->af == AF_INET ? &pkt->ipv4.udp.uh_sum : &pkt->ipv6.udp.uh_sum, &sum, sizeof(sum));
 
 		ring->cur = ring->head = head;
 
@@ -2209,7 +2222,7 @@ tx_output(struct my_ctrs *cur, double de
 	abs = cur->pkts / (double)(cur->events);
 
 	printf("Speed: %spps Bandwidth: %sbps (raw %sbps). Average batch: %.2f pkts\n",
-		norm(b1, pps), norm(b2, bw), norm(b3, raw_bw), abs);
+		norm(b1, pps, normalize), norm(b2, bw, normalize), norm(b3, raw_bw, normalize), abs);
 }
 
 static void
@@ -2219,38 +2232,72 @@ usage(void)
 	fprintf(stderr,
 		"Usage:\n"
 		"%s arguments\n"
-		"\t-i interface		interface name\n"
-		"\t-f function		tx rx ping pong txseq rxseq\n"
-		"\t-n count		number of iterations (can be 0)\n"
-		"\t-t pkts_to_send	also forces tx mode\n"
-		"\t-r pkts_to_receive	also forces rx mode\n"
-		"\t-l pkt_size		in bytes excluding CRC\n"
-		"\t                     (if passed a second time, use random sizes\n"
-		"\t                      bigger than the second one and lower than\n"
-		"\t                      the first one)\n"
-		"\t-d dst_ip[:port[-dst_ip:port]]   single or range\n"
-		"\t-s src_ip[:port[-src_ip:port]]   single or range\n"
-		"\t-D dst-mac\n"
-		"\t-S src-mac\n"
-		"\t-a cpu_id		use setaffinity\n"
-		"\t-b burst size		testing, mostly\n"
-		"\t-c cores		cores to use\n"
-		"\t-p threads		processes/threads to use\n"
-		"\t-T report_ms		milliseconds between reports\n"
-		"\t-w wait_for_link_time	in seconds\n"
-		"\t-R rate		in packets per second\n"
-		"\t-X			dump payload\n"
-		"\t-H len		add empty virtio-net-header with size 'len'\n"
-		"\t-E pipes		allocate extra space for a number of pipes\n"
-		"\t-r			do not touch the buffers (send rubbish)\n"
-	        "\t-P file		load packet from pcap file\n"
-		"\t-z			use random IPv4 src address/port\n"
-		"\t-Z			use random IPv4 dst address/port\n"
-		"\t-F num_frags		send multi-slot packets\n"
-		"\t-A			activate pps stats on receiver\n"
-		"",
+		     "\t-i interface		interface name\n"
+		     "\t-f function		tx rx ping pong txseq rxseq\n"
+		     "\t-n count		number of iterations (can be 0)\n"
+#ifdef notyet
+		     "\t-t pkts_to_send		also forces tx mode\n"
+		     "\t-r pkts_to_receive	also forces rx mode\n"
+#endif
+		     "\t-l pkt_size		in bytes excluding CRC\n"
+		     "\t			(if passed a second time, use random sizes\n"
+		     "\t			 bigger than the second one and lower than\n"
+		     "\t			 the first one)\n"
+		     "\t-d dst_ip[:port[-dst_ip:port]]   single or range\n"
+		     "\t-s src_ip[:port[-src_ip:port]]   single or range\n"
+		     "\t-D dst-mac\n"
+		     "\t-S src-mac\n"
+		     "\t-a cpu_id		use setaffinity\n"
+		     "\t-b burst size		testing, mostly\n"
+		     "\t-c cores		cores to use\n"
+		     "\t-p threads		processes/threads to use\n"
+		     "\t-T report_ms		milliseconds between reports\n"
+		     "\t-w wait_for_link_time	in seconds\n"
+		     "\t-R rate			in packets per second\n"
+		     "\t-X			dump payload\n"
+		     "\t-H len			add empty virtio-net-header with size 'len'\n"
+		     "\t-E pipes		allocate extra space for a number of pipes\n"
+		     "\t-r			do not touch the buffers (send rubbish)\n"
+	             "\t-P file			load packet from pcap file\n"
+		     "\t-z			use random IPv4 src address/port\n"
+		     "\t-Z			use random IPv4 dst address/port\n"
+		     "\t-F num_frags		send multi-slot packets\n"
+		     "\t-A			activate pps stats on receiver\n"
+		     "\t-4			IPv4\n"
+		     "\t-6			IPv6\n"
+		     "\t-N			don't normalize units (Kbps/Mbps/etc)\n"
+		     "\t-I			use indirect buffers, tx only\n"
+		     "\t-o options		data generation options (parsed using atoi)\n"
+		     "\t			OPT_PREFETCH	1\n"
+		     "\t			OPT_ACCESS	2\n"
+		     "\t			OPT_COPY	4\n"
+		     "\t			OPT_MEMCPY	8\n"
+		     "\t			OPT_TS		16 (add a timestamp)\n"
+		     "\t			OPT_INDIRECT	32 (use indirect buffers)\n"
+		     "\t			OPT_DUMP	64 (dump rx/tx traffic)\n"
+		     "\t			OPT_RUBBISH	256\n"
+		     "\t			    (send wathever the buffers contain)\n"
+		     "\t			OPT_RANDOM_SRC  512\n"
+		     "\t			OPT_RANDOM_DST  1024\n"
+		     "\t			OPT_PPS_STATS   2048\n"
+		     "\t-W			exit RX with no traffic\n"
+		     "\t-v			verbose (more v = more verbose)\n"
+		     "\t-C vale-config		specify a vale config\n"
+#ifdef notyet
+		     "\t			The configuration may consist of 0 to 4\n"
+		     "\t			numbers separated by commas:\n"
+		     "\t			#tx-slots,#rx-slots,#tx-rings,#rx-rings.\n"
+		     "\t			Missing numbers or zeroes stand for default\n"
+		     "\t			values. As an additional convenience, if\n"
+		     "\t			exactly one number is specified, then this\n"
+		     "\t			is assigned to both #tx-slots and #rx-slots.\n"
+		     "\t			If there is no 4th number, then the 3rd is\n"
+		     "\t			assigned to both #tx-rings and #rx-rings.\n"
+#endif
+		     "\t-e extra-bufs		extra_bufs - goes in nr_arg3\n"
+		     "\t-m			ignored\n"
+		     "",
 		cmd);
-
 	exit(0);
 }
 
@@ -2405,13 +2452,13 @@ main_thread(struct glob_arg *g)
 			ppsdev = sqrt(ppsdev);
 
 			snprintf(b4, sizeof(b4), "[avg/std %s/%s pps]",
-				 norm(b1, ppsavg), norm(b2, ppsdev));
+				 norm(b1, ppsavg, normalize), norm(b2, ppsdev, normalize));
 		}
 
 		D("%spps %s(%spkts %sbps in %llu usec) %.2f avg_batch %d min_space",
-			norm(b1, pps), b4,
-			norm(b2, (double)x.pkts),
-			norm(b3, (double)x.bytes*8),
+			norm(b1, pps, normalize), b4,
+			norm(b2, (double)x.pkts, normalize),
+			norm(b3, (double)x.bytes*8, normalize),
 			(unsigned long long)usec,
 			abs, (int)cur.min_space);
 		prev = cur;
@@ -2589,7 +2636,7 @@ main(int arc, char **argv)
 	g.virt_header = 0;
 	g.wait_link = 2;
 
-	while ((ch = getopt(arc, argv, "46a:f:F:n:i:Il:d:s:D:S:b:c:o:p:"
+	while ((ch = getopt(arc, argv, "46a:f:F:Nn:i:Il:d:s:D:S:b:c:o:p:"
 	    "T:w:WvR:XC:H:e:E:m:rP:zZA")) != -1) {
 
 		switch(ch) {
@@ -2606,6 +2653,10 @@ main(int arc, char **argv)
 			g.af = AF_INET6;
 			break;
 
+		case 'N':
+			normalize = 0;
+			break;
+
 		case 'n':
 			g.npackets = strtoull(optarg, NULL, 10);
 			break;
@@ -2633,7 +2684,7 @@ main(int arc, char **argv)
 			break;
 
 		case 'o':	/* data generation options */
-			g.options = atoi(optarg);
+			g.options |= atoi(optarg);
 			break;
 
 		case 'a':       /* force affinity */
