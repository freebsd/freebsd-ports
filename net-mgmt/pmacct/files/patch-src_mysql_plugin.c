--- src/mysql_plugin.c.orig	2019-01-06 20:48:02.557254000 +0100
+++ src/mysql_plugin.c	2019-01-06 20:49:11.176001000 +0100
@@ -668,8 +668,9 @@
   MYSQL *dbptr = db->desc;
 
   if (!db->fail) {
+    my_bool reconnect = 1;
     mysql_init(db->desc);
-    dbptr->reconnect = TRUE;
+    mysql_options(db->desc, MYSQL_OPT_RECONNECT, &reconnect);
     if (!mysql_real_connect(db->desc, host, config.sql_user, config.sql_passwd, config.sql_db, 0, NULL, 0)) {
       sql_db_fail(db);
       MY_get_errmsg(db);
@@ -768,5 +769,9 @@
 
 void MY_mysql_get_version()
 {
+#ifdef MARIADB_CLIENT_VERSION_STR
+  printf("MySQL %s\n", MARIADB_CLIENT_VERSION_STR);
+#else
   printf("MySQL %s\n", MYSQL_SERVER_VERSION);
+#endif
 }
