
https://git.gnome.org/browse/gtk+/commit/?id=0731c502626d2b739281f7bb87f5cfd9d8a61ade

From 0731c502626d2b739281f7bb87f5cfd9d8a61ade Mon Sep 17 00:00:00 2001
From: Matthias Clasen <mclasen@redhat.com>
Date: Thu, 15 Oct 2015 20:16:54 -0400
Subject: entry completion: Only grab the device if we have one

When the entry completion is popped up from a timeout, we may
not have a device. In that case, don't call gdk_device_grab,
do avoid criticals.
---
 gtk/gtkentrycompletion.c | 21 ++++++++++++---------
 1 file changed, 12 insertions(+), 9 deletions(-)

diff --git a/gtk/gtkentrycompletion.c b/gtk/gtkentrycompletion.c
index cee8f25..9acae9d 100644
--- gtk/gtkentrycompletion.c
+++ gtk/gtkentrycompletion.c
@@ -1654,15 +1654,18 @@ gtk_entry_completion_popup (GtkEntryCompletion *completion)
 
   gtk_widget_show (completion->priv->popup_window);
 
-  gtk_device_grab_add (completion->priv->popup_window, completion->priv->device, TRUE);
-  gdk_device_grab (completion->priv->device, gtk_widget_get_window (completion->priv->popup_window),
-                   GDK_OWNERSHIP_WINDOW, TRUE,
-                   GDK_BUTTON_PRESS_MASK |
-                   GDK_BUTTON_RELEASE_MASK |
-                   GDK_POINTER_MOTION_MASK,
-                   NULL, GDK_CURRENT_TIME);
-
-  completion->priv->has_grab = TRUE;
+  if (completion->priv->device)
+    {
+      gtk_device_grab_add (completion->priv->popup_window, completion->priv->device, TRUE);
+      gdk_device_grab (completion->priv->device, gtk_widget_get_window (completion->priv->popup_window),
+                       GDK_OWNERSHIP_WINDOW, TRUE,
+                       GDK_BUTTON_PRESS_MASK |
+                       GDK_BUTTON_RELEASE_MASK |
+                       GDK_POINTER_MOTION_MASK,
+                       NULL, GDK_CURRENT_TIME);
+
+      completion->priv->has_grab = TRUE;
+    }
 }
 
 void
-- 
cgit v0.11.2

