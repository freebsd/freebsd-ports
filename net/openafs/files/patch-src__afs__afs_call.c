--- ./src/afs/afs_call.c.orig	2011-06-16 13:25:10.000000000 -0400
+++ ./src/afs/afs_call.c	2011-06-16 13:26:19.000000000 -0400
@@ -1253,7 +1253,9 @@
 	afs_warn("afs: WARM ");
     afs_warn("shutting down of: vcaches... ");
 
+#if !defined(AFS_FBSD_ENV)
     afs_FlushAllVCaches();
+#endif
 
     afs_warn("CB... ");
 
