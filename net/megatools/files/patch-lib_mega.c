--- lib/mega.c.orig	2018-07-22 21:41:55 UTC
+++ lib/mega.c
@@ -3172,6 +3172,7 @@ static void tman_worker_upload_chunk(struct transfer_c
 	GError *local_err = NULL;
 	gc_free gchar *url = NULL;
 	gc_string_free GString *response = NULL;
+	gc_free gchar* chksum = NULL;
 
 	tman_debug("W[%d]: started for chunk %d\n", worker->index, c->index);
 
@@ -3217,7 +3218,7 @@ static void tman_worker_upload_chunk(struct transfer_c
 	}
 
 	// prepare URL including chunk offset
-	gc_free gchar* chksum = upload_checksum(buf, c->size);
+	chksum = upload_checksum(buf, c->size);
 	url = g_strdup_printf("%s/%" G_GOFFSET_FORMAT "?c=%s", t->upload_url, c->offset, chksum);
 
 	// perform upload POST
@@ -4636,6 +4637,26 @@ gboolean mega_node_get_path(struct mega_node *n, gchar
 gboolean mega_node_is_container(struct mega_node *n)
 {
 	return n && n->type != MEGA_NODE_FILE;
+}
+
+// }}}
+// {{{ mega_node_has_ancestor
+
+gboolean mega_node_has_ancestor(struct mega_node *n, struct mega_node *ancestor)
+{
+	g_return_val_if_fail(n != NULL, FALSE);
+	g_return_val_if_fail(ancestor != NULL, FALSE);
+
+	struct mega_node* it = n->parent;
+
+	while (it) {
+		if (it == ancestor)
+			return TRUE;
+
+		it = it->parent;
+	}
+
+	return FALSE;
 }
 
 // }}}
