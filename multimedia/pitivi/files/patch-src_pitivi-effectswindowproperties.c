--- src/pitivi-effectswindowproperties.c.orig	Mon Dec 20 13:17:07 2004
+++ src/pitivi-effectswindowproperties.c	Mon Dec 20 13:17:47 2004
@@ -130,6 +130,7 @@
   GtkWidget *button_ok;
   GtkWidget *button_apply;
   GtkWidget *button_cancel;
+  PitiviEffectsWindowProperties *self;
 
   /* Invoke parent constructor. */
   
@@ -137,7 +138,7 @@
   parent_class = G_OBJECT_CLASS (g_type_class_peek_parent (klass));
   obj = parent_class->constructor (type, n_construct_properties,
 				   construct_properties);
-  PitiviEffectsWindowProperties *self = (PitiviEffectsWindowProperties *) obj;
+  self = (PitiviEffectsWindowProperties *) obj;
   
   /* do stuff. */
   
