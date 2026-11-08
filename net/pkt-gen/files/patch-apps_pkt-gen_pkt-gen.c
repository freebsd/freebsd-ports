Fix stale UDP checksum when IPv6 source/destination ranges are used.

--- apps/pkt-gen/pkt-gen.c.orig	2026-09-24 16:05:21 UTC
+++ apps/pkt-gen/pkt-gen.c
@@ -917,7 +917,7 @@ update_ip6(struct pkt *pkt, struct targ *t)
 	struct glob_arg *g = t->g;
 	struct ip6_hdr ip6;
 	struct udphdr udp;
-	uint16_t udp_sum;
+	uint16_t udp_sum = 0;
 	uint16_t oaddr, naddr;
 	uint16_t oport, nport;
 	uint8_t group;
@@ -925,7 +925,6 @@ update_ip6(struct pkt *pkt, struct targ *t)
 	memcpy(&ip6, &pkt->ipv6.ip, sizeof(ip6));
 	memcpy(&udp, &pkt->ipv6.udp, sizeof(udp));
 	do {
-		udp_sum = 0;
 		group = g->src_ip.ipv6.sgroup;
 		naddr = oaddr = ntohs(ip6.ip6_src.s6_addr16[group]);
 		nport = oport = ntohs(udp.uh_sport);
@@ -934,30 +933,29 @@ update_ip6(struct pkt *pkt, struct targ *t)
 			udp.uh_sport = nrand48(t->seed);
 			naddr = ntohs(ip6.ip6_src.s6_addr16[group]);
 			nport = ntohs(udp.uh_sport);
+			udp_sum = new_udp_sum(udp_sum, oaddr, naddr);
+			udp_sum = new_udp_sum(udp_sum, oport, nport);
 			break;
 		}
 		if (oport < g->src_ip.port1) {
 			nport = oport + 1;
 			udp.uh_sport = htons(nport);
+			udp_sum = new_udp_sum(udp_sum, oport, nport);
 			break;
 		}
 		nport = g->src_ip.port0;
 		udp.uh_sport = htons(nport);
+		udp_sum = new_udp_sum(udp_sum, oport, nport);
 		if (oaddr < ntohs(g->src_ip.ipv6.end.s6_addr16[group])) {
 			naddr = oaddr + 1;
 			ip6.ip6_src.s6_addr16[group] = htons(naddr);
+			udp_sum = new_udp_sum(udp_sum, oaddr, naddr);
 			break;
 		}
 		naddr = ntohs(g->src_ip.ipv6.start.s6_addr16[group]);
 		ip6.ip6_src.s6_addr16[group] = htons(naddr);
+		udp_sum = new_udp_sum(udp_sum, oaddr, naddr);
 
-		/* update checksums if needed */
-		if (oaddr != naddr)
-			udp_sum = cksum_add(~oaddr, naddr);
-		if (oport != nport)
-			udp_sum = cksum_add(udp_sum,
-			    cksum_add(~oport, nport));
-
 		group = g->dst_ip.ipv6.egroup;
 		naddr = oaddr = ntohs(ip6.ip6_dst.s6_addr16[group]);
 		nport = oport = ntohs(udp.uh_dport);
@@ -966,32 +964,32 @@ update_ip6(struct pkt *pkt, struct targ *t)
 			udp.uh_dport = nrand48(t->seed);
 			naddr = ntohs(ip6.ip6_dst.s6_addr16[group]);
 			nport = ntohs(udp.uh_dport);
+			udp_sum = new_udp_sum(udp_sum, oaddr, naddr);
+			udp_sum = new_udp_sum(udp_sum, oport, nport);
 			break;
 		}
 		if (oport < g->dst_ip.port1) {
 			nport = oport + 1;
 			udp.uh_dport = htons(nport);
+			udp_sum = new_udp_sum(udp_sum, oport, nport);
 			break;
 		}
 		nport = g->dst_ip.port0;
 		udp.uh_dport = htons(nport);
+		udp_sum = new_udp_sum(udp_sum, oport, nport);
 		if (oaddr < ntohs(g->dst_ip.ipv6.end.s6_addr16[group])) {
 			naddr = oaddr + 1;
 			ip6.ip6_dst.s6_addr16[group] = htons(naddr);
+			udp_sum = new_udp_sum(udp_sum, oaddr, naddr);
 			break;
 		}
 		naddr = ntohs(g->dst_ip.ipv6.start.s6_addr16[group]);
 		ip6.ip6_dst.s6_addr16[group] = htons(naddr);
+		udp_sum = new_udp_sum(udp_sum, oaddr, naddr);
 	} while (0);
 	/* update checksums */
-	if (oaddr != naddr)
-		udp_sum = cksum_add(udp_sum,
-		    cksum_add(~oaddr, naddr));
-	if (oport != nport)
-		udp_sum = cksum_add(udp_sum,
-		    cksum_add(~oport, nport));
 	if (udp_sum != 0)
-		udp.uh_sum = ~cksum_add(~udp.uh_sum, udp_sum);
+		udp.uh_sum = ~cksum_add(~udp.uh_sum, htons(udp_sum));
 	memcpy(&pkt->ipv6.ip, &ip6, sizeof(ip6));
 	memcpy(&pkt->ipv6.udp, &udp, sizeof(udp));
 }
