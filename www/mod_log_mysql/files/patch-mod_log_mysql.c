--- mod_log_mysql.c.orig	Mon Jun 10 21:57:51 2002
+++ mod_log_mysql.c	Mon Jun 10 21:58:12 2002
@@ -41,7 +41,7 @@
  * -------------*/
 
 /* Declare ourselves so the configuration routines can find and know us. */
-module mysql_log_module;
+module log_mysql_module;
 
 /* The contents of these are known 'Apache wide' and are not variable
  * on a per-virtual-server basis.  Every virtual server 'knows' the
@@ -320,7 +320,7 @@
 	char *isvalid;
 	char *cookiebuf;
     
-	log_mysql_state *cls = get_module_config(r->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(r->server->module_config, &log_mysql_module);
 	
 	#ifdef DEBUG
 	  	ap_log_error(APLOG_MARK,DEBUGLEVEL,r->server,"watching for cookie '%s'", cls->cookie_name);
@@ -509,7 +509,7 @@
 void preserve_entry(request_rec *r, const char *query)
 {
 	FILE *fp;
-	log_mysql_state *cls = get_module_config(r->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(r->server->module_config, &log_mysql_module);
 	
 	fp = pfopen(r->pool, cls->preserve_file, "a");
 	if (fp == NULL)
@@ -548,7 +548,7 @@
 	 * at any time, hence the check. */
 	if ( retval != 0 ) 
     {
-			log_mysql_state *cls = get_module_config(r->server->module_config, &mysql_log_module);
+			log_mysql_state *cls = get_module_config(r->server->module_config, &log_mysql_module);
 		
 			/* Something went wrong, so start by trying to restart the db link. */
 		    ap_log_error(APLOG_MARK,ERRLEVEL,r->server,"attempting reconnect because API said: %s", mysql_error(mysql_log));
@@ -621,7 +621,7 @@
 
 const char *set_log_mysql_cookie(cmd_parms *parms, void *dummy, char *arg)
 {
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	cls->cookie_name = arg;
 	return NULL;
@@ -630,7 +630,7 @@
 const char *set_log_mysql_preserve_file(cmd_parms *parms, void *dummy, char *arg)
 {
 	char *pfile;
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	pfile = ap_pstrcat(parms->pool, "/tmp/", arg, NULL);
 	cls->preserve_file = pfile;
@@ -653,7 +653,7 @@
 
 const char *set_transfer_log_mysql_table(cmd_parms *parms, void *dummy, char *arg)
 {
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	if (massvirtual != 0)
 		ap_log_error(APLOG_MARK,WARNINGLEVEL,parms->server,"do not set MySQLTransferLogTable when MySQLMassVirtualHosting is On. Ignoring.");
@@ -664,7 +664,7 @@
 
 const char *set_mysql_transfer_log_format(cmd_parms *parms, void *dummy, char *arg)
 {
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	cls->transfer_log_format = arg;
 	return NULL;
@@ -680,7 +680,7 @@
 const char *add_referer_mysql_ignore(cmd_parms *parms, void *dummy, char *arg)
 {
 	char **addme;
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	addme = push_array(cls->referer_ignore_list);
 	*addme = pstrdup(cls->referer_ignore_list->pool, arg);
@@ -690,7 +690,7 @@
 const char *add_transfer_mysql_ignore(cmd_parms *parms, void *dummy, char *arg)
 {
 	char **addme;
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	addme = push_array(cls->transfer_ignore_list);
 	*addme = pstrdup(cls->transfer_ignore_list->pool, arg);
@@ -700,7 +700,7 @@
 const char *add_remhost_mysql_ignore(cmd_parms *parms, void *dummy, char *arg)
 {
 	char **addme;
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	addme = push_array(cls->remhost_ignore_list);
 	*addme = pstrdup(cls->remhost_ignore_list->pool, arg);
@@ -755,10 +755,10 @@
 {
 	server_rec *s;
 	
-    log_mysql_state main_conf = ap_get_module_config(main_server->module_config, &mysql_log_module);
+    log_mysql_state main_conf = ap_get_module_config(main_server->module_config, &log_mysql_module);
 
 	for (server_rec *s = main_server; s; s = s->next) {
-	    conf = ap_get_module_config(s->module_config, &mysql_log_module);
+	    conf = ap_get_module_config(s->module_config, &log_mysql_module);
 	    if (conf->transfer_log_format == NULL && s != main_server) {
 	        *conf = *main_conf;
 		}
@@ -847,7 +847,7 @@
 int log_mysql_transaction(request_rec *orig)
 {
 	char **ptrptr, **ptrptr2;
-	log_mysql_state *cls = get_module_config(orig->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(orig->server->module_config, &log_mysql_module);
 	const char *str;
 	request_rec *r;
 
@@ -1042,7 +1042,7 @@
 
 
 /* The configuration array that sets up the hooks into the module. */
-module mysql_log_module = {
+module log_mysql_module = {
 	STANDARD_MODULE_STUFF,
 	NULL,					 /* module initializer 				*/
 	NULL,					 /* create per-dir config 			*/
