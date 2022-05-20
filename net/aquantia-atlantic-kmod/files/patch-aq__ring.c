--- aq_ring.c.orig	2022-05-13 21:22:45 UTC
+++ aq_ring.c
@@ -456,8 +456,8 @@ static int aq_isc_txd_encap(void *arg, if_pkt_info_t p
 	aq_tx_desc_t *txd = NULL;
 	bus_dma_segment_t *segs;
 	qidx_t pidx;
-	uint32_t hdrlen=0, pay_len, eop;
-	uint8_t tx_cmd = 0, ct_en, ct_idx;
+	uint32_t hdrlen=0, pay_len;
+	uint8_t tx_cmd = 0;
 	int i, desc_count = 0;
 
 	AQ_DBG_ENTERA("[%d] start=%d", pi->ipi_qsidx, pi->ipi_pidx);
@@ -469,9 +469,6 @@ static int aq_isc_txd_encap(void *arg, if_pkt_info_t p
 	AQ_DBG_PRINT("txc at 0x%p, txd at 0x%p len %d", txc, txd, pi->ipi_len);
 
 	pay_len = pi->ipi_len;
-	eop = 0;
-	ct_en = 0;
-	ct_idx = 0;
 
 	txc->flags1 = 0U;
 	txc->flags2 = 0U;
