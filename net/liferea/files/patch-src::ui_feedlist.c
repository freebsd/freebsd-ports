--- src/ui_feedlist.c.orig	Tue May 17 10:44:47 2005
+++ src/ui_feedlist.c	Tue May 17 10:45:11 2005
@@ -821,7 +821,7 @@
 	dbus_connection_setup_with_g_main (connection, NULL);
 	    
 	/* Register for the FeedReader service on the bus, so we get method calls */
-    dbus_bus_acquire_service (connection, DBUS_RSS_SERVICE, 0, &error);
+    dbus_bus_request_name (connection, DBUS_RSS_SERVICE, 0, &error);
 	if (dbus_error_is_set (&error))
 	{
 		fprintf (stderr, "*** ui_feedlist.c: Failed to get dbus service: %s | %s\n", error.name, error.message);
