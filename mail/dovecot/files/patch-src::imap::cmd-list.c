--- src/imap/cmd-list.c.orig	Wed Feb 26 05:58:45 2003
+++ src/imap/cmd-list.c	Sun Apr 20 02:32:27 2003
@@ -24,16 +24,17 @@
 	const char *response_name;
 	const char *sep;
 	struct imap_match_glob *glob;
-	int listext;
+	int listext, no_placeholder;
 };
 
-static const char *mailbox_flags2str(enum mailbox_flags flags, int listext)
+static const char *mailbox_flags2str(enum mailbox_flags flags,
+				     int listext, int no_placeholder)
 {
 	const char *str;
 
 	if (flags & MAILBOX_PLACEHOLDER) {
-		if (flags == MAILBOX_PLACEHOLDER) {
-			if (!listext)
+		if ((flags & ~MAILBOX_CHILDREN) == MAILBOX_PLACEHOLDER) {
+			if (!listext || no_placeholder)
 				flags = MAILBOX_NOSELECT;
 		} else {
 			/* it was at one point, but then we got better specs */
@@ -59,7 +60,6 @@
 
 static void list_node_update(pool_t pool, struct list_node **node,
 			     const char *path, char separator,
-			     enum mailbox_flags dir_flags,
 			     enum mailbox_flags flags)
 {
 	const char *name, *parent;
@@ -88,7 +88,8 @@
 			/* not found, create it */
 			*node = p_new(pool, struct list_node, 1);
 			(*node)->name = p_strdup(pool, name);
-			(*node)->flags = *path == '\0' ? flags : dir_flags;
+			(*node)->flags = *path == '\0' ? flags :
+				MAILBOX_PLACEHOLDER;
 		} else {
 			if (*path == '\0') {
 				if (((*node)->flags & MAILBOX_NOSELECT) != 0 &&
@@ -139,16 +140,24 @@
 
 			buf = str_unescape(t_strdup_noconst(name));
 			match = imap_match(ctx->glob, buf);
-			if (match == IMAP_MATCH_CHILDREN) {
+			/* FIXME: IMAP spec says this should be done, but
+			   a) this is broken, we shouldn't give \NoSelect for
+			      this folder if it actually works.
+			   b) at least mozilla's subscriptions list breaks if
+			      this is sent
+			   c) cyrus and courier doesn't do this either..
+
+			   if (match == IMAP_MATCH_CHILDREN) {
 				send_name = t_strconcat(name, ctx->sep, NULL);
 				buf = str_unescape(t_strdup_noconst(send_name));
 				match = imap_match(ctx->glob, buf);
-			}
+			}*/
 		}
 
 		if (match == IMAP_MATCH_YES) {
 			/* node->name should already be escaped */
-			flagstr = mailbox_flags2str(node->flags, ctx->listext);
+			flagstr = mailbox_flags2str(node->flags, ctx->listext,
+						    ctx->no_placeholder);
 			str = t_strdup_printf("* %s (%s) \"%s\" \"%s\"",
 					      ctx->response_name, flagstr,
 					      ctx->sep, send_name);
@@ -171,19 +180,15 @@
 	struct mailbox_list *list;
 	struct list_node *nodes;
 	struct list_send_context send_ctx;
-	enum mailbox_flags dir_flags;
 	pool_t pool;
 
-	dir_flags = (list_flags & MAILBOX_LIST_SUBSCRIBED) ?
-		MAILBOX_PLACEHOLDER : MAILBOX_NOSELECT;
-
 	pool = pool_alloconly_create("list_mailboxes", 10240);
 	nodes = NULL;
 
 	while ((list = client->storage->list_mailbox_next(ctx)) != NULL) {
 		list_node_update(pool, &nodes, list->name,
 				 client->storage->hierarchy_sep,
-				 dir_flags, list->flags);
+				 list->flags);
 	}
 
 	send_ctx.client = client;
@@ -192,6 +197,7 @@
 	send_ctx.glob = imap_match_init(data_stack_pool, mask, TRUE,
 					client->storage->hierarchy_sep);
 	send_ctx.listext = listext;
+	send_ctx.no_placeholder = (list_flags & MAILBOX_LIST_SUBSCRIBED) == 0;
 
 	list_send(&send_ctx, nodes, NULL);
 	imap_match_deinit(send_ctx.glob);
@@ -212,7 +218,8 @@
 		else
 			name = str_escape(list->name);
 		str = t_strdup_printf("* %s (%s) \"%s\" \"%s\"", reply,
-				      mailbox_flags2str(list->flags, listext),
+				      mailbox_flags2str(list->flags, listext,
+							FALSE),
 				      sep, name);
 		client_send_line(client, str);
 		t_pop();
