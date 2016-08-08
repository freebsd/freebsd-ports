--- src/zfs_arc.c.orig	2016-07-26 05:57:19 UTC
+++ src/zfs_arc.c
@@ -270,10 +270,6 @@ static int za_read (void)
 	za_read_derive (ksp, "deleted",  "cache_operation", "deleted");
 #if __FreeBSD__
 	za_read_derive (ksp, "allocated","cache_operation", "allocated");
-#if defined(__FreeBSD_version) && (__FreeBSD_version < 1002501)
-	/* stolen removed from sysctl kstat.zfs.misc.arcstats on FreeBSD 10.2+ */
-	za_read_derive (ksp, "stolen",   "cache_operation", "stolen");
-#endif
 #endif
 
 	/* Issue indicators */
