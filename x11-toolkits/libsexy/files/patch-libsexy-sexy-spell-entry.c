--- libsexy/sexy-spell-entry.c.orig	Fri Oct 14 20:20:45 2005
+++ libsexy/sexy-spell-entry.c	Tue Nov  8 22:13:53 2005
@@ -866,13 +866,15 @@
 gboolean
 sexy_spell_entry_activate_language(SexySpellEntry *entry, const gchar *lang, GError **error)
 {
+#ifdef HAVE_ENCHANT
+	gboolean ret;
+#endif
+
 	g_return_val_if_fail(entry != NULL, FALSE);
 	g_return_val_if_fail(SEXY_IS_SPELL_ENTRY(entry), FALSE);
 	g_return_val_if_fail(lang != NULL && lang != '\0', FALSE);
 
 #ifdef HAVE_ENCHANT
-	gboolean ret;
-
 	if (error)
 		g_return_val_if_fail(*error == NULL, FALSE);
 
