--- lib/mis/evolutionary/combine/multiway_combine.h.orig	2022-06-26 07:46:47 UTC
+++ lib/mis/evolutionary/combine/multiway_combine.h
@@ -112,7 +112,7 @@ class multiway_combine : public combine {
          * @param pool Pool of k-partitions.
          * @param part The partition that was applied.
          */
-        void apply_k_partition_kahip(MISConfig & config, graph_access & G, separator_pool *pool, partition & part);
+        void apply_k_partition_kahip(MISConfig & config, graph_access & G, separator_pool *pool, ::partition & part);
 
         /**
          * Get a random k-separator from the pool build with the KaHIP-interface.
