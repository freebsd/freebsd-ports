--- src/plugins/aaway/aaway.c.orig	Fri Oct  7 13:04:11 2005
+++ src/plugins/aaway/aaway.c	Fri Oct  7 13:06:34 2005
@@ -250,8 +250,10 @@
 static gpointer aaway_preferences(gpointer user_data)
 {
 	GGaduDialog *d = ggadu_dialog_new(GGADU_DIALOG_CONFIG, _("Auto-Away Preferences"), "update config");
+	gchar *utf;
+
 	print_debug("%s: Preferences\n", "aaway");
-	gchar *utf = NULL;
+	utf = NULL;
 	ggadu_dialog_add_entry(d, GGADU_AAWAY_CONFIG_ENABLE_AUTOAWAY, _("Enable auto-away"), VAR_BOOL, (gpointer) ggadu_config_var_get(handler, "enable"), VAR_FLAG_ADVANCED);
 	ggadu_dialog_add_entry(d, GGADU_AAWAY_CONFIG_INTERVAL, _("Auto away after time (minutes)"), VAR_INT, (gpointer) ggadu_config_var_get(handler, "interval"), VAR_FLAG_NONE);
 	ggadu_dialog_add_entry(d, GGADU_AAWAY_CONFIG_ENABLE_AWAY_MSG, _("Enable away message"), VAR_BOOL,
