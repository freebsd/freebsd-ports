--- src/pm/hydra/lib/tools/bootstrap/external/slurm_query_node_list.c.orig	2023-06-06 14:38:37 UTC
+++ src/pm/hydra/lib/tools/bootstrap/external/slurm_query_node_list.c
@@ -26,7 +26,7 @@ static HYD_status list_to_nodes(char *str)
 #if defined(HAVE_SLURM)
 static HYD_status list_to_nodes(char *str)
 {
-    hostlist_t hostlist;
+    hostlist_t *hostlist;
     char *host;
     int k = 0;
     HYD_status status = HYD_SUCCESS;
