--- helper/helper-applet.c.orig	Tue Oct 14 00:07:31 2003
+++ helper/helper-applet.c	Tue Oct 14 00:24:43 2003
@@ -134,6 +134,7 @@
   gchar **tmp2 = NULL;
   gchar *charset = NULL;
   GString *path = g_string_new("");
+  GtkItemFactoryEntry entry;
 
   tmp2 = g_strsplit(tmp[1], "=", 0);
 
@@ -176,7 +177,11 @@
 	  gtk_widget_show(button);
 	} else if(strcmp("leaf", tmp2[0]) == 0) {
 	  g_string_printf(path, "/%s", tmp2[2]);
-	  GtkItemFactoryEntry entry = {path->str, NULL, G_CALLBACK(activate_event), 0, ""};
+	  entry.path = path->str;
+	  entry.accelerator = NULL;
+	  entry.callback = G_CALLBACK(activate_event);
+	  entry.callback_action = 0;
+	  entry.item_type = "";
 	  gtk_item_factory_create_item ( mode_item_fact, &entry, tmp2[4], 1);
 
 	}
