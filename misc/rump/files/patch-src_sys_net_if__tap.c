--- src/sys/net/if_tap.c.orig	2017-09-26 10:11:03 UTC
+++ src/sys/net/if_tap.c
@@ -332,7 +332,8 @@ tap_attach(device_t parent, device_t sel
 	ifp = &sc->sc_ec.ec_if;
 	strcpy(ifp->if_xname, device_xname(self));
 	ifp->if_softc	= sc;
-	ifp->if_flags	= IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
+	int tmp = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
+	ifp->if_flags	= tmp;
 	ifp->if_ioctl	= tap_ioctl;
 	ifp->if_start	= tap_start;
 	ifp->if_stop	= tap_stop;
