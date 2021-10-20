--- transports/janus_websockets.c.orig	2021-10-20 10:23:29 UTC
+++ transports/janus_websockets.c
@@ -383,6 +383,9 @@ static struct lws_vhost* janus_websockets_create_ws_se
 {
 	janus_config_item *item;
 	char item_name[255];
+#ifdef __FreeBSD__
+	int ipv4_only = 0;
+#endif
 
 	item = janus_config_get(config, config_container, janus_config_type_item, prefix);
 	if(!item || !item->value || !janus_is_true(item->value)) {
@@ -529,9 +532,6 @@ int janus_websockets_init(janus_transport_callbacks *c
 	JANUS_LOG(LOG_WARN, "libwebsockets has been built without IPv6 support, will bind to IPv4 only\n");
 #endif
 
-#ifdef __FreeBSD__
-	int ipv4_only = 0;
-#endif
 	/* This is the callback we'll need to invoke to contact the Janus core */
 	gateway = callback;
 
