--- src/pitivi-progressbar.c.orig	Mon Dec 20 13:14:17 2004
+++ src/pitivi-progressbar.c	Mon Dec 20 13:16:17 2004
@@ -137,17 +137,19 @@
 				guint n_construct_properties,
 				GObjectConstructParam * construct_properties)
 {
+  PitiviProgressBarClass *klass;
   GtkWidget *main_vbox;
   GObjectClass *parent_class;
-  PitiviProgressBarClass *klass;
-  
+  GObject *obj;
+  PitiviProgressBar *self;  
+
   /* Invoke parent constructor. */
   
   klass = PITIVI_PROGRESSBAR_CLASS (g_type_class_peek (PITIVI_PROGRESSBAR_TYPE));
   parent_class = G_OBJECT_CLASS (g_type_class_peek_parent (klass));
-  GObject *obj = parent_class->constructor (type, n_construct_properties,
+  obj = parent_class->constructor (type, n_construct_properties,
 				   construct_properties);
-  PitiviProgressBar *self = (PitiviProgressBar *) obj;
+  self = (PitiviProgressBar *) obj;
   
   /* window properties */
   gtk_window_set_title (GTK_WINDOW(self), "Loading");
