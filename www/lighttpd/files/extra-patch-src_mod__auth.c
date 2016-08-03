--- src/mod_auth.c.orig	2016-07-16 10:06:16 UTC
+++ src/mod_auth.c
@@ -13,6 +13,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <unistd.h>
+#include <mysql/mysql.h>
 
 handler_t auth_ldap_init(server *srv, mod_auth_plugin_config *s);
 
@@ -84,6 +85,19 @@ FREE_FUNC(mod_auth_free) {
 
 			if (s->ldap) ldap_unbind_s(s->ldap);
 #endif
+			buffer_free(s->auth_mysql_host);
+			buffer_free(s->auth_mysql_user);
+			buffer_free(s->auth_mysql_pass);
+			buffer_free(s->auth_mysql_db);
+			buffer_free(s->auth_mysql_socket);
+			buffer_free(s->auth_mysql_users_table);
+			buffer_free(s->auth_mysql_col_user);
+			buffer_free(s->auth_mysql_col_pass);
+			buffer_free(s->auth_mysql_col_realm);
+			buffer_free(s->auth_mysql_domains_table);
+			buffer_free(s->auth_mysql_col_domain);
+			buffer_free(s->auth_mysql_domains_table_col_domain_id);
+			buffer_free(s->auth_mysql_users_table_col_domain_id);
 
 			free(s);
 		}
@@ -122,6 +136,21 @@ static int mod_auth_patch_connection(ser
 	PATCH(ldap_filter_post);
 #endif
 
+	PATCH(auth_mysql_host);
+	PATCH(auth_mysql_user);
+	PATCH(auth_mysql_pass);
+	PATCH(auth_mysql_db);
+	PATCH(auth_mysql_port);
+	PATCH(auth_mysql_socket);
+	PATCH(auth_mysql_users_table);
+	PATCH(auth_mysql_col_user);
+	PATCH(auth_mysql_col_pass);
+	PATCH(auth_mysql_col_realm);
+	PATCH(auth_mysql_domains_table);
+	PATCH(auth_mysql_col_domain);
+	PATCH(auth_mysql_domains_table_col_domain_id);
+	PATCH(auth_mysql_users_table_col_domain_id);
+
 	/* skip the first, the global context */
 	for (i = 1; i < srv->config_context->used; i++) {
 		data_config *dc = (data_config *)srv->config_context->data[i];
@@ -171,6 +200,34 @@ static int mod_auth_patch_connection(ser
 				PATCH(auth_ldap_bindpw);
 			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.ldap.allow-empty-pw"))) {
 				PATCH(auth_ldap_allow_empty_pw);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.host"))) {
+				PATCH(auth_mysql_host);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.user"))) {
+				PATCH(auth_mysql_user);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.pass"))) {
+				PATCH(auth_mysql_pass);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.db"))) {
+				PATCH(auth_mysql_db);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.port"))) {
+				PATCH(auth_mysql_port);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.socket"))) {
+				PATCH(auth_mysql_user);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.users_table"))) {
+				PATCH(auth_mysql_users_table);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.col_user"))) {
+				PATCH(auth_mysql_col_user);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.col_pass"))) {
+				PATCH(auth_mysql_col_pass);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.col_realm"))) {
+				PATCH(auth_mysql_col_realm);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.domains_table"))) {
+				PATCH(auth_mysql_domains_table);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.col_domain"))) {
+				PATCH(auth_mysql_col_domain);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.domains_table_col_domain_id"))) {
+				PATCH(auth_mysql_domains_table_col_domain_id);
+			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.users_table_col_domain_id"))) {
+				PATCH(auth_mysql_users_table_col_domain_id);
 			}
 		}
 	}
@@ -362,10 +419,25 @@ SETDEFAULTS_FUNC(mod_auth_set_defaults) 
 		{ "auth.backend.ldap.starttls",     NULL, T_CONFIG_BOOLEAN, T_CONFIG_SCOPE_CONNECTION }, /* 8 */
  		{ "auth.backend.ldap.bind-dn",      NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 9 */
  		{ "auth.backend.ldap.bind-pw",      NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 10 */
-		{ "auth.backend.ldap.allow-empty-pw",     NULL, T_CONFIG_BOOLEAN, T_CONFIG_SCOPE_CONNECTION }, /* 11 */
+		{ "auth.backend.ldap.allow-empty-pw",     NULL, T_CONFIG_BOOLEAN, T_CONFIG_SCOPE_CONNECTION },
 		{ "auth.backend.htdigest.userfile", NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 12 */
 		{ "auth.backend.htpasswd.userfile", NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 13 */
 		{ "auth.debug",                     NULL, T_CONFIG_SHORT, T_CONFIG_SCOPE_CONNECTION },  /* 14 */
+		{ "auth.backend.mysql.host",        NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.user",        NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.pass",        NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.db",          NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.port",        NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.socket",      NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.users_table", NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.col_user",    NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.col_pass",    NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.col_realm",   NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 23 */
+		{ "auth.backend.mysql.domains_table",               NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.col_domain",                  NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.domains_table_col_domain_id", NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+		{ "auth.backend.mysql.users_table_col_domain_id",   NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 27 */
+
 		{ NULL,                             NULL, T_CONFIG_UNSET, T_CONFIG_SCOPE_UNSET }
 	};
 
@@ -394,6 +466,22 @@ SETDEFAULTS_FUNC(mod_auth_set_defaults) 
 		s->auth_debug = 0;
 
 		s->auth_require = array_init();
+		s->mysql_conn                             = NULL;
+		s->auth_mysql_host                        = buffer_init();
+		s->auth_mysql_user                        = buffer_init();
+		s->auth_mysql_pass                        = buffer_init();
+		s->auth_mysql_db                          = buffer_init();
+		s->auth_mysql_port                        = buffer_init();
+		s->auth_mysql_socket                      = buffer_init();
+		s->auth_mysql_users_table                 = buffer_init();
+		s->auth_mysql_col_user                    = buffer_init();
+		s->auth_mysql_col_pass                    = buffer_init();
+		s->auth_mysql_col_realm                   = buffer_init();
+		s->auth_mysql_domains_table               = buffer_init();
+		s->auth_mysql_col_domain                  = buffer_init();
+		s->auth_mysql_domains_table_col_domain_id = buffer_init();
+		s->auth_mysql_users_table_col_domain_id   = buffer_init();
+
 
 #ifdef USE_LDAP
 		s->ldap_filter_pre = buffer_init();
@@ -416,7 +504,20 @@ SETDEFAULTS_FUNC(mod_auth_set_defaults) 
 		cv[12].destination = s->auth_htdigest_userfile;
 		cv[13].destination = s->auth_htpasswd_userfile;
 		cv[14].destination = &(s->auth_debug);
-
+		cv[15].destination = s->auth_mysql_host;
+		cv[16].destination = s->auth_mysql_user;
+		cv[17].destination = s->auth_mysql_pass;
+		cv[18].destination = s->auth_mysql_db;
+		cv[19].destination = s->auth_mysql_port;
+		cv[20].destination = s->auth_mysql_socket;
+		cv[21].destination = s->auth_mysql_users_table;
+		cv[22].destination = s->auth_mysql_col_user;
+		cv[23].destination = s->auth_mysql_col_pass;
+		cv[24].destination = s->auth_mysql_col_realm;
+		cv[25].destination = s->auth_mysql_domains_table;
+		cv[26].destination = s->auth_mysql_col_domain;
+		cv[27].destination = s->auth_mysql_domains_table_col_domain_id;
+		cv[28].destination = s->auth_mysql_users_table_col_domain_id;
 		p->config_storage[i] = s;
 
 		if (0 != config_insert_values_global(srv, config->value, cv, i == 0 ? T_CONFIG_SCOPE_SERVER : T_CONFIG_SCOPE_CONNECTION)) {
@@ -432,6 +533,8 @@ SETDEFAULTS_FUNC(mod_auth_set_defaults) 
 				s->auth_backend = AUTH_BACKEND_PLAIN;
 			} else if (0 == strcmp(s->auth_backend_conf->ptr, "ldap")) {
 				s->auth_backend = AUTH_BACKEND_LDAP;
+			} else if (0 == strcmp(s->auth_backend_conf->ptr, "mysql")) {
+				s->auth_backend = AUTH_BACKEND_MYSQL;
 			} else {
 				log_error_write(srv, __FILE__, __LINE__, "sb", "auth.backend not supported:", s->auth_backend_conf);
 
@@ -573,6 +676,31 @@ SETDEFAULTS_FUNC(mod_auth_set_defaults) 
 				return (ret);
 			break;
 		}
+		case AUTH_BACKEND_MYSQL: {
+			int port = atoi(s->auth_mysql_port->ptr);
+
+			/* ignore if auth_mysql_socket is invalid */
+			if (p->conf.auth_mysql_socket == NULL)
+				return HANDLER_GO_ON;
+			if (p->conf.auth_mysql_socket->ptr != NULL)
+				if (0 == strcmp(s->auth_mysql_socket->ptr, "")) s->auth_mysql_socket->ptr = NULL;
+
+			s->mysql_conn = mysql_init(NULL);
+			if (!mysql_real_connect(s->mysql_conn, s->auth_mysql_host->ptr, s->auth_mysql_user->ptr, s->auth_mysql_pass->ptr, s->auth_mysql_db->ptr, port, NULL, 0))
+			{
+				log_error_write(srv, __FILE__, __LINE__, "sbsbsbsbss",
+						"opening connection to mysql:", s->auth_mysql_host,
+						"user:", s->auth_mysql_user,
+						"pass:", s->auth_mysql_pass,
+						"db:", s->auth_mysql_db,
+						"failed:", strerror(errno));
+
+				return HANDLER_ERROR;
+			}
+			mysql_close(s->mysql_conn);
+
+			break;
+		}
 		default:
 			break;
 		}
