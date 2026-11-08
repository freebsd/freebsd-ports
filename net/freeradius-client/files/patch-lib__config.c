--- lib/config.c.orig	2021-07-29 14:49:30 UTC
+++ lib/config.c
@@ -107,7 +107,7 @@ static int set_option_srv(char const *filename, int li
 	serv = (SERVER *) option->val;
 	if (serv == NULL) {
 		DEBUG(LOG_ERR, "option->val / server is NULL, allocating memory");
-		serv = malloc(sizeof(*serv));
+		serv = calloc(1, sizeof(*serv));
 		if (serv == NULL) {
 			rc_log(LOG_CRIT, "read_config: out of memory");
 			free(p_dupe);
@@ -360,8 +360,8 @@ rc_handle *rc_config_init(rc_handle *rh)
 
 	acct = find_option(rh, "acctserver", OT_ANY);
 	auth = find_option(rh, "authserver", OT_ANY);
-	authservers = malloc(sizeof(SERVER));
-	acctservers = malloc(sizeof(SERVER));
+	authservers = calloc(1, sizeof(SERVER));
+	acctservers = calloc(1, sizeof(SERVER));
 
 	if(authservers == NULL || acctservers == NULL)
 	{
@@ -541,7 +541,7 @@ int rc_conf_int(rc_handle const *rh, char const *optna
 
 	if (option != NULL) {
 		if (option->val) {
-			return *((int *)option->val);
+			return option->val ? *((int *)option->val) : 0;
 		} else {
 			rc_log(LOG_ERR, "rc_conf_int: config option %s was not set", optname);
 			return 0;
