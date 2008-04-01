--- hald/freebsd/addons/addon-storage.c.orig	2008-03-17 17:25:16.000000000 -0400
+++ hald/freebsd/addons/addon-storage.c	2008-03-31 04:41:55.000000000 -0400
@@ -36,17 +36,23 @@
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
+
 /* see MMC-3 Working Draft Revision 10 */
 static boolean
 hf_addon_storage_cdrom_eject_pressed (HFPCDROM *cdrom)
@@ -144,19 +150,114 @@ hf_addon_storage_update (void)
 	}
     }
 
-  hfp_gettimeofday(&addon.next_update);
-  hfp_timevaladd(&addon.next_update, &addon.update_interval);
-
   return has_media;
 }
 
+static boolean
+poll_for_media (boolean check_only, boolean force)
+{
+  boolean has_media;
+
+  if (check_lock_state)
+    {
+      boolean should_poll;
+
+      check_lock_state = FALSE;
+
+      hfp_info("Checking whether device %s is locked by HAL", addon.device_file);
+      if (libhal_device_is_locked_by_others(hfp_ctx, hfp_udi, "org.freedesktop.Hal.Device.Storage", &hfp_error))
+        {
+          hfp_info("... device %s is locked by HAL", addon.device_file);
+	  dbus_error_free(&hfp_error);
+	  is_locked_by_hal = TRUE;
+	  update_proc_title(addon.device_file);
+	  goto skip_check;
+	}
+      else
+        {
+          hfp_info("... device %s is not locked by HAL", addon.device_file);
+	  is_locked_by_hal = FALSE;
+	}
+      dbus_error_free(&hfp_error);
+
+      should_poll = libhal_device_get_property_bool(hfp_ctx, hfp_udi, "storage.media_check_enabled", &hfp_error);
+      dbus_error_free(&hfp_error);
+      polling_disabled = ! should_poll;
+      update_proc_title(addon.device_file);
+    }
+
+  if (! force && polling_disabled)
+    goto skip_check;
+
+  has_media = hf_addon_storage_update();
+  if (check_only)
+    return has_media;
+
+  if (has_media != addon.had_media)
+    {
+      /*
+       * FIXME: if the media was removed, we should force-unmount
+       * all its child volumes (see linux2/addons/addon-storage.c).
+       * However, currently (FreeBSD 6.0) umount -f is broken and
+       * can cause kernel panics. When I tried to umount -f a
+       * flash card after removing it, it failed with EAGAIN. It
+       * continued to fail after I inserted the card. The system
+       * then hung while rebooting and did not unmount my other
+       * filesystems.
+       */
+
+      libhal_device_rescan(hfp_ctx, hfp_udi, &hfp_error);
+      dbus_error_free(&hfp_error);
+      addon.had_media = has_media;
+
+      return TRUE;
+    }
+
+skip_check:
+
+  return FALSE;
+}
+
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
+}
+
+static DBusHandlerResult
+dbus_filter_function (DBusConnection *connection, DBusMessage *message, void *user_data)
+{
+  check_lock_state = TRUE;
+
+  return DBUS_HANDLER_RESULT_HANDLED;
+}
+
+static DBusHandlerResult
+direct_filter_function (DBusConnection *connection, DBusMessage *message, void *user_data)
+{
+  if (dbus_message_is_method_call(message,
+			  	  "org.freedesktop.Hal.Device.Storage.Removable",
+				  "CheckForMedia"))
+    {
+      DBusMessage *reply;
+      dbus_bool_t had_effect;
+
+      hfp_info("Forcing poll for media becusse CheckForMedia() was called");
+
+      had_effect = poll_for_media(FALSE, TRUE);
+
+      reply = dbus_message_new_method_return (message);
+      dbus_message_append_args(reply, DBUS_TYPE_BOOLEAN, &had_effect, DBUS_TYPE_INVALID);
+      dbus_connection_send(connection, reply, NULL);
+      dbus_message_unref(reply);
+    }
+
+  return DBUS_HANDLER_RESULT_HANDLED;
 }
 
 int
@@ -166,8 +267,9 @@ main (int argc, char **argv)
   char *removable;
   char *bus;
   char *driver;
-  boolean should_poll;
+  char *filter_str;
   DBusConnection *connection;
+  DBusConnection *syscon;
 
   if (! hfp_init(argc, argv))
     goto end;
@@ -200,69 +302,86 @@ main (int argc, char **argv)
   addon.is_scsi_removable = (! strcmp(bus, "scsi") ||
     (! strcmp(bus, "usb") && (! strcmp(driver, "da") || ! strcmp(driver, "sa") ||
     ! strcmp(driver, "cd")))) && ! strcmp(removable, "true");
-  addon.had_media = hf_addon_storage_update();
+  addon.had_media = poll_for_media(TRUE, FALSE);
+
+  if (! libhal_device_addon_is_ready(hfp_ctx, hfp_udi, &hfp_error))
+    goto end;
+  dbus_error_free(&hfp_error);
+
+  syscon = dbus_bus_get(DBUS_BUS_SYSTEM, &hfp_error);
+  dbus_error_free(&hfp_error);
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
+  dbus_connection_set_exit_on_disconnect(connection, 0);
+  dbus_connection_add_filter(connection, direct_filter_function, NULL, NULL);
 
-  while (TRUE)
+  if (! libhal_device_claim_interface(hfp_ctx,
+			 	      hfp_udi,
+				      "org.freedesktop.Hal.Device.Storage.Removable",
+				      "    <method name=\"CheckForMedia\">\n"
+				      "      <arg name=\"call_had_sideeffect\" direction=\"out\" type=\"b\"/>\n"
+				      "    </method>\n",
+				      &hfp_error))
     {
-      boolean has_media;
+      hfp_critical("Cannot claim interface 'org.freedesktop.Hal.Device.Storage.Removable'");
+      goto end;
+    }
+  dbus_error_free(&hfp_error);
 
+  while (TRUE)
+    {
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
 
-	      dbus_connection_read_write(connection, timeout.tv_sec * 1000 + timeout.tv_usec / 1000);
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
-          has_media = hf_addon_storage_update();
-          if (has_media != addon.had_media)
-	    {
-	      /*
-	       * FIXME: if the media was removed, we should force-unmount
-	       * all its child volumes (see linux2/addons/addon-storage.c).
-	       * However, currently (FreeBSD 6.0) umount -f is broken and
-	       * can cause kernel panics. When I tried to umount -f a
-	       * flash card after removing it, it failed with EAGAIN. It
-	       * continued to fail after I inserted the card. The system
-	       * then hung while rebooting and did not unmount my other
-	       * filesystems.
-	       */
-
-	      libhal_device_rescan(hfp_ctx, hfp_udi, &hfp_error);
-	      dbus_error_free(&hfp_error);
-	      addon.had_media = has_media;
-	    }
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
