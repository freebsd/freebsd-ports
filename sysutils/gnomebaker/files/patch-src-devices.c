--- src/devices.c.orig	Wed Oct 26 22:12:18 2005
+++ src/devices.c	Wed Oct 26 22:12:41 2005
@@ -779,7 +779,8 @@
     gchar* devicename = devices_get_device_config(devicekey, GB_DEVICE_NAME_LABEL);
     gchar* message = g_strdup_printf(_("Please insert a disk into the %s"), devicename);    
     gint ret = GTK_RESPONSE_OK;
-    while(!devices_is_disk_inserted(devicekey) && (ret == GTK_RESPONSE_OK))
+    /* while(!devices_is_disk_inserted(devicekey) && (ret == GTK_RESPONSE_OK)) */
+    if(!devices_is_disk_inserted(devicekey))
     {
         devices_eject_disk(devicekey);
         ret = gnomebaker_show_msg_dlg(parent, GTK_MESSAGE_INFO, 
