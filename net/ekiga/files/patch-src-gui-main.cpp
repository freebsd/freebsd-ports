--- src/gui/main.cpp.orig	Thu Jun 22 10:00:56 2006
+++ src/gui/main.cpp	Thu Jun 22 10:03:18 2006
@@ -1282,7 +1282,7 @@
     gtk_container_set_border_width (GTK_CONTAINER (button), 0);
     gtk_container_add (GTK_CONTAINER (button), box);
    
-    gtk_widget_add_accelerator (button, "activate", 
+    gtk_widget_add_accelerator (button, "clicked", 
 				mw->accel, key_kp [i], 
 				(GdkModifierType) 0, (GtkAccelFlags) 0);
     
