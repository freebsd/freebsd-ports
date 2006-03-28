--- platform/FreeBSD/sm_mem.c.orig	Mon Mar 27 06:06:18 2006
+++ platform/FreeBSD/sm_mem.c	Mon Mar 27 06:45:54 2006
@@ -131,12 +131,12 @@
     }
     for (i = 0; i < vmnswp_dat; i++) {
 	struct xswdev vmiswp_dat;
-	int vmiswp_siz;
+	int vmiswp_siz = sizeof vmiswp_dat;
 	me_vmiswp_mib_nam[me_vmiswp_mib_len] = i;
 	if (sysctl(me_vmiswp_mib_nam, me_vmiswp_mib_len + 1, &vmiswp_dat, (void *)&vmiswp_siz, NULL, 0) < 0)
 		continue;
-	me_stats[3] += (vmiswp_dat.xsw_used * DEV_BSIZE);
-	me_stats[4] += (vmiswp_dat.xsw_nblks * DEV_BSIZE);
+	me_stats[3] += pagetob(vmiswp_dat.xsw_used);
+	me_stats[4] += pagetob(vmiswp_dat.xsw_nblks);
     }
 #endif
 
