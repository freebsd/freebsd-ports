From 8c8cddbe022af5ece9949804cacffbee6b8972fa Mon Sep 17 00:00:00 2001
From: nicm <nicm>
Date: Tue, 20 Oct 2015 14:19:27 +0000
Subject: [PATCH] The table could change when retrying so don't save it at
 start of server_client_handle_key.

--- server-client.c.orig	2015-09-27 09:42:08 UTC
+++ server-client.c
@@ -540,7 +540,7 @@ server_client_handle_key(struct client *
 	struct window		*w;
 	struct window_pane	*wp;
 	struct timeval		 tv;
-	struct key_table	*table = c->keytable;
+	struct key_table	*table;
 	struct key_binding	 bd_find, *bd;
 	int			 xtimeout;
 
@@ -606,7 +606,7 @@ server_client_handle_key(struct client *
 retry:
 	/* Try to see if there is a key binding in the current table. */
 	bd_find.key = key;
-	bd = RB_FIND(key_bindings, &table->key_bindings, &bd_find);
+	bd = RB_FIND(key_bindings, &c->keytable->key_bindings, &bd_find);
 	if (bd != NULL) {
 		/*
 		 * Key was matched in this table. If currently repeating but a
@@ -624,6 +624,7 @@ retry:
 		 * Take a reference to this table to make sure the key binding
 		 * doesn't disappear.
 		 */
+		table = c->keytable;
 		table->references++;
 
 		/*
