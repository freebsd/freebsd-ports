--- src/pitivi-settingswindow.c.orig	Mon Dec 20 13:55:04 2004
+++ src/pitivi-settingswindow.c	Mon Dec 20 13:55:54 2004
@@ -701,12 +701,13 @@
 			     GObjectConstructParam * construct_properties)
 {
   GObject *obj;
+  PitiviSettingsWindow	*self;
   /* Invoke parent constructor. */
   obj = G_OBJECT_CLASS (parent_class)->constructor (type, n_construct_properties,
 						    construct_properties);
 
   /* do stuff. */
-  PitiviSettingsWindow	*self = (PitiviSettingsWindow *) obj;
+  self = (PitiviSettingsWindow *) obj;
 
   pitivi_settingswindow_create_gui (self);
 
