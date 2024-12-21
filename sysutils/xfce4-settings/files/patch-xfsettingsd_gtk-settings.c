--- xfsettingsd/gtk-settings.c.orig	2024-12-01 15:21:41 UTC
+++ xfsettingsd/gtk-settings.c
@@ -226,8 +226,8 @@ xfce_gtk_settings_helper_init (XfceGtkSettingsHelper *
     }
 
     net_properties = g_hash_table_new (g_str_hash, g_str_equal);
-    for (guint i = 0; i < G_N_ELEMENTS (xsettings_properties_Net); i++)
-        g_hash_table_add (net_properties, (gpointer) xsettings_properties_Net[i]);
+    /*for (guint i = 0; i < G_N_ELEMENTS (xsettings_properties_Net); i++)
+        g_hash_table_add (net_properties, (gpointer) xsettings_properties_Net[i]);*/
 
     helper->gsettings_objs = g_hash_table_new_full (g_str_hash, g_str_equal, NULL, g_object_unref);
     helper->gsettings_data = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
