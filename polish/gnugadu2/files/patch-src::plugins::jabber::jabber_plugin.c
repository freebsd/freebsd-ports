--- src/plugins/jabber/jabber_plugin.c.orig	Tue Feb 17 17:12:25 2004
+++ src/plugins/jabber/jabber_plugin.c	Mon Feb 23 22:45:48 2004
@@ -235,11 +235,12 @@
 {
 	GSList *user = (GSList *) user_data;
 	GGaduContact *k = NULL;
+	LmMessage *m = NULL;
 	
 	if (!user) return NULL;
 	
 	k = (GGaduContact *) user->data;
-	LmMessage *m = lm_message_new_with_sub_type(k->id, LM_MESSAGE_TYPE_PRESENCE, LM_MESSAGE_SUB_TYPE_SUBSCRIBE);
+	m = lm_message_new_with_sub_type(k->id, LM_MESSAGE_TYPE_PRESENCE, LM_MESSAGE_SUB_TYPE_SUBSCRIBE);
 	lm_connection_send(connection, m, NULL);
 	lm_message_unref(m);
 	return NULL;
