--- src/mysql.c.orig	2005-09-04 03:34:02 UTC
+++ src/mysql.c
@@ -196,6 +196,7 @@ _nss_mysql_connect_sql (MYSQL_RES **mresult)
   int retval;
   sql_server_t *server = &conf.sql.server;
   unsigned int port;
+  my_bool reconnect = 1;
 
   DENTER
 
@@ -238,8 +239,9 @@ _nss_mysql_connect_sql (MYSQL_RES **mresult)
           DSRETURN (NSS_UNAVAIL)
         }
       ci.valid = ntrue;
-      ci.link.reconnect = 0; /* Safety: We can't let MySQL assume socket is
-                                still valid; see _nss_mysql_validate_socket */
+      /* Safety: We can't let MySQL assume socket is still valid;
+         see _nss_mysql_validate_socket */
+      mysql_options(&ci.link, MYSQL_OPT_RECONNECT, &reconnect); 
       DSRETURN (NSS_SUCCESS)
     }
   _nss_mysql_log (LOG_ALERT, "Connection to server '%s' failed: %s",
