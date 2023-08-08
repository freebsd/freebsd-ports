--- libpurple/protocols/jabber/auth_cyrus.c.orig	2021-12-21 02:44:53 UTC
+++ libpurple/protocols/jabber/auth_cyrus.c
@@ -373,30 +373,30 @@ jabber_sasl_build_callbacks(JabberStream *js)
 
 	id = 0;
 	js->sasl_cb[id].id = SASL_CB_GETREALM;
-	js->sasl_cb[id].proc = jabber_sasl_cb_realm;
+	js->sasl_cb[id].proc = (int(*)(void))jabber_sasl_cb_realm;
 	js->sasl_cb[id].context = (void *)js;
 	id++;
 
 	js->sasl_cb[id].id = SASL_CB_AUTHNAME;
-	js->sasl_cb[id].proc = jabber_sasl_cb_simple;
+	js->sasl_cb[id].proc = (int(*)(void))jabber_sasl_cb_simple;
 	js->sasl_cb[id].context = (void *)js;
 	id++;
 
 	js->sasl_cb[id].id = SASL_CB_USER;
-	js->sasl_cb[id].proc = jabber_sasl_cb_simple;
+	js->sasl_cb[id].proc = (int(*)(void))jabber_sasl_cb_simple;
 	js->sasl_cb[id].context = (void *)js;
 	id++;
 
 	account = purple_connection_get_account(js->gc);
 	if (purple_account_get_password(account) != NULL ) {
 		js->sasl_cb[id].id = SASL_CB_PASS;
-		js->sasl_cb[id].proc = jabber_sasl_cb_secret;
+		js->sasl_cb[id].proc = (int(*)(void))jabber_sasl_cb_secret;
 		js->sasl_cb[id].context = (void *)js;
 		id++;
 	}
 
 	js->sasl_cb[id].id = SASL_CB_LOG;
-	js->sasl_cb[id].proc = jabber_sasl_cb_log;
+	js->sasl_cb[id].proc = (int(*)(void))jabber_sasl_cb_log;
 	js->sasl_cb[id].context = (void*)js;
 	id++;
 
