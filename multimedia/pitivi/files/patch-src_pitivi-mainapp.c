--- src/pitivi-mainapp.c.orig	Mon Dec 20 13:10:23 2004
+++ src/pitivi-mainapp.c	Mon Dec 20 13:12:47 2004
@@ -136,8 +136,8 @@
 void
 pitivi_mainapp_callb_effects (GtkWindow *win, gpointer data)
 {
-  PITIVI_DEBUG("removed the effects window...\n");
   PitiviMainApp *self = data;
+  PITIVI_DEBUG("removed the effects window...\n");
   self->private->effectswin = NULL;
 }
 
@@ -409,6 +409,10 @@
 			    guint n_construct_properties,
 			    GObjectConstructParam * construct_properties)
 {
+  /* Invoke parent constructor. */
+  PitiviMainAppClass *klass;
+  GObjectClass *parent_class;
+
   PitiviMainApp	*self;
   gchar		*settingsfile;
   GObject	*obj;
@@ -418,9 +422,6 @@
   width = gdk_screen_width ();
   height = gdk_screen_height ();
 
-  /* Invoke parent constructor. */
-  PitiviMainAppClass *klass;
-  GObjectClass *parent_class;
   klass = PITIVI_MAINAPP_CLASS (g_type_class_peek (PITIVI_MAINAPP_TYPE));
   parent_class = G_OBJECT_CLASS (g_type_class_peek_parent (klass));
   obj = parent_class->constructor (type, n_construct_properties,
