--- src/pitivi-lplayerwindow.c.orig	Mon Dec 20 13:58:25 2004
+++ src/pitivi-lplayerwindow.c	Mon Dec 20 13:59:02 2004
@@ -374,13 +374,15 @@
 {
   GstElement *elem;
   GObject *obj;
+  PitiviLPlayerWindow *self;
+
   /* Invoke parent constructor. */
   obj = parent_class->constructor (type, n_construct_properties,
 				   construct_properties);
 
   /* do stuff. */
   PITIVI_DEBUG("lplayer creation !");
-  PitiviLPlayerWindow *self = (PitiviLPlayerWindow *) obj;
+  self = (PitiviLPlayerWindow *) obj;
 
   pitivi_lplayerwindow_create_gui (self);
 
