--- xfprint/main.c.orig	Wed Apr 13 23:55:06 2005
+++ xfprint/main.c	Wed Apr 13 23:55:07 2005
@@ -87,22 +87,17 @@
     mcs_client_add_channel (client, CHANNEL);
 
     if (mcs_client_get_setting (client, "XfPrint/system", CHANNEL, &setting) == MCS_SUCCESS) {
-      if (!load_printing_system (setting->data.v_string))
-        g_error ("Unable to load printing system module %s", setting->data.v_string);
+      if (!load_printing_system (setting->data.v_string) && strncmp(setting->data.v_string,"file_plugin.so",14) == 0) {
+        g_print ("Configure your printing system using the Xfce Settings Manager first\n");
+        exit (EXIT_FAILURE);
+      } else if (!load_printing_system (setting->data.v_string) ) {
+          g_error ("Unable to load printing system module %s", setting->data.v_string);
+      }
       mcs_setting_free (setting);
     }
     else {
-      gchar *default_system = NULL;
-
-      g_warning ("No mcs-setting found for XfPrint/system in channel %s, using default printing-system", CHANNEL);
-
-      default_system = g_build_filename (PLUGIN_DIR, "file_plugin.so", NULL);
-
-      if (!load_printing_system (default_system)) {
-        g_error ("Unable to load default printing system module %s", default_system);
-      }
-
-      g_free (default_system);
+        g_print ("Configure your printing system using the Xfce Settings Manager first\n");      
+        exit (EXIT_FAILURE);
     }
 
     mcs_client_destroy (client);
