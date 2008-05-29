--- config/dbus-core.c.orig	2008-05-28 18:04:17.000000000 +0000
+++ config/dbus-core.c	2008-05-28 18:04:01.000000000 +0000
@@ -87,7 +87,8 @@
         dbus_connection_unref(bus_info.connection);
 
     RemoveBlockAndWakeupHandlers(block_handler, wakeup_handler, &bus_info);
-    RemoveGeneralSocket(bus_info.fd);
+    if (bus_info.fd != -1)
+        RemoveGeneralSocket(bus_info.fd);
     bus_info.fd = -1;
     bus_info.connection = NULL;
 


