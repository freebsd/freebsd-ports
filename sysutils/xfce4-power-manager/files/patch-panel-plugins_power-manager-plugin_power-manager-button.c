--- panel-plugins/power-manager-plugin/power-manager-button.c.orig	2019-05-17 13:43:56 UTC
+++ panel-plugins/power-manager-plugin/power-manager-button.c
@@ -510,6 +510,7 @@ power_manager_button_update_device_icon_and_details (P
          * so we can disconnect it later */
         battery_device->img = gtk_image_new_from_pixbuf (battery_device->pix);
 
+        g_object_ref (battery_device->img);
 G_GNUC_BEGIN_IGNORE_DEPRECATIONS
         gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM(battery_device->menu_item), battery_device->img);
 G_GNUC_END_IGNORE_DEPRECATIONS
