--- if_em.c.orig	2026-05-24 14:44:46.949390000 +0700
+++ if_em.c	2026-05-24 14:50:16.444411000 +0700
@@ -1584,10 +1588,7 @@ em_irq_fast(void *arg)
 em_irq_fast(void *arg)
 {
 	struct adapter	*adapter = arg;
-	if_t ifp;
 	u32		reg_icr;
-
-	ifp = adapter->ifp;
 
 	reg_icr = E1000_READ_REG(&adapter->hw, E1000_ICR);
 
@@ -4478,6 +4479,9 @@ em_setup_receive_ring(struct rx_ring *rxr)
 			goto fail;
 		}
 		rxbuf->m_head->m_len = adapter->rx_mbuf_sz;
+#ifndef M_HASFCS
+#define	M_HASFCS	M_PROTO5
+#endif
 		rxbuf->m_head->m_flags &= ~M_HASFCS; /* we strip it */
 		rxbuf->m_head->m_pkthdr.len = adapter->rx_mbuf_sz;
 
