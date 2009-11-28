--- hald/freebsd/addons/addon-storage.c.orig	2008-08-10 09:50:10.000000000 -0400
+++ hald/freebsd/addons/addon-storage.c	2009-09-13 17:23:52.000000000 -0400
@@ -36,17 +36,24 @@
 #include "../libprobe/hfp.h"
 #include "../libprobe/hfp-cdrom.h"
 
+static boolean is_locked_by_hal = FALSE;
+static boolean check_lock_state = TRUE;
+static boolean polling_disabled = FALSE;
+
 static struct
 {
-  const struct timeval	update_interval;
+  const struct timespec	update_interval;
   char			*device_file;
   char			*parent;
   boolean		is_cdrom;
   boolean		is_scsi_removable;
   boolean		had_media;
-  struct timeval	next_update;
+  struct timespec	next_update;
 } addon = { { 2, 0 } };
 
+static void update_proc_title (const char *device);
+static void unmount_volumes (void);
+
 /* see MMC-3 Working Draft Revision 10 */
 static boolean
 hf_addon_storage_cdrom_eject_pressed (HFPCDROM *cdrom)
@@ -100,8 +107,7 @@ hf_addon_storage_update (void)
 
 	  if (hf_addon_storage_cdrom_eject_pressed(cdrom))
 	    {
-	      libhal_device_emit_condition(hfp_ctx, hfp_udi, "EjectPressed", "", &hfp_error);
-	      dbus_error_free(&hfp_error);
+	      libhal_device_emit_condition(hfp_ctx, hfp_udi, "EjectPressed", "", NULL);
 	    }
 
 	  hfp_cdrom_free(cdrom);
@@ -144,18 +150,142 @@ hf_addon_storage_update (void)
 	}
     }
 
-  hfp_gettimeofday(&addon.next_update);
-  hfp_timevaladd(&addon.next_update, &addon.update_interval);
-
   return has_media;
 }
 
+static void
+unmount_volumes (void)
+{
+  int num_volumes;
+  char **volumes;
+
+  if ((volumes = libhal_manager_find_device_string_match(hfp_ctx,
+                                                         "block.storage_device",
+							 hfp_udi,
+							 &num_volumes,
+							 NULL)) != NULL)
+    {
+      int i;
+
+      for (i = 0; i < num_volumes; i++)
+        {
+          char *vol_udi;
+
+	  vol_udi = volumes[i];
+
+	  if (libhal_device_get_property_bool(hfp_ctx, vol_udi, "volume.is_mounted", NULL))
+            {
+              DBusMessage *msg = NULL;
+	      DBusMessage *reply = NULL;
+	      DBusConnection *dbus_connection;
+	      unsigned int num_options = 0;
+	      char **options = NULL;
+	      char *devfile;
+
+              hfp_info("Forcing unmount of volume '%s'", vol_udi);
+
+	      dbus_connection = libhal_ctx_get_dbus_connection(hfp_ctx);
+	      msg = dbus_message_new_method_call("org.freedesktop.Hal", vol_udi,
+                                                 "org.freedesktop.Hal.Device.Volume",
+						 "Unmount");
+	      if (msg == NULL)
+                {
+                  hfp_warning("Could not create dbus message for %s", vol_udi);
+		  continue;
+		}
+
+	      options = calloc(1, sizeof (char *));
+	      if (options == NULL)
+                {
+                  hfp_warning("Could not allocation memory for options");
+		  dbus_message_unref(msg);
+		  continue;
+		}
+
+	      options[0] = "force";
+	      num_options = 1;
+
+	      devfile = libhal_device_get_property_string(hfp_ctx, vol_udi, "block.device", NULL);
+	      if (devfile != NULL)
+                {
+                  hfp_info("Forcibly attempting to unmount %s as media was removed", devfile);
+		  libhal_free_string(devfile);
+		}
+
+	      if (! dbus_message_append_args(msg, DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &options, num_options, DBUS_TYPE_INVALID))
+                 {
+                   hfp_warning("Could not append args to dbus message for %s", vol_udi);
+		   free(options);
+		   dbus_message_unref(msg);
+		   continue;
+		 }
+
+	      if (! (reply = dbus_connection_send_with_reply_and_block(dbus_connection, msg, -1, &hfp_error)))
+                {
+                  hfp_warning("Unmount failed for %s: %s: %s", vol_udi, hfp_error.name, hfp_error.message);
+		  dbus_error_free(&hfp_error);
+		  free(options);
+		  dbus_message_unref(msg);
+		  continue;
+		}
+
+	      if (dbus_error_is_set(&hfp_error))
+                {
+                  hfp_warning("Unmount failed for %s: %s : %s", vol_udi, hfp_error.name, hfp_error.message);
+		  dbus_error_free(&hfp_error);
+		  free(options);
+		  dbus_message_unref(msg);
+		  dbus_message_unref(reply);
+		  continue;
+		}
+
+	      hfp_info("Successfully unmounted udi '%s'", vol_udi);
+	      free(options);
+              dbus_message_unref(msg);
+              dbus_message_unref(reply);
+	    }
+	}
+      libhal_free_string_array(volumes);
+    }
+}
+
 static boolean
-poll_for_media (void)
+poll_for_media (boolean check_only, boolean force)
 {
   boolean has_media;
 
+  if (check_lock_state)
+    {
+      boolean should_poll;
+
+      check_lock_state = FALSE;
+
+      hfp_info("Checking whether device %s is locked by HAL", addon.device_file);
+      if (libhal_device_is_locked_by_others(hfp_ctx, hfp_udi, "org.freedesktop.Hal.Device.Storage", NULL))
+        {
+          hfp_info("... device %s is locked by HAL", addon.device_file);
+	  is_locked_by_hal = TRUE;
+	  update_proc_title(addon.device_file);
+	  goto skip_check;
+	}
+      else
+        {
+          hfp_info("... device %s is not locked by HAL", addon.device_file);
+	  is_locked_by_hal = FALSE;
+	}
+
+      should_poll = libhal_device_get_property_bool(hfp_ctx, hfp_udi, "storage.media_check_enabled", NULL);
+      polling_disabled = ! should_poll;
+      update_proc_title(addon.device_file);
+    }
+
+  if (! force && polling_disabled)
+    goto skip_check;
+
   has_media = hf_addon_storage_update();
+  if (check_only)
+    return has_media;
+
   if (has_media != addon.had_media)
     {
       /*
@@ -168,27 +298,47 @@ poll_for_media (void)
        * then hung while rebooting and did not unmount my other
        * filesystems.
        */
+#if __FreeBSD_version >= 800066
+      /*
+       * With newusb, it is safe to force unmount volumes.  This may be
+       * safe on newer versions of the old USB stack, but we'll be
+       * extra cautious.
+       */
+      unmount_volumes();
+#endif
 
-      libhal_device_rescan(hfp_ctx, hfp_udi, &hfp_error);
-      dbus_error_free(&hfp_error);
+      libhal_device_rescan(hfp_ctx, hfp_udi, NULL);
       addon.had_media = has_media;
 
       return TRUE;
     }
+
+skip_check:
+
   return FALSE;
 }
 
 static void
-update_proc_title (const char *device, boolean polling_enabled)
+update_proc_title (const char *device)
 {
-  if (polling_enabled)
-    setproctitle("%s", device);
-  else
+  if (polling_disabled)
     setproctitle("no polling on %s because it is explicitly disabled", device);
+  else if (is_locked_by_hal)
+    setproctitle("no polling on %s because it is locked by HAL", device);
+  else
+    setproctitle("%s", device);
 }
 
 static DBusHandlerResult
-filter_function (DBusConnection *connection, DBusMessage *message, void *user_data)
+dbus_filter_function (DBusConnection *connection, DBusMessage *message, void *user_data)
+{
+  check_lock_state = TRUE;
+
+  return DBUS_HANDLER_RESULT_HANDLED;
+}
+
+static DBusHandlerResult
+direct_filter_function (DBusConnection *connection, DBusMessage *message, void *user_data)
 {
   if (dbus_message_is_method_call(message,
 			  	  "org.freedesktop.Hal.Device.Storage.Removable",
@@ -199,7 +349,7 @@ filter_function (DBusConnection *connect
 
       hfp_info("Forcing poll for media becusse CheckForMedia() was called");
 
-      had_effect = poll_for_media();
+      had_effect = poll_for_media(FALSE, TRUE);
 
       reply = dbus_message_new_method_return (message);
       dbus_message_append_args(reply, DBUS_TYPE_BOOLEAN, &had_effect, DBUS_TYPE_INVALID);
@@ -217,8 +367,9 @@ main (int argc, char **argv)
   char *removable;
   char *bus;
   char *driver;
-  boolean should_poll;
+  char *filter_str;
   DBusConnection *connection;
+  DBusConnection *syscon;
 
   if (! hfp_init(argc, argv))
     goto end;
@@ -251,16 +402,39 @@ main (int argc, char **argv)
   addon.is_scsi_removable = (! strcmp(bus, "scsi") ||
     (! strcmp(bus, "usb") && (! strcmp(driver, "da") || ! strcmp(driver, "sa") ||
     ! strcmp(driver, "cd")))) && ! strcmp(removable, "true");
-  addon.had_media = hf_addon_storage_update();
+  addon.had_media = poll_for_media(TRUE, FALSE);
 
-  if (! libhal_device_addon_is_ready(hfp_ctx, hfp_udi, &hfp_error))
+  if (! libhal_device_addon_is_ready(hfp_ctx, hfp_udi, NULL))
     goto end;
-  dbus_error_free(&hfp_error);
+
+  syscon = dbus_bus_get(DBUS_BUS_SYSTEM, NULL);
+  assert(syscon != NULL);
+  dbus_connection_set_exit_on_disconnect(syscon, 0);
+
+  dbus_bus_add_match(syscon,
+		     "type='signal'"
+		     ",interface='org.freedesktop.Hal.Manager'"
+		     ",sender='org.freedesktop.Hal'",
+		     NULL);
+  dbus_bus_add_match(syscon,
+		     "type='signal'"
+		     ",interface='org.freedesktop.Hal.Manager'"
+		     ",sender='org.freedesktop.Hal'",
+		     NULL);
+  filter_str = hfp_strdup_printf("type='signal'"
+		  	       ",interface='org.freedesktop.Hal.Device'"
+			       ",sender='org.freedesktop.Hal'"
+			       ",path='%s'",
+			       hfp_udi);
+  dbus_bus_add_match(syscon, filter_str, NULL);
+  hfp_free(filter_str);
+
+  dbus_connection_add_filter(syscon, dbus_filter_function, NULL, NULL);
 
   connection = libhal_ctx_get_dbus_connection(hfp_ctx);
   assert(connection != NULL);
   dbus_connection_set_exit_on_disconnect(connection, 0);
-  dbus_connection_add_filter(connection, filter_function, NULL, NULL);
+  dbus_connection_add_filter(connection, direct_filter_function, NULL, NULL);
 
   if (! libhal_device_claim_interface(hfp_ctx,
 			 	      hfp_udi,
@@ -268,52 +442,43 @@ main (int argc, char **argv)
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
       /* process dbus traffic until update interval has elapsed */
       while (TRUE)
 	{
-	  struct timeval now;
+	  struct timespec now;
 
-	  hfp_gettimeofday(&now);
-	  if (hfp_timevalcmp(&now, &addon.next_update, <))
+	  hfp_clock_gettime(&now);
+	  if (hfp_timespeccmp(&now, &addon.next_update, <))
 	    {
-	      struct timeval timeout;
+	      struct timespec timeout;
 
 	      timeout = addon.next_update;
-	      hfp_timevalsub(&timeout, &now);
+	      hfp_timespecsub(&timeout, &now);
 
 	      if (timeout.tv_sec < 0) /* current time went backwards */
 		timeout = addon.update_interval;
 
-	      dbus_connection_read_write_dispatch(connection, timeout.tv_sec * 1000 + timeout.tv_usec / 1000);
-	      if (! dbus_connection_get_is_connected(connection))
+	      dbus_connection_read_write_dispatch(connection, (int) ((timeout.tv_sec * 1000 + timeout.tv_nsec / 1000000) / 2));
+	      dbus_connection_read_write_dispatch(syscon, (int) ((timeout.tv_sec * 1000 + timeout.tv_nsec / 1000000) / 2));
+	      if (! dbus_connection_get_is_connected(connection) ||
+		  ! dbus_connection_get_is_connected(syscon))
 		goto end;
 	    }
 	  else
 	    break;
 	}
 
-      should_poll = libhal_device_get_property_bool(hfp_ctx, hfp_udi, "storage.media_check_enabled", &hfp_error);
-      dbus_error_free(&hfp_error);
-      update_proc_title(addon.device_file, should_poll);
-
-      if (should_poll)
-        {
-          poll_for_media();
-        }
-      else
-        {
-          hfp_gettimeofday(&addon.next_update);
-	  hfp_timevaladd(&addon.next_update, &addon.update_interval);
-	}
+      poll_for_media(FALSE, FALSE);
+      hfp_clock_gettime(&addon.next_update);
+      hfp_timespecadd(&addon.next_update, &addon.update_interval);
     }
 
  end:
