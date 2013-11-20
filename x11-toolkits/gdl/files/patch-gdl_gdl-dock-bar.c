--- gdl/gdl-dock-bar.c.orig	2012-08-05 19:14:31.000000000 +0000
+++ gdl/gdl-dock-bar.c	2013-06-18 07:48:39.000000000 +0000
@@ -484,7 +484,8 @@
 {
     GdlDockBarStyle style;
 
-    g_return_if_fail (GDL_IS_DOCK_BAR (dockbar));
+    if (!GDL_IS_DOCK_BAR (dockbar))
+        return NULL;
 
     g_object_get(G_OBJECT(dockbar), "dockbar-style", &style, NULL);
 
