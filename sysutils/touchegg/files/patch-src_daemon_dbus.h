- Unix Domain Socket with Abstract Socket Address aren't supported on FreeBSD

--- src/daemon/dbus.h.orig	2023-01-15 09:10:50 UTC
+++ src/daemon/dbus.h
@@ -18,7 +18,11 @@
 #ifndef DAEMON_DBUS_H_
 #define DAEMON_DBUS_H_
 
+#if defined(__FreeBSD__)
+constexpr auto DBUS_ADDRESS = "unix:path=/tmp/touchegg#0";
+#else
 constexpr auto DBUS_ADDRESS = "unix:abstract=touchegg";
+#endif
 
 constexpr auto DBUS_OBJECT_PATH = "/io/github/joseexposito/Touchegg";
 
