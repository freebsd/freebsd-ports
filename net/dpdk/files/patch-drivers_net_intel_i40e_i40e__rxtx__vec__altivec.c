--- drivers/net/intel/i40e/i40e_rxtx_vec_altivec.c.orig
+++ drivers/net/intel/i40e/i40e_rxtx_vec_altivec.c
@@ -24,7 +24,7 @@
 }
 
 static inline void
-desc_to_olflags_v(__vector unsigned long descs[4], struct rte_mbuf **rx_pkts)
+desc_to_olflags_v(__vector unsigned long long descs[4], struct rte_mbuf **rx_pkts)
 {
 	__vector unsigned int vlan0, vlan1, rss, l3_l4e;
 
@@ -91,14 +91,14 @@
 #define PKTLEN_SHIFT     10
 
 static inline void
-desc_to_ptype_v(__vector unsigned long descs[4], struct rte_mbuf **rx_pkts,
+desc_to_ptype_v(__vector unsigned long long descs[4], struct rte_mbuf **rx_pkts,
 		uint32_t *ptype_tbl)
 {
-	__vector unsigned long ptype0 = vec_mergel(descs[0], descs[1]);
-	__vector unsigned long ptype1 = vec_mergel(descs[2], descs[3]);
-
-	ptype0 = vec_sr(ptype0, (__vector unsigned long){30, 30});
-	ptype1 = vec_sr(ptype1, (__vector unsigned long){30, 30});
+	__vector unsigned long long ptype0 = vec_mergel(descs[0], descs[1]);
+	__vector unsigned long long ptype1 = vec_mergel(descs[2], descs[3]);
+
+	ptype0 = vec_sr(ptype0, (__vector unsigned long long){30, 30});
+	ptype1 = vec_sr(ptype1, (__vector unsigned long long){30, 30});
 
 	rx_pkts[0]->packet_type =
 		ptype_tbl[(*(__vector unsigned char *)&ptype0)[0]];
@@ -136,7 +136,7 @@
 		rxq->crc_len, /* sub crc on data_len */
 		0, 0, 0       /* ignore non-length fields */
 		};
-	__vector unsigned long dd_check, eop_check;
+	__vector unsigned long long dd_check, eop_check;
 
 	/* nb_pkts has to be floor-aligned to I40E_VPMD_DESCS_PER_LOOP */
 	nb_pkts = RTE_ALIGN_FLOOR(nb_pkts, I40E_VPMD_DESCS_PER_LOOP);
@@ -162,11 +162,11 @@
 		return 0;
 
 	/* 4 packets DD mask */
-	dd_check = (__vector unsigned long){0x0000000100000001ULL,
+	dd_check = (__vector unsigned long long){0x0000000100000001ULL,
 					  0x0000000100000001ULL};
 
 	/* 4 packets EOP mask */
-	eop_check = (__vector unsigned long){0x0000000200000002ULL,
+	eop_check = (__vector unsigned long long){0x0000000200000002ULL,
 					   0x0000000200000002ULL};
 
 	/* mask to shuffle from desc. to mbuf */
@@ -196,35 +196,35 @@
 	for (pos = 0, nb_pkts_recd = 0; pos < nb_pkts;
 			pos += I40E_VPMD_DESCS_PER_LOOP,
 			rxdp += I40E_VPMD_DESCS_PER_LOOP) {
-		__vector unsigned long descs[I40E_VPMD_DESCS_PER_LOOP];
+		__vector unsigned long long descs[I40E_VPMD_DESCS_PER_LOOP];
 		__vector unsigned char pkt_mb1, pkt_mb2, pkt_mb3, pkt_mb4;
 		__vector unsigned short staterr, sterr_tmp1, sterr_tmp2;
-		__vector unsigned long mbp1, mbp2; /* two mbuf pointer
+		__vector unsigned long long mbp1, mbp2; /* two mbuf pointer
 						  * in one XMM reg.
 						  */
 
 		/* B.1 load 2 mbuf point */
-		mbp1 = *(__vector unsigned long *)&sw_ring[pos];
+		mbp1 = *(__vector unsigned long long *)&sw_ring[pos];
 		/* Read desc statuses backwards to avoid race condition */
 		/* A.1 load desc[3] */
-		descs[3] = *RTE_CAST_PTR(__vector unsigned long *, rxdp + 3);
+		descs[3] = *RTE_CAST_PTR(__vector unsigned long long *, rxdp + 3);
 		rte_compiler_barrier();
 
 		/* B.2 copy 2 mbuf point into rx_pkts  */
-		*(__vector unsigned long *)&rx_pkts[pos] = mbp1;
+		*(__vector unsigned long long *)&rx_pkts[pos] = mbp1;
 
 		/* B.1 load 2 mbuf point */
-		mbp2 = *(__vector unsigned long *)&sw_ring[pos + 2];
+		mbp2 = *(__vector unsigned long long *)&sw_ring[pos + 2];
 
 		/* A.1 load desc[2-0] */
-		descs[2] = *RTE_CAST_PTR(__vector unsigned long *, rxdp + 2);
+		descs[2] = *RTE_CAST_PTR(__vector unsigned long long *, rxdp + 2);
 		rte_compiler_barrier();
-		descs[1] = *RTE_CAST_PTR(__vector unsigned long *, rxdp + 1);
+		descs[1] = *RTE_CAST_PTR(__vector unsigned long long *, rxdp + 1);
 		rte_compiler_barrier();
-		descs[0] = *RTE_CAST_PTR(__vector unsigned long *, rxdp);
+		descs[0] = *RTE_CAST_PTR(__vector unsigned long long *, rxdp);
 
 		/* B.2 copy 2 mbuf point into rx_pkts  */
-		*(__vector unsigned long *)&rx_pkts[pos + 2] =  mbp2;
+		*(__vector unsigned long long *)&rx_pkts[pos + 2] =  mbp2;
 
 		if (split_packet) {
 			rte_mbuf_prefetch_part2(rx_pkts[pos]);
@@ -246,8 +246,8 @@
 			(__vector unsigned int){0, 0, 0, PKTLEN_SHIFT});
 
 		/* merge the now-aligned packet length fields back in */
-		descs[3] = (__vector unsigned long)len3;
-		descs[2] = (__vector unsigned long)len2;
+		descs[3] = (__vector unsigned long long)len3;
+		descs[2] = (__vector unsigned long long)len2;
 
 		/* D.1 pkt 3,4 convert format from desc to pktmbuf */
 		pkt_mb4 = vec_perm((__vector unsigned char)descs[3],
@@ -276,8 +276,8 @@
 			(__vector unsigned int){0, 0, 0, PKTLEN_SHIFT});
 
 		/* merge the now-aligned packet length fields back in */
-		descs[1] = (__vector unsigned long)len1;
-		descs[0] = (__vector unsigned long)len0;
+		descs[1] = (__vector unsigned long long)len1;
+		descs[0] = (__vector unsigned long long)len0;
 
 		/* D.1 pkt 1,2 convert format from desc to pktmbuf */
 		pkt_mb2 = vec_perm((__vector unsigned char)descs[1],
@@ -353,8 +353,8 @@
 		desc_to_olflags_v(descs, &rx_pkts[pos]);
 
 		/* C.4 calc available number of desc */
-		var = rte_popcount64((vec_ld(0,
-			(__vector unsigned long *)&staterr)[0]));
+		var = rte_popcount64(((__vector unsigned long long)vec_ld(0,
+			(__vector unsigned short *)&staterr))[0]);
 		nb_pkts_recd += var;
 		if (likely(var != I40E_VPMD_DESCS_PER_LOOP))
 			break;
@@ -453,9 +453,9 @@
 		((uint64_t)flags  << I40E_TXD_QW1_CMD_SHIFT) |
 		((uint64_t)pkt->data_len << I40E_TXD_QW1_TX_BUF_SZ_SHIFT));
 
-	__vector unsigned long descriptor = (__vector unsigned long){
+	__vector unsigned long long descriptor = (__vector unsigned long long){
 		pkt->buf_iova + pkt->data_off, high_qw};
-	*RTE_CAST_PTR(__vector unsigned long *, txdp) = descriptor;
+	*RTE_CAST_PTR(__vector unsigned long long *, txdp) = descriptor;
 }
 
 static inline void
