--- src/sys/net/if_loop.c.orig	2016-08-02 11:51:10 UTC
+++ src/sys/net/if_loop.c
@@ -150,13 +150,14 @@ static int
 loop_clone_create(struct if_clone *ifc, int unit)
 {
 	struct ifnet *ifp;
+	int tmp = IFF_LOOPBACK | IFF_MULTICAST | IFF_RUNNING;
 
 	ifp = if_alloc(IFT_LOOP);
 
 	if_initname(ifp, ifc->ifc_name, unit);
 
 	ifp->if_mtu = LOMTU;
-	ifp->if_flags = IFF_LOOPBACK | IFF_MULTICAST | IFF_RUNNING;
+	ifp->if_flags = tmp;
 	ifp->if_extflags = IFEF_OUTPUT_MPSAFE;
 	ifp->if_ioctl = loioctl;
 	ifp->if_output = looutput;
