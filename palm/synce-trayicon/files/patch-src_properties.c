--- src/properties.c.orig	2008-07-26 22:26:43.000000000 +1000
+++ src/properties.c	2008-07-26 22:28:54.000000000 +1000
@@ -23,7 +23,6 @@
 
   if (!(g_ascii_strcasecmp(key, "/apps/synce/trayicon/dccm"))) {
     const gchar *which_dccm = gconf_value_get_string(value);
-    GtkWidget *prefs_use_odccm = glade_xml_get_widget (xml, "prefs_use_odccm");	
     GtkWidget *prefs_use_vdccm = glade_xml_get_widget (xml, "prefs_use_vdccm");	
     GtkWidget *prefs_use_hal = glade_xml_get_widget (xml, "prefs_use_hal");	
     GtkWidget *prefs_start_stop_vdccm = glade_xml_get_widget (xml, "prefs_start_stop_vdccm");	
@@ -31,33 +30,18 @@
     if (!(g_ascii_strcasecmp(which_dccm, "v"))) {
       gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (prefs_use_vdccm), TRUE);
       gtk_widget_set_sensitive(prefs_start_stop_vdccm, TRUE);
-    } else if (!(g_ascii_strcasecmp(which_dccm, "o"))) {
-      gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (prefs_use_odccm), TRUE);
-      gtk_widget_set_sensitive(prefs_start_stop_vdccm, FALSE);
     } else if (!(g_ascii_strcasecmp(which_dccm, "h"))) {
       gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (prefs_use_hal), TRUE);
       gtk_widget_set_sensitive(prefs_start_stop_vdccm, FALSE);
     } else {
       gconf_client_set_string (conf_client,
-			    "/apps/synce/trayicon/dccm", "o", NULL);
+			    "/apps/synce/trayicon/dccm", "h", NULL);
     }
   }
 }
 
 
 static void
-prefs_use_odccm_toggled_cb (GtkWidget *widget, gpointer data)
-{
-    gboolean state;
-    GConfClient *conf_client = gconf_client_get_default();
-
-    state = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget));
-    if (state)
-      gconf_client_set_string (conf_client,
-			       "/apps/synce/trayicon/dccm", "o", NULL);
-}
-
-static void
 prefs_use_vdccm_toggled_cb (GtkWidget *widget, gpointer data)
 {
     gboolean state;
@@ -107,7 +91,7 @@
 GtkWidget *
 run_prefs_dialog (SynceTrayIcon *trayicon)
 {
-  GtkWidget *prefs_window, *prefs_use_odccm, *prefs_use_vdccm, *prefs_use_hal, *prefs_start_stop_vdccm, *close_button;
+  GtkWidget *prefs_window, *prefs_use_vdccm, *prefs_use_hal, *prefs_start_stop_vdccm, *close_button;
   gchar *which_dccm;
   GError *error = NULL;
 
@@ -117,36 +101,30 @@
 
   prefs_window = glade_xml_get_widget (xml, "prefs_window");
 
-  prefs_use_odccm = glade_xml_get_widget (xml, "prefs_use_odccm");
   prefs_use_vdccm = glade_xml_get_widget (xml, "prefs_use_vdccm");
   prefs_use_hal = glade_xml_get_widget (xml, "prefs_use_hal");
   prefs_start_stop_vdccm = glade_xml_get_widget (xml, "prefs_start_stop_vdccm");
 
   if (!(which_dccm = gconf_client_get_string (conf_client,
 					      "/apps/synce/trayicon/dccm", &error))) {
-    which_dccm = g_strdup("o");
+    which_dccm = g_strdup("h");
     if (error) {
       g_warning("%s: Get dccm type from gconf failed: %s", G_STRFUNC, error->message);
       g_error_free(error);
     }
   }
 
-  if (!(g_ascii_strcasecmp(which_dccm, "h"))) {
-    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (prefs_use_hal), TRUE);
-    gtk_widget_set_sensitive(prefs_start_stop_vdccm, FALSE);
-  } else if (!(g_ascii_strcasecmp(which_dccm, "v"))) {
+  if (!(g_ascii_strcasecmp(which_dccm, "v"))) {
     gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (prefs_use_vdccm), TRUE);
     gtk_widget_set_sensitive(prefs_start_stop_vdccm, TRUE);
     gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (prefs_start_stop_vdccm), 
 				  gconf_client_get_bool (conf_client,
 							 "/apps/synce/trayicon/start_vdccm", NULL));
   } else {
-    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (prefs_use_odccm), TRUE);
+    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (prefs_use_hal), TRUE);
     gtk_widget_set_sensitive(prefs_start_stop_vdccm, FALSE);
   }
 
-  g_signal_connect (G_OBJECT (prefs_use_odccm), "toggled",
-		      G_CALLBACK (prefs_use_odccm_toggled_cb), NULL);
   g_signal_connect (G_OBJECT (prefs_use_vdccm), "toggled",
 		      G_CALLBACK (prefs_use_vdccm_toggled_cb), prefs_start_stop_vdccm);
   g_signal_connect (G_OBJECT (prefs_use_hal), "toggled",
