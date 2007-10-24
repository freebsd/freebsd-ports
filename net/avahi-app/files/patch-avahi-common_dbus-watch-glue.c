--- avahi-common/dbus-watch-glue.c.orig	2007-08-26 00:46:45.000000000 -0400
+++ avahi-common/dbus-watch-glue.c	2007-08-26 00:47:12.000000000 -0400
@@ -134,7 +134,11 @@ static dbus_bool_t update_watch(const Av
 
         if (!(avahi_watch = poll_api->watch_new(
                   poll_api,
+#if (DBUS_VERSION_MAJOR == 1 && DBUS_VERSION_MINOR == 1 && DBUS_VERSION_MICRO >= 1) || (DBUS_VERSION_MAJOR == 1 && DBUS_VERSION_MAJOR > 1) || (DBUS_VERSION_MAJOR > 1)
                   dbus_watch_get_unix_fd(dbus_watch),
+#else
+		  dbus_watch_get_fd(dbus_watch),
+#endif
                   translate_dbus_to_avahi(dbus_watch_get_flags(dbus_watch)),
                   watch_callback,
                   dbus_watch)))
