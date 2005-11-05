--- plugins/groupwise-features/proxy-login.c.orig	Fri Jul 29 18:55:40 2005
+++ plugins/groupwise-features/proxy-login.c	Fri Jul 29 18:55:58 2005
@@ -236,7 +236,6 @@ proxy_login_get_cnc (EAccount *account)
 {
 	EGwConnection *cnc;
 	CamelURL *url;
-	url = camel_url_new (account->source->url, NULL);
 	char *uri = NULL, *failed_auth = NULL, *key = NULL, *prompt = NULL, *password = NULL;
 	const char *use_ssl, *soap_port;
 
