--- gtkextra/gtkcolorcombo.c.orig	2004-09-16 17:48:05 UTC
+++ gtkextra/gtkcolorcombo.c
@@ -146,7 +146,7 @@ gtk_color_combo_class_init (GtkColorComb
                                       GTK_CLASS_TYPE(object_class),
                                       GTK_SIGNAL_OFFSET(GtkColorComboClass,
                                       changed),
-                                      gtkextra_VOID__INT_BOXED,
+                                      gtkextra_VOID__BOXED_BOXED,
                                       GTK_TYPE_NONE,  
                                       2, GTK_TYPE_INT, GDK_TYPE_COLOR);
 
