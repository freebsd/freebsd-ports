--- mod_log_mysql.c	2003-11-01 12:21:28.000000000 +0200
+++ mod_log_mysql.c.new	2010-11-28 17:01:06.000000000 +0200
@@ -172,11 +172,13 @@
 {
   mysql_log *l = param;
   MYSQL *db;
+  my_bool do_reconnect = 1;
     
   db = apr_palloc(p, sizeof(MYSQL));
 
   mysql_init(db);
   mysql_options(db, MYSQL_READ_DEFAULT_GROUP, "mod_log_mysql");
+  mysql_options(db, MYSQL_OPT_RECONNECT,&do_reconnect);
 
   if (! mysql_real_connect(db, l->host, l->user, l->passwd, l->database, l->port, l->socket, 0)) {
       ap_log_perror(APLOG_MARK, APLOG_CRIT, 0, p, "log database %s: %s", l->uri, mysql_error(db));
