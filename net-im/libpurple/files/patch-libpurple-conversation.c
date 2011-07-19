--- libpurple/conversation.c.orig	2011-07-11 14:28:20.000000000 +0200
+++ libpurple/conversation.c	2011-07-11 14:28:47.000000000 +0200
@@ -1978,7 +1978,6 @@
 	}
 
 	g_hash_table_remove_all(chat->users);
-	chat->users = NULL;
 
 	g_list_free(users);
 	chat->in_room = NULL;
