--- udfclient.c.orig	Thu Aug  4 09:07:47 2005
+++ udfclient.c	Thu Aug  4 09:08:08 2005
@@ -748,7 +748,7 @@
 void udfclient_mget(int args, char *argv[]) {
 	struct udf_node *udf_node;
 	uint64_t start, now, totalsize, avg_speed;
-	char *node_name, *source_name, *target_name;
+	char *node_name=NULL, *source_name, *target_name;
 	int   arg, error;
 
 	if (args == 0) {
