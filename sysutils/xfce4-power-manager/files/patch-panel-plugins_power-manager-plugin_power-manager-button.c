--- panel-plugins/power-manager-plugin/power-manager-button.c.orig	2015-05-25 16:10:37 UTC
+++ panel-plugins/power-manager-plugin/power-manager-button.c
@@ -382,7 +382,7 @@ power_manager_button_update_device_icon_
     details = get_device_description (button->priv->upower, device);
 
     /* If UPower doesn't give us an icon, just use the default */
-    if (icon_name == NULL)
+    if (icon_name == NULL || g_strcmp0 (icon_name, "") == 0)
         icon_name = g_strdup (PANEL_DEFAULT_ICON);
 
     pix = gtk_icon_theme_load_icon (gtk_icon_theme_get_default (),
@@ -407,7 +407,13 @@ power_manager_button_update_device_icon_
         DBG("this is the display device, updating");
         /* it is! update the panel button */
         g_free (button->priv->panel_icon_name);
-
+#ifdef XFCE_PLUGIN
+        g_object_get (device,
+                      "icon-name", &icon_name,
+                      NULL);
+        if (icon_name == NULL || g_strcmp0 (icon_name, "") == 0)
+            icon_name = g_strdup (PANEL_DEFAULT_ICON);
+#endif
         button->priv->panel_icon_name = g_strdup (icon_name);
         power_manager_button_set_icon (button);
         /* update tooltip */
