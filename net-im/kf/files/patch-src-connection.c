--- src/connection.c.orig	Wed Sep 29 11:16:38 2004
+++ src/connection.c	Wed Oct 20 02:48:18 2004
@@ -71,8 +71,8 @@
 
 void kf_connection_set_proxy   (const gchar *server, gint port,
 				const gchar *uname, const gchar *passwd) {
-	foo_debug ("Setting proxy '%s'...", server);
 	LmProxy *proxy;
+	foo_debug ("Setting proxy '%s'...", server);
 	if (server) {
 		proxy = lm_proxy_new_with_server (LM_PROXY_TYPE_HTTP, server, port);
 		if (*uname == '\0') uname = NULL;
