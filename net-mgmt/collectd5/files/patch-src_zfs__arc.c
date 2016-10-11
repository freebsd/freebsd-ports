--- src/zfs_arc.c.orig	2016-09-11 08:10:25 UTC
+++ src/zfs_arc.c
@@ -314,7 +314,6 @@ static int za_read (void)
 	za_read_derive (ksp, "demand_data_misses",       "cache_result", "demand_data-miss");
 	za_read_derive (ksp, "demand_metadata_misses",   "cache_result", "demand_metadata-miss");
 	za_read_derive (ksp, "prefetch_data_misses",     "cache_result", "prefetch_data-miss");
-	za_read_derive (ksp, "prefetch_metadata_misses", "cache_result", "prefetch_metadata-miss");
 	za_read_derive (ksp, "mfu_hits",                 "cache_result", "mfu-hit");
 	za_read_derive (ksp, "mfu_ghost_hits",           "cache_result", "mfu_ghost-hit");
 	za_read_derive (ksp, "mru_hits",                 "cache_result", "mru-hit");
