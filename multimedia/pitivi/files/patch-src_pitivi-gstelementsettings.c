--- src/pitivi-gstelementsettings.c.orig	Mon Dec 20 13:56:47 2004
+++ src/pitivi-gstelementsettings.c	Mon Dec 20 13:57:28 2004
@@ -872,12 +872,13 @@
 			     GObjectConstructParam * construct_properties)
 {
   GObject *obj;
+  PitiviGstElementSettings *self;
   /* Invoke parent constructor. */
   obj =  G_OBJECT_CLASS (parent_class)->constructor (type, n_construct_properties,
 						     construct_properties);
 
   /* do stuff. */
-  PitiviGstElementSettings *self = (PitiviGstElementSettings *) obj;
+  self = (PitiviGstElementSettings *) obj;
 
   pitivi_gstelementsettings_create_gui (self);
 
