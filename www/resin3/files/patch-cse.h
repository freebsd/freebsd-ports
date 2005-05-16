$FreeBSD$

--- modules/c/src/common/cse.h.orig	Thu May 12 12:54:14 2005
+++ modules/c/src/common/cse.h	Thu May 12 12:55:30 2005
@@ -339,6 +339,9 @@
 			     const char *host, int port,
 			     time_t now);
 
+static resin_host_t * cse_match_host_impl(config_t *config, const char *host_name, int
+		port, time_t now);
+
 cluster_srun_t *
 cse_add_cluster_server(cluster_t *cluster,
 		       const char *host, int port, const char *id,
