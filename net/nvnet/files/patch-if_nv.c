--- src/if_nv.c.orig	Sat Nov  8 05:03:00 2003
+++ src/if_nv.c	Tue Dec  9 08:54:39 2003
@@ -457,8 +457,12 @@
 	/* Setup interface parameters */
 	ifp = &sc->sc_if;
 	ifp->if_softc = sc;
+#if __FreeBSD_version < 501113
 	ifp->if_unit = unit;
 	ifp->if_name = "nv";
+#else
+	if_initname(ifp, "nv", unit);
+#endif
 	ifp->if_flags = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
 	ifp->if_ioctl = nv_ioctl;
 	ifp->if_output = ether_output;
