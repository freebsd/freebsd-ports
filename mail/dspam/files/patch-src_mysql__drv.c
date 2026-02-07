--- src/mysql_drv.c.orig	2012-04-11 18:48:33 UTC
+++ src/mysql_drv.c
@@ -3461,7 +3461,11 @@ MYSQL *_mysql_drv_connect (DSPAM_CTX *CTX, const char 
   snprintf(attrib, sizeof(attrib), "%sReconnect", prefix);
   if (_ds_match_attribute(CTX->config->attributes, attrib, "true"))
   {
+#  if MYSQL_VERSION_ID < 80000 || defined(MARIADB_VERSION_ID)
       my_bool reconnect = 1;
+#  else
+      bool reconnect = 1;
+#  endif
       mysql_options(dbh, MYSQL_OPT_RECONNECT, &reconnect);
   }
 #endif
