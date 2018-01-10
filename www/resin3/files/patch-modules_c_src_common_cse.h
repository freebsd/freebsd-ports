--- modules/c/src/common/cse.h.orig	2013-10-28 16:37:43 UTC
+++ modules/c/src/common/cse.h
@@ -367,6 +367,9 @@ resin_host_t *cse_match_host(config_t *config,
 			     const char *host, int port,
 			     time_t now);
 
+static resin_host_t * cse_match_host_impl(config_t *config, const char *host_name, int
+		port, time_t now);
+
 cluster_srun_t *
 cse_add_cluster_server(mem_pool_t *pool, cluster_t *cluster,
 		       const char *host, int port, const char *id,
