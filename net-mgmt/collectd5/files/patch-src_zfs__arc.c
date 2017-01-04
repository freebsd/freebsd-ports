--- src/zfs_arc.c.orig	2016-12-12 03:03:36.728278972 -0500
+++ src/zfs_arc.c	2017-01-03 08:15:23.751003000 -0500
@@ -286,8 +286,6 @@
   za_read_derive(ksp, "prefetch_metadata_hits", "cache_result",
                  "prefetch_metadata-hit");
   za_read_derive(ksp, "demand_data_misses", "cache_result", "demand_data-miss");
-  za_read_derive(ksp, "demand_metadata_misses", "cache_result",
-                 "demand_metadata-miss");
   za_read_derive(ksp, "prefetch_data_misses", "cache_result",
                  "prefetch_data-miss");
   za_read_derive(ksp, "prefetch_metadata_misses", "cache_result",
