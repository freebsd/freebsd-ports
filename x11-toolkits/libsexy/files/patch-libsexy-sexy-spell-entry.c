--- libsexy/sexy-spell-entry.c.orig	Wed Nov 16 04:45:57 2005
+++ libsexy/sexy-spell-entry.c	Thu Jan 12 00:57:57 2006
@@ -880,10 +880,10 @@
 static gchar *
 get_lang_from_dict(struct EnchantDict *dict)
 {
+	gchar *lang;
 	if (!have_enchant)
 		return NULL;
 
-	gchar *lang;
 	enchant_dict_describe(dict, get_lang_from_dict_cb, &lang);
 	return lang;
 }
@@ -938,14 +938,14 @@
 GSList *
 sexy_spell_entry_get_languages(const SexySpellEntry *entry)
 {
+	GSList *langs = NULL;
+
 	g_return_val_if_fail(entry != NULL, NULL);
 	g_return_val_if_fail(SEXY_IS_SPELL_ENTRY(entry), NULL);
 
 	if (enchant_broker_list_dicts == NULL)
 		return NULL;
 
-	GSList *langs = NULL;
-
 	if (!entry->priv->broker)
 		return NULL;
 
@@ -1002,14 +1002,14 @@
 gboolean
 sexy_spell_entry_activate_language(SexySpellEntry *entry, const gchar *lang, GError **error)
 {
+	gboolean ret;
+
 	g_return_val_if_fail(entry != NULL, FALSE);
 	g_return_val_if_fail(SEXY_IS_SPELL_ENTRY(entry), FALSE);
 	g_return_val_if_fail(lang != NULL && lang != '\0', FALSE);
 
 	if (!have_enchant)
 		return FALSE;
-
-	gboolean ret;
 
 	if (error)
 		g_return_val_if_fail(*error == NULL, FALSE);
