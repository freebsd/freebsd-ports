--- lib/config.c
+++ lib/config.c
@@ -106,7 +106,7 @@
 	serv = (SERVER *) option->val;
 	if (serv == NULL) {
 		DEBUG(LOG_ERR, "option->val / server is NULL, allocating memory");
-		serv = malloc(sizeof(*serv));
+		serv = calloc(1, sizeof(*serv));
 		if (serv == NULL) {
 			rc_log(LOG_CRIT, "read_config: out of memory");
 			free(p_dupe);
@@ -313,8 +313,8 @@
 
         authservers = rc_conf_srv(rh, "authserver"); 
 	acctservers = rc_conf_srv(rh, "acctserver");
-	authservers = malloc(sizeof(SERVER));
-	acctservers = malloc(sizeof(SERVER));
+	authservers = calloc(1, sizeof(SERVER));
+	acctservers = calloc(1, sizeof(SERVER));
 
 	if(authservers == NULL || acctservers == NULL)
 	{
@@ -491,7 +491,7 @@
 	option = find_option(rh, optname, OT_INT|OT_AUO);
 
 	if (option != NULL) {
-		return *((int *)option->val);
+		return option->val ? *((int *)option->val) : 0;
 	} else {
 		rc_log(LOG_CRIT, "rc_conf_int: unkown config option requested: %s", optname);
 		abort();
@@ -528,17 +528,21 @@
 	struct stat st;
 	char	    *file;
 #endif
+	SERVER *srv = NULL;
 
-	if (!(rc_conf_srv(rh, "authserver")->max))
+	srv = rc_conf_srv(rh, "authserver");
+	if (!srv || !srv->max)
 	{
 		rc_log(LOG_ERR,"%s: no authserver specified", filename);
 		return -1;
 	}
-	if (!(rc_conf_srv(rh, "acctserver")->max))
+	srv = rc_conf_srv(rh, "acctserver");
+	if (!srv || !srv->max)
 	{
 		rc_log(LOG_ERR,"%s: no acctserver specified", filename);
 		return -1;
 	}
+
 	if (!rc_conf_str(rh, "servers"))
 	{
 		rc_log(LOG_ERR,"%s: no servers file specified", filename);
