--- src/zfs_arc.c.orig	2017-01-23 07:53:57 UTC
+++ src/zfs_arc.c
@@ -286,8 +286,6 @@ static int za_read(void) {
   za_read_derive(ksp, "prefetch_metadata_hits", "cache_result",
                  "prefetch_metadata-hit");
   za_read_derive(ksp, "demand_data_misses", "cache_result", "demand_data-miss");
-  za_read_derive(ksp, "demand_metadata_misses", "cache_result",
-                 "demand_metadata-miss");
   za_read_derive(ksp, "prefetch_data_misses", "cache_result",
                  "prefetch_data-miss");
   za_read_derive(ksp, "prefetch_metadata_misses", "cache_result",
