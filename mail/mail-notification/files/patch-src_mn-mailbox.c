--- src/mn-mailbox.c.orig	Mon May  9 20:49:29 2005
+++ src/mn-mailbox.c	Mon May  9 20:51:26 2005
@@ -913,31 +913,11 @@
 {
 #line 378 "mn-mailbox.gob"
 	
-    GnomeVFSResult result;
-
     g_return_if_fail(MN_MAILBOX_CAN_CHECK(self));
     g_return_if_fail(selfp->monitor_handle == NULL);
     
-    gdk_flush();
-    GDK_THREADS_LEAVE();
-
-    result = gnome_vfs_monitor_add(&selfp->monitor_handle,
-				   uri,
-				   monitor_type,
-				   self_monitor_cb,
-				   self);
-
-    GDK_THREADS_ENTER();
-    
-    if (result == GNOME_VFS_OK)
-      {
-	selfp->monitor_uri = g_strdup(uri);
-	selfp->monitor_events = events;
-	self_set_must_poll(self, FALSE);
-      }
-    else
       {
-	self_warning(self, _("unable to enable immediate notification: %s"), gnome_vfs_result_to_string(result));
+	self_warning(self, _("unable to enable immediate notification: broken, will be fixed in the next release"));
 
 	if (! eel_gconf_get_boolean(MN_CONF_IMMEDIATE_NOTIFICATION_ERROR_DIALOG_DO_NOT_SHOW))
 	  {
