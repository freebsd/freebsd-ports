--- src/hal-client.c.orig	2008-07-28 09:58:40.000000000 +1000
+++ src/hal-client.c	2008-07-28 09:59:09.000000000 +1000
@@ -188,7 +188,7 @@
     goto exit;
   }
 
-  if ( (strcmp(pw_status, "unset") == 0) || (strcmp(pw_status, "unlocked")) ) {
+  if ( (strcmp(pw_status, "unset") == 0) || (strcmp(pw_status, "unlocked") == 0) ) {
     g_ptr_array_remove_index(priv->pending_devices, i);
 
     if (!libhal_device_remove_property_watch(priv->hal_ctx, udi, &dbus_error))
