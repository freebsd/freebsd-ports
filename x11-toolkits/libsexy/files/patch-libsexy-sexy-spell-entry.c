--- libsexy/sexy-spell-entry.c.orig	Fri Oct 14 20:20:45 2005
+++ libsexy/sexy-spell-entry.c	Sun Nov 13 13:21:06 2005
@@ -799,12 +799,14 @@
 GSList *
 sexy_spell_entry_get_languages(const SexySpellEntry *entry)
 {
+#ifdef HAVE_ENCHANT_BROKER_LIST_DICTS
+	GSList *langs = NULL;
+#endif
+
 	g_return_val_if_fail(entry != NULL, NULL);
 	g_return_val_if_fail(SEXY_IS_SPELL_ENTRY(entry), NULL);
 
 #ifdef HAVE_ENCHANT_BROKER_LIST_DICTS
-	GSList *langs = NULL;
-
 	if (!entry->priv->broker)
 		return NULL;
 
@@ -866,13 +868,15 @@
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
 
