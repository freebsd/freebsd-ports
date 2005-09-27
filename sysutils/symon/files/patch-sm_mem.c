--- platform/FreeBSD/sm_mem.c.orig	Tue Sep 27 18:32:40 2005
+++ platform/FreeBSD/sm_mem.c	Tue Sep 27 19:00:29 2005
@@ -119,6 +119,7 @@
     me_stats[1] = pagetob(me_vmtotal.t_rm);
     me_stats[2] = pagetob(me_vmtotal.t_free);
 
+    me_stats[3] = me_stats[4] = 0;
 #ifdef HAS_XSWDEV
     vmnswp_siz = sizeof (int);
     if (sysctl(me_vmnswp_mib_nam, me_vmnswp_mib_len, &vmnswp_dat, (void *)&vmnswp_siz, NULL, 0) < 0) {
@@ -134,8 +135,6 @@
 	me_stats[3] += (vmiswp_dat.xsw_used * DEV_BSIZE);
 	me_stats[4] += (vmiswp_dat.xsw_nblks * DEV_BSIZE);
     }
-#else
-    me_stats[3] = me_stats[4] = 0;
 #endif
 
     return snpack(symon_buf, maxlen, s, MT_MEM,
