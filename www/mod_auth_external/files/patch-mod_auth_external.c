--- mod_auth_external.c.orig	Tue May 15 00:49:04 2001
+++ mod_auth_external.c	Tue May 15 00:50:55 2001
@@ -239,7 +239,7 @@
  * Structure for the module itself
  */
 
-module external_auth_module;
+module auth_external_module;
 
 /*
  *  Data types for per-dir and server configuration
@@ -303,7 +303,7 @@
     extauth_server_config_rec *sc_rec;
 
     sc_rec= ap_get_module_config( cmd->server->module_config,
-	&external_auth_module);
+	&auth_external_module);
 
     ap_table_set( sc_rec->auth_extpath, keyword, path );
 
@@ -323,7 +323,7 @@
     extauth_server_config_rec *sc_rec;
 
     sc_rec= ap_get_module_config( cmd->server->module_config,
-	&external_auth_module);
+	&auth_external_module);
 
     ap_table_set( sc_rec->group_extpath, keyword, path );
 
@@ -343,7 +343,7 @@
 	extauth_server_config_rec *sc_rec;
 
 	sc_rec= ap_get_module_config( cmd->server->module_config,
-	    &external_auth_module);
+	    &auth_external_module);
 
 	ap_table_set( sc_rec->auth_extmethod, keyword, method );
 	
@@ -361,7 +361,7 @@
 	extauth_server_config_rec *sc_rec;
 
 	sc_rec= ap_get_module_config( cmd->server->module_config,
-	    &external_auth_module);
+	    &auth_external_module);
 
 	ap_table_set( sc_rec->group_extmethod, keyword, method );
 	
@@ -565,11 +565,11 @@
 {
     extauth_dir_config_rec *dir_config_rec=
 	(extauth_dir_config_rec *)ap_get_module_config(r->per_dir_config,
-	&external_auth_module);
+	&auth_external_module);
 
     extauth_server_config_rec *server_config_rec=
 	(extauth_server_config_rec *)ap_get_module_config(r->server->module_config,
-	&external_auth_module);
+	&auth_external_module);
 
     const char *sent_pw;
     int res, code= 1;
@@ -679,11 +679,11 @@
 {
     extauth_dir_config_rec *dir_config_rec=
 	(extauth_dir_config_rec *)ap_get_module_config(r->per_dir_config,
-	&external_auth_module);
+	&auth_external_module);
 
     extauth_server_config_rec *server_config_rec=
 	(extauth_server_config_rec *)ap_get_module_config(r->server->module_config,
-	&external_auth_module);
+	&auth_external_module);
 
     conn_rec *c= r->connection;
 
@@ -787,7 +787,7 @@
     return AUTH_REQUIRED;
 }
 
-module external_auth_module= {
+module auth_external_module= {
     STANDARD_MODULE_STUFF,
     NULL,			 /* initializer */
     create_extauth_dir_config,	 /* dir config creater */
