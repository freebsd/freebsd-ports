--- storage/authreg_mysql.c.orig	2018-10-22 23:49:34 UTC
+++ storage/authreg_mysql.c
@@ -489,6 +489,8 @@ DLLEXPORT int ar_init(authreg_t ar) {
     MYSQL *conn;
     mysqlcontext_t mysqlcontext;
     int fail = 0;
+    /* enable reconnect */
+    my_bool reconnect= 1;
 
     /* configure the database context with field names and SQL statements */
     mysqlcontext = (mysqlcontext_t) malloc( sizeof( struct mysqlcontext_st ) );
@@ -620,6 +622,7 @@ DLLEXPORT int ar_init(authreg_t ar) {
 
     mysql_options(conn, MYSQL_READ_DEFAULT_GROUP, "jabberd");
     mysql_options(conn, MYSQL_SET_CHARSET_NAME, "utf8");
+    mysql_options(conn, MYSQL_OPT_RECONNECT, (void *)&reconnect);
 
     /* connect with CLIENT_INTERACTIVE to get a (possibly) higher timeout value than default */
     if(mysql_real_connect(conn, host, user, pass, dbname, atoi(port), NULL, CLIENT_INTERACTIVE) == NULL) {
@@ -628,9 +631,6 @@ DLLEXPORT int ar_init(authreg_t ar) {
     }
 
     mysql_query(conn, "SET NAMES 'utf8'");
-
-    /* Set reconnect flag to 1 (set to 0 by default from mysql 5 on) */
-    conn->reconnect = 1;
 
     ar->user_exists = _ar_mysql_user_exists;
     if (MPC_PLAIN == mysqlcontext->password_type) {
