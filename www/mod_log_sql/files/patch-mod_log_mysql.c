--- mod_log_mysql.c.orig	Fri Feb  1 11:02:55 2002
+++ mod_log_mysql.c	Fri Feb  1 11:03:36 2002
@@ -31,7 +31,7 @@
 
 
 /* DECLARATIONS */
-module mysql_log_module;
+module log_mysql_module;
 
 MYSQL sql_server, *mysql_log = NULL;
 
@@ -539,7 +539,7 @@
 
 const char *set_referer_log_mysql_table(cmd_parms *parms, void *dummy, char *arg)
 {
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	cls->referer_table_name = arg;
 	return NULL;
@@ -548,7 +548,7 @@
 
 const char *set_agent_log_mysql_table(cmd_parms *parms, void *dummy, char *arg)
 {
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	cls->agent_table_name = arg;
 	return NULL;
@@ -557,7 +557,7 @@
 
 const char *set_transfer_log_mysql_table(cmd_parms *parms, void *dummy, char *arg)
 {
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	cls->transfer_table_name = arg;
 	return NULL;
@@ -566,7 +566,7 @@
 
 const char *set_transfer_log_format(cmd_parms *parms, void *dummy, char *arg)
 {
-	log_mysql_state *cls = get_module_config(parms->server->module_config, &mysql_log_module);
+	log_mysql_state *cls = get_module_config(parms->server->module_config, &log_mysql_module);
 
 	cls->transfer_log_format = arg;
 	return NULL;
@@ -604,7 +604,7 @@
 {
 	char **addme;
 	log_mysql_state *cls = get_module_config(parms->server->module_config,
-						 &mysql_log_module);
+						 &log_mysql_module);
 
 	addme = push_array(cls->referer_ignore_list);
 	*addme = pstrdup(cls->referer_ignore_list->pool, arg);
@@ -615,7 +615,7 @@
 {
 	char **addme;
 	log_mysql_state *cls = get_module_config(parms->server->module_config,
-						 &mysql_log_module);
+						 &log_mysql_module);
 
 	addme = push_array(cls->transfer_ignore_list);
 	*addme = pstrdup(cls->transfer_ignore_list->pool, arg);
@@ -626,7 +626,7 @@
 {
 	char **addme;
 	log_mysql_state *cls = get_module_config(parms->server->module_config,
-						 &mysql_log_module);
+						 &log_mysql_module);
 
 	addme = push_array(cls->remhost_ignore_list);
 	*addme = pstrdup(cls->remhost_ignore_list->pool, arg);
@@ -702,7 +702,7 @@
 {
 	char **ptrptr, **ptrptr2;
 	log_mysql_state *cls = get_module_config(orig->server->module_config,
-						 &mysql_log_module);
+						 &log_mysql_module);
 	char *str;
 	const char *referer;
 	request_rec *r;
@@ -856,7 +856,7 @@
 
 
 /* The configuration array that sets up the hooks into the module. */
-module mysql_log_module = {
+module log_mysql_module = {
 	STANDARD_MODULE_STUFF,
 	NULL,					 /* initializer */
 	NULL,					 /* create per-dir config */
