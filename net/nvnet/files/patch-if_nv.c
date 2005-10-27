--- src/if_nv.c.orig	Fri Mar 11 17:12:42 2005
+++ src/if_nv.c	Thu Oct 27 08:36:09 2005
@@ -720,6 +720,7 @@ nv_stop(struct nv_softc *sc)
 	sc->linkup = 0;
 	sc->cur_rx = 0;
 	sc->pending_rxs = 0;
+	sc->pending_txs = 0;
 
 	ifp->if_flags &= ~(IFF_RUNNING | IFF_OACTIVE);
 
