--- plugins/exchange-account-setup/exchange-account-setup.c.orig	Tue Mar  1 15:38:29 2005
+++ plugins/exchange-account-setup/exchange-account-setup.c	Tue Mar  1 15:38:45 2005
@@ -564,9 +564,10 @@
 org_gnome_exchange_commit (EPlugin *epl, EConfigHookItemFactoryData *data)
 {
 	EMConfigTargetAccount *target_account;
-	target_account = (EMConfigTargetAccount *)data->config->target;
 	const char *source_url;
 	CamelURL *url;
+
+	target_account = (EMConfigTargetAccount *)data->config->target;
 	
 	source_url = e_account_get_string (target_account->account,  E_ACCOUNT_SOURCE_URL);
 	url = camel_url_new (source_url, NULL);
