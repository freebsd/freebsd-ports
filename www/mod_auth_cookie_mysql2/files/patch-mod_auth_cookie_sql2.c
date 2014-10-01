--- mod_auth_cookie_sql2.c.orig	2009-06-17 23:28:01 UTC
+++ mod_auth_cookie_sql2.c
@@ -182,7 +182,11 @@
 		    ap_log_rerror(APLOG_MARK, APLOG_ERR|APLOG_NOERRNO, 0, r, ERRTAG "valid cookie found, data: %s", cookies);
 #endif
 
+#if MODULE_MAGIC_NUMBER_MAJOR >= 20111130
+		    db_ret=check_against_db(conf, r, conf->cookiename, value, username,r->useragent_ip, conf->sql_addon, tc);
+#else
 		    db_ret=check_against_db(conf, r, conf->cookiename, value, username,r->connection->remote_ip, conf->sql_addon, tc);
+#endif
 		}
 	    }
 	}
@@ -205,7 +209,13 @@
 	    *value = '\0';
 	    value++;
 
-	    if ((db_ret=check_against_db(conf, r, cookies, value, username, r->connection->remote_ip, conf->sql_addon, tc)) == RET_AUTHORIZED) {
+	    if ((db_ret=check_against_db(conf, r, cookies, value, username,
+#if MODULE_MAGIC_NUMBER_MAJOR >= 20111130
+		    r->useragent_ip,
+#else
+		    r->connection->remote_ip,
+#endif
+		    conf->sql_addon, tc)) == RET_AUTHORIZED) {
 		// found valid cookie
 
 #ifdef AUTH_COOKIE_SQL2_DEBUG
