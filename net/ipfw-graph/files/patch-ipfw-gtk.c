--- ipfw-gtk.c.orig	Sat Nov 17 15:50:05 2001
+++ ipfw-gtk.c	Sat Nov 17 15:50:14 2001
@@ -230,7 +230,7 @@
 
 //  text_area=gtk_label_new("blaat");
     text_area=gtk_entry_new();
-    gtk_entry_set_text(text_area,"blaat");
+    gtk_entry_set_text((GtkEntry *)text_area,"blaat");
     gtk_box_pack_start(GTK_BOX(vbox),text_area,FALSE,FALSE,0);
     gtk_widget_show(text_area);
 
