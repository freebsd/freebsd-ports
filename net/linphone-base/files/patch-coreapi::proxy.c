--- coreapi/proxy.c.orig	Fri Mar 11 01:54:25 2005
+++ coreapi/proxy.c	Wed Mar 23 17:43:30 2005
@@ -59,8 +59,8 @@
 
 gint linphone_proxy_config_set_server_addr(LinphoneProxyConfig *obj, const gchar *server_addr){
 	int err;
-	if (server_addr==NULL || strlen(server_addr)==0) return -1;
 	osip_from_t *url;
+	if (server_addr==NULL || strlen(server_addr)==0) return -1;
 	osip_from_init(&url);
 	err=osip_from_parse(url,server_addr);
 	if (err<0){
