--- libgtkhtml/util/htmlatomlist.c.orig	Mon May 26 14:13:28 2003
+++ libgtkhtml/util/htmlatomlist.c	Mon May 26 15:29:00 2003
@@ -68,10 +68,11 @@
 	HtmlAtom atom;
 	gchar *ptr;
 	gboolean found;
+	gpointer old_atom;
 
 	ptr = g_strdown (g_strdup (str));
 
-	found = g_hash_table_lookup_extended (al->table, ptr, NULL, (gpointer) &atom);
+	found = g_hash_table_lookup_extended (al->table, ptr, NULL, &old_atom);
 	
 	if (!found) {
 		if (al->len % 512 == 0)
@@ -81,6 +82,9 @@
 		atom = al->len;
 		g_hash_table_insert (al->table, al->data[al->len], GUINT_TO_POINTER (atom));
 		al->len++;
+	}
+	else {
+		atom = GPOINTER_TO_UINT (old_atom);
 	}
 
 	g_free (ptr);
