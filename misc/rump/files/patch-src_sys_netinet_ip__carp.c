--- src/sys/netinet/ip_carp.c.orig	2016-08-02 11:51:10 UTC
+++ src/sys/netinet/ip_carp.c
@@ -827,7 +827,8 @@ carp_clone_create(struct if_clone *ifc, int unit)
 	ifp->if_softc = sc;
 	snprintf(ifp->if_xname, sizeof ifp->if_xname, "%s%d", ifc->ifc_name,
 	    unit);
-	ifp->if_flags = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
+	int tmp = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
+	ifp->if_flags = tmp;
 	ifp->if_ioctl = carp_ioctl;
 	ifp->if_start = carp_start;
 	ifp->if_output = carp_output;
