--- src/sys/net/if_pppoe.c.orig	2017-09-26 10:07:00 UTC
+++ src/sys/net/if_pppoe.c
@@ -227,7 +227,8 @@ pppoe_clone_create(struct if_clone *ifc,
 	if_initname(&sc->sc_sppp.pp_if, "pppoe", unit);
 	sc->sc_sppp.pp_if.if_softc = sc;
 	sc->sc_sppp.pp_if.if_mtu = PPPOE_MAXMTU;
-	sc->sc_sppp.pp_if.if_flags = IFF_SIMPLEX|IFF_POINTOPOINT|IFF_MULTICAST;
+	int tmp = IFF_SIMPLEX|IFF_POINTOPOINT|IFF_MULTICAST;
+	sc->sc_sppp.pp_if.if_flags = tmp;
 	sc->sc_sppp.pp_if.if_type = IFT_PPP;
 	sc->sc_sppp.pp_if.if_hdrlen = sizeof(struct ether_header) + PPPOE_HEADERLEN;
 	sc->sc_sppp.pp_if.if_dlt = DLT_PPP_ETHER;
