--- src/protocols/yahoo/yahoochat.c.orig	Wed Mar 16 05:14:01 2005
+++ src/protocols/yahoo/yahoochat.c	Sun Mar 20 15:59:34 2005
@@ -342,8 +342,11 @@
 void yahoo_process_chat_join(GaimConnection *gc, struct yahoo_packet *pkt)
 {
 	struct yahoo_data *yd = (struct yahoo_data *) gc->proto_data;
+	GaimAccount *account;
 	GaimConversation *c = NULL;
+	GaimConversationUiOps *ops;
 	GSList *l;
+	GList *roomies = NULL;
 	GList *members = NULL;
 	char *room = NULL;
 	char *topic = NULL;
@@ -443,10 +446,8 @@
 		yahoo_chat_add_users(GAIM_CONV_CHAT(c), members);
 	}
 
-	GList *roomies=NULL;
-	GaimConversationUiOps *ops;
 	ops = gaim_conversation_get_ui_ops(c);
-	GaimAccount *account = gaim_connection_get_account(gc);
+	account = gaim_connection_get_account(gc);
 	for (l = account->deny; l != NULL; l = l->next) {
 		for (roomies = members; roomies; roomies = roomies->next) {
 			if (!gaim_utf8_strcasecmp((char *)l->data, roomies->data)) {
