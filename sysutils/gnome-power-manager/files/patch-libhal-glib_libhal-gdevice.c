--- libhal-glib/libhal-gdevice.c.orig	2009-04-19 02:15:52.000000000 -0400
+++ libhal-glib/libhal-gdevice.c	2009-04-19 02:16:09.000000000 -0400
@@ -280,7 +280,7 @@ hal_gdevice_query_capability (HalGDevice
 		return FALSE;
 	}
 	ret = dbus_g_proxy_call (proxy, "QueryCapability", error,
-				 G_TYPE_STRING, device->priv->udi,
+				 G_TYPE_STRING, capability,
 				 G_TYPE_INVALID,
 				 G_TYPE_BOOLEAN, has_capability,
 				 G_TYPE_INVALID);
