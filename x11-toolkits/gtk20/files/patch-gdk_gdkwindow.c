From d7ac9cd71c43689672a9796e518ef3b970197bf2 Mon Sep 17 00:00:00 2001
From: Matthias Clasen <mclasen@redhat.com>
Date: Mon, 20 Jun 2011 12:10:36 +0000
Subject: Revert "gdk: Make background changes queue a repaint"

This reverts commit 254b9a4c540e3dff1dcd17db2ceea6a9fa5df973.
---
diff --git a/gdk/gdkwindow.c b/gdk/gdkwindow.c
index 10d83ab..f058570 100644
--- gdk/gdkwindow.c
+++ gdk/gdkwindow.c
@@ -8004,15 +8004,11 @@ gdk_window_set_background (GdkWindow      *window,
     }
 
   if (!GDK_WINDOW_DESTROYED (window) &&
+      gdk_window_has_impl (private) &&
       !private->input_only)
     {
-      if (gdk_window_has_impl (private))
-        {
-          impl_iface = GDK_WINDOW_IMPL_GET_IFACE (private->impl);
-          impl_iface->set_background (window, &private->bg_color);
-        }
-      else
-        gdk_window_invalidate_rect_full (window, NULL, TRUE, CLEAR_BG_ALL);
+      impl_iface = GDK_WINDOW_IMPL_GET_IFACE (private->impl);
+      impl_iface->set_background (window, &private->bg_color);
     }
 }
 
@@ -8081,15 +8077,11 @@ gdk_window_set_back_pixmap (GdkWindow *window,
     private->bg_pixmap = GDK_NO_BG;
 
   if (!GDK_WINDOW_DESTROYED (window) &&
+      gdk_window_has_impl (private) &&
       !private->input_only)
     {
-      if (gdk_window_has_impl (private))
-        {
-          impl_iface = GDK_WINDOW_IMPL_GET_IFACE (private->impl);
-          impl_iface->set_back_pixmap (window, private->bg_pixmap);
-        }
-      else
-        gdk_window_invalidate_rect_full (window, NULL, TRUE, CLEAR_BG_ALL);
+      impl_iface = GDK_WINDOW_IMPL_GET_IFACE (private->impl);
+      impl_iface->set_back_pixmap (window, private->bg_pixmap);
     }
 }
 
--
cgit v0.9
