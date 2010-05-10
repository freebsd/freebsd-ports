--- hald/freebsd/addons/addon-storage.c.orig	2009-08-24 08:42:29.000000000 -0400
+++ hald/freebsd/addons/addon-storage.c	2009-12-23 13:53:00.000000000 -0500
@@ -107,8 +107,7 @@ hf_addon_storage_update (void)
 
 	  if (hf_addon_storage_cdrom_eject_pressed(cdrom))
 	    {
-	      libhal_device_emit_condition(hfp_ctx, hfp_udi, "EjectPressed", "", &hfp_error);
-	      dbus_error_free(&hfp_error);
+	      libhal_device_emit_condition(hfp_ctx, hfp_udi, "EjectPressed", "", NULL);
 	    }
 
 	  hfp_cdrom_free(cdrom);
@@ -164,19 +163,17 @@ unmount_volumes (void)
                                                          "block.storage_device",
 							 hfp_udi,
 							 &num_volumes,
-							 &hfp_error)) != NULL)
+							 NULL)) != NULL)
     {
       int i;
 
-      dbus_error_free(&hfp_error);
-
       for (i = 0; i < num_volumes; i++)
         {
           char *vol_udi;
 
 	  vol_udi = volumes[i];
 
-	  if (libhal_device_get_property_bool(hfp_ctx, vol_udi, "volume.is_mounted", &hfp_error))
+	  if (libhal_device_get_property_bool(hfp_ctx, vol_udi, "volume.is_mounted", NULL))
             {
               DBusMessage *msg = NULL;
 	      DBusMessage *reply = NULL;
@@ -185,7 +182,6 @@ unmount_volumes (void)
 	      char **options = NULL;
 	      char *devfile;
 
-	      dbus_error_free(&hfp_error);
               hfp_info("Forcing unmount of volume '%s'", vol_udi);
 
 	      dbus_connection = libhal_ctx_get_dbus_connection(hfp_ctx);
@@ -265,10 +261,9 @@ poll_for_media (boolean check_only, bool
       check_lock_state = FALSE;
 
       hfp_info("Checking whether device %s is locked by HAL", addon.device_file);
-      if (libhal_device_is_locked_by_others(hfp_ctx, hfp_udi, "org.freedesktop.Hal.Device.Storage", &hfp_error))
+      if (libhal_device_is_locked_by_others(hfp_ctx, hfp_udi, "org.freedesktop.Hal.Device.Storage", NULL))
         {
           hfp_info("... device %s is locked by HAL", addon.device_file);
-	  dbus_error_free(&hfp_error);
 	  is_locked_by_hal = TRUE;
 	  update_proc_title(addon.device_file);
 	  goto skip_check;
@@ -278,10 +273,8 @@ poll_for_media (boolean check_only, bool
           hfp_info("... device %s is not locked by HAL", addon.device_file);
 	  is_locked_by_hal = FALSE;
 	}
-      dbus_error_free(&hfp_error);
 
-      should_poll = libhal_device_get_property_bool(hfp_ctx, hfp_udi, "storage.media_check_enabled", &hfp_error);
-      dbus_error_free(&hfp_error);
+      should_poll = libhal_device_get_property_bool(hfp_ctx, hfp_udi, "storage.media_check_enabled", NULL);
       polling_disabled = ! should_poll;
       update_proc_title(addon.device_file);
     }
@@ -314,8 +307,7 @@ poll_for_media (boolean check_only, bool
       unmount_volumes();
 #endif
 
-      libhal_device_rescan(hfp_ctx, hfp_udi, &hfp_error);
-      dbus_error_free(&hfp_error);
+      libhal_device_rescan(hfp_ctx, hfp_udi, NULL);
       addon.had_media = has_media;
 
       return TRUE;
@@ -412,12 +404,10 @@ main (int argc, char **argv)
     ! strcmp(driver, "cd")))) && ! strcmp(removable, "true");
   addon.had_media = poll_for_media(TRUE, FALSE);
 
-  if (! libhal_device_addon_is_ready(hfp_ctx, hfp_udi, &hfp_error))
+  if (! libhal_device_addon_is_ready(hfp_ctx, hfp_udi, NULL))
     goto end;
-  dbus_error_free(&hfp_error);
 
-  syscon = dbus_bus_get(DBUS_BUS_SYSTEM, &hfp_error);
-  dbus_error_free(&hfp_error);
+  syscon = dbus_bus_get(DBUS_BUS_SYSTEM, NULL);
   assert(syscon != NULL);
   dbus_connection_set_exit_on_disconnect(syscon, 0);
 
@@ -452,12 +442,11 @@ main (int argc, char **argv)
 				      "    <method name=\"CheckForMedia\">\n"
 				      "      <arg name=\"call_had_sideeffect\" direction=\"out\" type=\"b\"/>\n"
 				      "    </method>\n",
-				      &hfp_error))
+				      NULL))
     {
       hfp_critical("Cannot claim interface 'org.freedesktop.Hal.Device.Storage.Removable'");
       goto end;
     }
-  dbus_error_free(&hfp_error);
 
   while (TRUE)
     {
