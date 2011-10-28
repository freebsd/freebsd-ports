--- gtkextra/gtkcolorcombo.c.orig	2011-10-27 00:08:40.655552360 +0200
+++ gtkextra/gtkcolorcombo.c	2011-10-27 00:09:03.934648236 +0200
@@ -146,7 +146,7 @@
                                       GTK_CLASS_TYPE(object_class),
                                       GTK_SIGNAL_OFFSET(GtkColorComboClass,
                                       changed),
-                                      gtkextra_VOID__INT_BOXED,
+                                      gtkextra_VOID__BOXED_BOXED,
                                       GTK_TYPE_NONE,  
                                       2, GTK_TYPE_INT, GDK_TYPE_COLOR);

