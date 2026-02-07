--- src/rdf_storage_mysql.c.orig	2023-11-25 15:00:04 UTC
+++ src/rdf_storage_mysql.c
@@ -447,7 +447,7 @@ librdf_storage_mysql_get_handle(librdf_storage* storag
 
 #ifdef HAVE_MYSQL_OPT_RECONNECT
   if(1) {
-    my_bool value=(context->reconnect) ? 1 : 0;
+    bool value=(context->reconnect) ? 1 : 0;
     mysql_options(connection->handle, MYSQL_OPT_RECONNECT, &value);
   }
 #endif
