From 66c69759423124f0bd661b28ceaaaab361a1c3e5 Mon Sep 17 00:00:00 2001
From: Debarshi Ray <debarshir@gnome.org>
Date: Fri, 20 Nov 2015 18:42:44 +0100
Subject: region: Silence a CRITICAL

Fall out from abb0592866515ac43ed1ac3c9ecc0b229960011f

https://bugzilla.gnome.org/show_bug.cgi?id=758417
---
 panels/region/cc-region-panel.c | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)

diff --git a/panels/region/cc-region-panel.c b/panels/region/cc-region-panel.c
index 8436b68..6cd5b85 100644
--- panels/region/cc-region-panel.c
+++ panels/region/cc-region-panel.c
@@ -166,7 +166,8 @@ cc_region_panel_finalize (GObject *object)
         g_free (priv->system_region);
 
         chooser = g_object_get_data (G_OBJECT (self), "input-chooser");
-        gtk_widget_destroy (chooser);
+        if (chooser)
+                gtk_widget_destroy (chooser);
 
 	G_OBJECT_CLASS (cc_region_panel_parent_class)->finalize (object);
 }
-- 
cgit v0.11.2

