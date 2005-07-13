--- bsd/swapinternal.cc.orig	Tue Nov 16 23:16:20 1999
+++ bsd/swapinternal.cc	Tue Aug 21 11:27:26 2001
@@ -459,16 +459,17 @@
 #endif /* XOSVIEW_FREEBSD */
 
 void
-BSDGetSwapInfo(int* total, int* free)
+BSDGetSwapInfo(int64_t* total, int64_t* free)
 {
-        int i, avail, npfree, used=0, xsize, xfree;
+        int i, npfree, xsize, xfree;
+        int64_t avail, used=0;
 
 	fetchswap();
 #ifdef USE_KVM_GETSWAPINFO
 	avail = used = 0;
 	if (kvnsw == 0) {
-		avail += pagesize * kvmsw[0].ksw_total;
-		used += pagesize * kvmsw[0].ksw_used;
+		avail += pagesize * (int64_t)kvmsw[0].ksw_total;
+		used += pagesize * (int64_t)kvmsw[0].ksw_used;
 	}
 	*total = avail;
 	*free = avail - used;
