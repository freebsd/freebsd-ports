--- libepc/service-monitor.c.orig	2008-03-24 00:54:58.000000000 +0100
+++ libepc/service-monitor.c	2008-03-24 00:56:35.000000000 +0100
@@ -307,7 +307,11 @@ epc_service_monitor_dispose (GObject *ob
 
   while (self->priv->browsers)
     {
-      avahi_service_browser_free (self->priv->browsers->data);
+      // This is evil, the real fix would be to prevent NULL entries from being added.
+      if (self->priv->browsers->data != NULL)
+      {
+        avahi_service_browser_free (self->priv->browsers->data);
+      }
       self->priv->browsers = g_slist_delete_link (self->priv->browsers, self->priv->browsers);
     }
 
