--- src/sys/net/agr/if_agr.c.orig	2016-08-02 11:51:10 UTC
+++ src/sys/net/agr/if_agr.c
@@ -317,6 +317,7 @@ agr_clone_create(struct if_clone *ifc, i
 {
 	struct agr_softc *sc;
 	struct ifnet *ifp;
+	int tmp = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
 
 	sc = agr_alloc_softc();
 	TAILQ_INIT(&sc->sc_ports);
@@ -330,7 +331,7 @@ agr_clone_create(struct if_clone *ifc, i
 	    ifc->ifc_name, unit);
 
 	ifp->if_softc = sc;
-	ifp->if_flags = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
+	ifp->if_flags = tmp;
 	ifp->if_start = agr_start;
 	ifp->if_ioctl = agr_ioctl;
 	IFQ_SET_READY(&ifp->if_snd);
