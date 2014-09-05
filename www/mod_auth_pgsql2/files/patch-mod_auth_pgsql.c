--- ./mod_auth_pgsql.c.orig	2006-01-05 15:15:13.000000000 +0100
+++ ./mod_auth_pgsql.c	2014-08-25 16:53:20.000000000 +0200
@@ -1060,8 +1060,13 @@
 		apr_snprintf(sql, MAX_STRING_LEN, ", %s",
 					 sec->auth_pg_log_addrs_field);
 		strncat(fields, sql, MAX_STRING_LEN - strlen(fields) - 1);
+#if MODULE_MAGIC_NUMBER_MAJOR >= 20111130
+		apr_snprintf(sql, MAX_STRING_LEN, ", '%s'",
+					 r->useragent_ip);
+#else
 		apr_snprintf(sql, MAX_STRING_LEN, ", '%s'",
 					 r->connection->remote_ip);
+#endif
 		strncat(values, sql, MAX_STRING_LEN - strlen(values) - 1);
 	}
 	if (sec->auth_pg_log_pwd_field) {	/* Password field , clear WARNING */
