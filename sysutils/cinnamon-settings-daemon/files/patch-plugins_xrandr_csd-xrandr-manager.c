--- plugins/xrandr/csd-xrandr-manager.c.orig	2018-12-29 18:51:26.289097000 +0100
+++ plugins/xrandr/csd-xrandr-manager.c	2018-12-29 18:54:43.819478000 +0100
@@ -149,6 +149,8 @@
 static void handle_rotate_windows (CsdXrandrManager *mgr, GnomeRRRotation rotation, guint32 timestamp);
 static void rotate_touchscreens (CsdXrandrManager *mgr, GnomeRRRotation rotation);
 
+void register_manager_dbus (CsdXrandrManager *manager);
+
 G_DEFINE_TYPE (CsdXrandrManager, csd_xrandr_manager, G_TYPE_OBJECT)
 
 static gpointer manager_object = NULL;
