--- avahi-daemon/dbus-protocol.c.orig	Fri Nov 10 21:50:07 2006
+++ avahi-daemon/dbus-protocol.c	Fri Nov 10 21:50:55 2006
@@ -1067,7 +1067,7 @@ static int dbus_connect(void) {
     if (dbus_bus_request_name(
             server->bus,
             AVAHI_DBUS_NAME,
-#if (DBUS_VERSION_MAJOR == 0) && (DBUS_VERSION_MINOR >= 60)
+#if ((DBUS_VERSION_MAJOR == 0) && (DBUS_VERSION_MINOR >= 60)) || DBUS_VERSION_MAJOR > 0
             DBUS_NAME_FLAG_DO_NOT_QUEUE,
 #else
             DBUS_NAME_FLAG_PROHIBIT_REPLACEMENT,
