--- console/commands.c.orig	Tue Mar  8 03:31:49 2005
+++ console/commands.c	Wed Mar 23 17:46:13 2005
@@ -112,9 +112,9 @@
 
 void linphonec_proxy_list(LinphoneCore *lc){
 	GList *proxies;
-	int n;
+	int def, n;
 	proxies=linphone_core_get_proxy_config_list(lc);
-	int def=linphone_core_get_default_proxy(lc,NULL);
+	def=linphone_core_get_default_proxy(lc,NULL);
 	for(n=0;proxies!=NULL;proxies=g_list_next(proxies),n++){
 		if (n==def)
 			printf("****** Proxy %i - this is the default one - *******\n",n);
