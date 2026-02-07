--- lib/config.c.orig	2015-01-19 16:18:26 UTC
+++ lib/config.c
@@ -106,7 +106,7 @@ static int set_option_srv(char const *filename, int li
 	serv = (SERVER *) option->val;
 	if (serv == NULL) {
 		DEBUG(LOG_ERR, "option->val / server is NULL, allocating memory");
-		serv = malloc(sizeof(*serv));
+		serv = calloc(1, sizeof(*serv));
 		if (serv == NULL) {
 			rc_log(LOG_CRIT, "read_config: out of memory");
 			free(p_dupe);
@@ -319,8 +319,8 @@ rc_config_init(rc_handle *rh)
 
 	acct = find_option(rh, "acctserver", OT_ANY);
 	auth = find_option(rh, "authserver", OT_ANY);
-	authservers = malloc(sizeof(SERVER));
-	acctservers = malloc(sizeof(SERVER));
+	authservers = calloc(1, sizeof(SERVER));
+	acctservers = calloc(1, sizeof(SERVER));
 
 	if(authservers == NULL || acctservers == NULL)
 	{
@@ -504,7 +504,7 @@ int rc_conf_int(rc_handle const *rh, char const *optna
 
 	if (option != NULL) {
 		if (option->val) {
-			return *((int *)option->val);
+			return option->val ? *((int *)option->val) : 0;
 		} else {
 			rc_log(LOG_ERR, "rc_conf_int: config option %s was not set", optname);
 			return 0;
@@ -545,17 +545,21 @@ int test_config(rc_handle const *rh, char const *filen
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
