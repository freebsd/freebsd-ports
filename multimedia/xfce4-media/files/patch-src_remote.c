--- src/remote.c.orig	2006-04-08 16:24:13.000000000 +0000
+++ src/remote.c
@@ -489,8 +489,7 @@ xfmedia_remote_init(XfmediaMainwin *mwin
     for(i = 0; i < MAX_INSTANCES; i++) {
         g_snprintf(name, 64, XFMEDIA_DBUS_SERVICE_FMT, i);
         dbus_error_init(&derr);
-        ret = dbus_bus_request_name(dbus_conn, name,
-                DBUS_NAME_FLAG_PROHIBIT_REPLACEMENT, &derr);
+        ret = dbus_bus_request_name(dbus_conn, name, 0, &derr);
         if(ret < 0) {
             g_warning("Unable to acquire D-BUS service '%s': %s." \
                 "  Remote control interface will not be available.",
