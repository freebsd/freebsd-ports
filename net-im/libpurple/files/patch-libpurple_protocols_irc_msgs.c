--- libpurple/protocols/irc/msgs.c.orig	2022-05-31 01:52:30 UTC
+++ libpurple/protocols/irc/msgs.c
@@ -1622,22 +1622,22 @@ irc_msg_cap(struct irc_conn *irc, const char *name, co
 	irc->sasl_cb = g_new0(sasl_callback_t, 5);
 
 	irc->sasl_cb[id].id = SASL_CB_AUTHNAME;
-	irc->sasl_cb[id].proc = irc_sasl_cb_simple;
+	irc->sasl_cb[id].proc = (int(*)(void))irc_sasl_cb_simple;
 	irc->sasl_cb[id].context = (void *)irc;
 	id++;
 
 	irc->sasl_cb[id].id = SASL_CB_USER;
-	irc->sasl_cb[id].proc = irc_sasl_cb_simple;
+	irc->sasl_cb[id].proc = (int(*)(void))irc_sasl_cb_simple;
 	irc->sasl_cb[id].context = (void *)irc;
 	id++;
 
 	irc->sasl_cb[id].id = SASL_CB_PASS;
-	irc->sasl_cb[id].proc = irc_sasl_cb_secret;
+	irc->sasl_cb[id].proc = (int(*)(void))irc_sasl_cb_secret;
 	irc->sasl_cb[id].context = (void *)irc;
 	id++;
 
 	irc->sasl_cb[id].id = SASL_CB_LOG;
-	irc->sasl_cb[id].proc = irc_sasl_cb_log;
+	irc->sasl_cb[id].proc = (int(*)(void))irc_sasl_cb_log;
 	irc->sasl_cb[id].context = (void *)irc;
 	id++;
 
