--- src/nautilus-burn-drive.c.orig        Fri Sep 29 12:55:36 2006
+++ src/nautilus-burn-drive.c        Sun Nov 19 13:27:31 2006
@@ -266,6 +266,25 @@ nautilus_burn_drive_get_device (Nautilus
 }
 
 /**
+ * nautilus_burn_drive_get_cdrecord_device:
+ * @drive: #NautilusBurnDrive
+ *
+ * Get the name of the device associated with the drive suitable for
+ * user with cdrcord.
+ *
+ * Returns: device name.  Must be not be freed.
+ *
+ * Since: 2.16
+ **/
+const char *
+nautilus_burn_drive_get_cdrecord_device (NautilusBurnDrive *drive)
+{
+        g_return_val_if_fail (drive != NULL, NULL);
+
+        return drive->priv->cdrecord_device;
+}
+
+/**
  * nautilus_burn_drive_get_drive_type:
  * @drive: #NautilusBurnDrive
  *
@@ -1021,6 +1044,7 @@ nautilus_burn_drive_finalize (GObject *o
         g_free (drive->priv->write_speeds);
         g_free (drive->priv->display_name);
         g_free (drive->priv->device);
+        g_free (drive->priv->cdrecord_device);
 
         if (G_OBJECT_CLASS (nautilus_burn_drive_parent_class)->finalize != NULL) {
                 (* G_OBJECT_CLASS (nautilus_burn_drive_parent_class)->finalize) (object);
@@ -1038,6 +1062,7 @@ nautilus_burn_drive_init (NautilusBurnDr
         drive->priv->max_speed_read  = 0;
         drive->priv->write_speeds    = NULL;
         drive->priv->device          = NULL;
+        drive->priv->cdrecord_device = NULL;
 }
 
 /**
