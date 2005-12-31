--- avahi-daemon/dbus-protocol.c.orig	Sat Dec 31 13:56:36 2005
+++ avahi-daemon/dbus-protocol.c	Sat Dec 31 14:02:18 2005
@@ -1029,7 +1029,11 @@ int dbus_protocol_setup(const AvahiPoll 
         goto fail;
     }
 
-    if (dbus_bus_request_name(server->bus, AVAHI_DBUS_NAME, DBUS_NAME_FLAG_PROHIBIT_REPLACEMENT, &error) != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER) {
+    if (dbus_bus_request_name(
+	  server->bus,
+	  AVAHI_DBUS_NAME,
+	  DBUS_NAME_FLAG_DO_NOT_QUEUE,
+	  &error) != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER) {
         if (dbus_error_is_set(&error)) {
             avahi_log_error("dbus_bus_request_name(): %s", error.message);
             goto fail;
