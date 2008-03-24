--- src/nautilus-burn-drive-selection.c.orig        Sun Nov 19 13:39:17 2006
+++ src/nautilus-burn-drive-selection.c        Sun Nov 19 13:39:30 2006
@@ -151,7 +151,7 @@ nautilus_burn_drive_selection_set_drive_
                        0, drive);
         g_signal_emit (G_OBJECT (selection),
                        nautilus_burn_drive_selection_table_signals [DEVICE_CHANGED],
-                       0, nautilus_burn_drive_get_device (drive));
+                       0, nautilus_burn_drive_get_cdrecord_device (drive));
 
         g_object_notify (G_OBJECT (selection), "device");
         g_object_notify (G_OBJECT (selection), "drive");
@@ -584,7 +584,7 @@ nautilus_burn_drive_selection_get_defaul
         if (drives == NULL) {
                 device = "/dev/cdrom";
         } else {
-                device = nautilus_burn_drive_get_device (drives->data);
+                device = nautilus_burn_drive_get_cdrecord_device (drives->data);
                 g_list_foreach (drives, (GFunc)nautilus_burn_drive_unref, NULL);
                 g_list_free (drives);
         }
@@ -633,7 +633,7 @@ nautilus_burn_drive_selection_get_device
         g_return_val_if_fail (selection != NULL, NULL);
         g_return_val_if_fail (NAUTILUS_BURN_IS_DRIVE_SELECTION (selection), NULL);
 
-        return selection->priv->selected_drive != NULL ? nautilus_burn_drive_get_device (selection->priv->selected_drive) : NULL;
+        return selection->priv->selected_drive != NULL ? nautilus_burn_drive_get_cdrecord_device (selection->priv->selected_drive) : NULL;
 }
 
 /**
