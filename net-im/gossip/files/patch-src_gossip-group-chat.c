--- src/gossip-group-chat.c.orig	Fri Nov 21 01:35:04 2003
+++ src/gossip-group-chat.c	Fri Nov 21 01:35:19 2003
@@ -1039,7 +1039,7 @@
 static GossipChat *
 group_chat_priv_chat_new (GossipGroupChat *chat, GossipJID *jid)
 {
-	GossipChat       *priv_chat = NULL;;
+	GossipChat       *priv_chat = NULL;
 	GList            *l;
 	GossipRosterItem *item;
 /*	gchar            *name; */
