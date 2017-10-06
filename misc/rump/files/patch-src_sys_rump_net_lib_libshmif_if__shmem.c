--- src/sys/rump/net/lib/libshmif/if_shmem.c.orig	2017-09-26 10:09:42 UTC
+++ src/sys/rump/net/lib/libshmif/if_shmem.c
@@ -176,7 +176,8 @@ allocif(int unit, struct shmif_sc **scp)
 
 	snprintf(ifp->if_xname, sizeof(ifp->if_xname), "shmif%d", unit);
 	ifp->if_softc = sc;
-	ifp->if_flags = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
+	int tmp = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
+	ifp->if_flags = tmp;
 	ifp->if_init = shmif_init;
 	ifp->if_ioctl = shmif_ioctl;
 	ifp->if_start = shmif_start;
