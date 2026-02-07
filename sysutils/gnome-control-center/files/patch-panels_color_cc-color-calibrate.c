--- panels/color/cc-color-calibrate.c.orig	2025-05-26 08:10:04 UTC
+++ panels/color/cc-color-calibrate.c
@@ -767,9 +767,9 @@ cc_color_calibrate_setup (CcColorCalibrate *calibrate,
   calibrate->proxy_inhibit = g_dbus_proxy_new_for_bus_sync (G_BUS_TYPE_SYSTEM,
                                                             G_DBUS_PROXY_FLAGS_NONE,
                                                             NULL,
-                                                            "org.freedesktop.login1",
-                                                            "/org/freedesktop/login1",
-                                                            "org.freedesktop.login1.Manager",
+                                                            "org.freedesktop.ConsoleKit",
+                                                            "/org/freedesktop/ConsoleKit/Manager",
+                                                            "org.freedesktop.ConsoleKit.Manager",
                                                             NULL,
                                                             error);
   if (calibrate->proxy_inhibit == NULL)
