--- drivers/net/intel/common/rx_vec_ppc.h.orig
+++ drivers/net/intel/common/rx_vec_ppc.h
@@ -25,12 +25,12 @@
 
 	if (rte_mbuf_raw_alloc_bulk(rxq->mp, rxp, rearm_thresh) < 0) {
 		if (rxq->rxrearm_nb + rearm_thresh >= rxq->nb_rx_desc) {
-			__vector unsigned long dma_addr0 = (__vector unsigned long){};
+			__vector unsigned long long dma_addr0 = (__vector unsigned long long){};
 
 			for (i = 0; i < CI_VPMD_DESCS_PER_LOOP; i++) {
 				rxp[i] = &rxq->fake_mbuf;
-				vec_st(dma_addr0, 0,
-					RTE_CAST_PTR(__vector unsigned long *, &rxdp[i]));
+				vec_st((__vector unsigned int)dma_addr0, 0,
+					RTE_CAST_PTR(__vector unsigned int *, &rxdp[i]));
 			}
 		}
 		rte_eth_devices[rxq->port_id].data->rx_mbuf_alloc_failed += rearm_thresh;
@@ -48,15 +48,15 @@
 {
 	struct ci_rx_entry *rxep = &rxq->sw_ring[rxq->rxrearm_start];
 	const uint16_t rearm_thresh = CI_VPMD_RX_REARM_THRESH;
-	__vector unsigned long hdroom =
-			(__vector unsigned long){RTE_PKTMBUF_HEADROOM, RTE_PKTMBUF_HEADROOM};
+	__vector unsigned long long hdroom =
+			(__vector unsigned long long){RTE_PKTMBUF_HEADROOM, RTE_PKTMBUF_HEADROOM};
 	int i;
 
 	volatile union ci_rx_desc *rxdp = rxq->rx_ring + rxq->rxrearm_start;
 
 	/* Initialize the mbufs in vector, process 2 mbufs in one loop */
 	for (i = 0; i < rearm_thresh; i += 2, rxep += 2) {
-		__vector unsigned long vaddr0, vaddr1;
+		__vector unsigned long long vaddr0, vaddr1;
 		struct rte_mbuf *mb0 = rxep[0].mbuf;
 		struct rte_mbuf *mb1 = rxep[1].mbuf;
 
@@ -70,8 +70,8 @@
 		*(uint64_t *)&mb1->rearm_data = rxq->mbuf_initializer;
 
 		/* load buf_addr(lo 64bit) and buf_iova(hi 64bit) */
-		vaddr0 = vec_ld(0, (__vector unsigned long *)&mb0->buf_addr);
-		vaddr1 = vec_ld(0, (__vector unsigned long *)&mb1->buf_addr);
+		vaddr0 = (__vector unsigned long long)vec_ld(0, (__vector unsigned int *)&mb0->buf_addr);
+		vaddr1 = (__vector unsigned long long)vec_ld(0, (__vector unsigned int *)&mb1->buf_addr);
 
 #if RTE_IOVA_IN_MBUF
 		/* convert pa to dma_addr hdr/data */
@@ -88,8 +88,8 @@
 		vaddr1 = vec_add(vaddr1, hdroom);
 
 		/* flush desc with pa dma_addr */
-		vec_st(vaddr0, 0, RTE_CAST_PTR(__vector unsigned long *, rxdp++));
-		vec_st(vaddr1, 0, RTE_CAST_PTR(__vector unsigned long *, rxdp++));
+		vec_st((__vector unsigned int)vaddr0, 0, RTE_CAST_PTR(__vector unsigned int *, rxdp++));
+		vec_st((__vector unsigned int)vaddr1, 0, RTE_CAST_PTR(__vector unsigned int *, rxdp++));
 	}
 }
 
