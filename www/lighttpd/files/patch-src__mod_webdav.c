--- src/mod_webdav.c.orig	Tue Oct 10 01:08:09 2006
+++ src/mod_webdav.c	Tue Oct 10 01:09:02 2006
@@ -1151,11 +1151,13 @@
  *
  */
 int webdav_has_lock(server *srv, connection *con, plugin_data *p, buffer *uri) {
-	UNUSED(srv);
 	int has_lock = 1;
-
 #ifdef USE_LOCKS
 	data_string *ds;
+#endif
+	UNUSED(srv);
+
+#ifdef USE_LOCKS
 
 	/**
 	 * This implementation is more fake than real
