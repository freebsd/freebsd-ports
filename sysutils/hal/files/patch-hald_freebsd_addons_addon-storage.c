--- hald/freebsd/addons/addon-storage.c.orig	2008-03-17 17:25:16.000000000 -0400
+++ hald/freebsd/addons/addon-storage.c	2008-03-22 03:25:19.000000000 -0400
@@ -150,6 +150,34 @@ hf_addon_storage_update (void)
   return has_media;
 }
 
+static boolean
+poll_for_media (void)
+{
+  boolean has_media;
+
+  has_media = hf_addon_storage_update();
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
+  return FALSE;
+}
+
 static void
 update_proc_title (const char *device, boolean polling_enabled)
 {
@@ -159,6 +187,29 @@ update_proc_title (const char *device, b
     setproctitle("no polling on %s because it is explicitly disabled", device);
 }
 
+static DBusHandlerResult
+filter_function (DBusConnection *connection, DBusMessage *message, void *user_data)
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
+      had_effect = poll_for_media();
+
+      reply = dbus_message_new_method_return (message);
+      dbus_message_append_args(reply, DBUS_TYPE_BOOLEAN, &had_effect, DBUS_TYPE_INVALID);
+      dbus_connection_send(connection, reply, NULL);
+      dbus_message_unref(reply);
+    }
+
+  return DBUS_HANDLER_RESULT_HANDLED;
+}
+
 int
 main (int argc, char **argv)
 {
@@ -202,13 +253,30 @@ main (int argc, char **argv)
     ! strcmp(driver, "cd")))) && ! strcmp(removable, "true");
   addon.had_media = hf_addon_storage_update();
 
+  if (! libhal_device_addon_is_ready(hfp_ctx, hfp_udi, &hfp_error))
+    goto end;
+  dbus_error_free(&hfp_error);
+
   connection = libhal_ctx_get_dbus_connection(hfp_ctx);
   assert(connection != NULL);
+  dbus_connection_set_exit_on_disconnect(connection, 0);
+  dbus_connection_add_filter(connection, filter_function, NULL, NULL);
 
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
@@ -225,7 +293,7 @@ main (int argc, char **argv)
 	      if (timeout.tv_sec < 0) /* current time went backwards */
 		timeout = addon.update_interval;
 
-	      dbus_connection_read_write(connection, timeout.tv_sec * 1000 + timeout.tv_usec / 1000);
+	      dbus_connection_read_write_dispatch(connection, timeout.tv_sec * 1000 + timeout.tv_usec / 1000);
 	      if (! dbus_connection_get_is_connected(connection))
 		goto end;
 	    }
@@ -239,24 +307,7 @@ main (int argc, char **argv)
 
       if (should_poll)
         {
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
+          poll_for_media();
         }
       else
         {
