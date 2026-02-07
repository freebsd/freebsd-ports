--- src/properties.c.orig	Sat May 28 02:37:14 2005
+++ src/properties.c	Sat Nov 12 18:25:19 2005
@@ -30,8 +30,8 @@
   GtkListStore *Lmodel;
 
   if (Ainit == TRUE) {
-    Lmodel = gtk_list_store_new(4, G_TYPE_INT, GDK_TYPE_PIXBUF, G_TYPE_STRING, G_TYPE_STRING);
     GtkCellRenderer *Lcellrender;
+    Lmodel = gtk_list_store_new(4, G_TYPE_INT, GDK_TYPE_PIXBUF, G_TYPE_STRING, G_TYPE_STRING);
 
     gtk_combo_box_set_model(Acombo, GTK_TREE_MODEL(Lmodel));
     gtk_cell_layout_clear(GTK_CELL_LAYOUT(Acombo));
@@ -58,8 +58,8 @@
   GtkListStore *Lmodel;
 
   if (Ainit == TRUE) {
-    Lmodel = gtk_list_store_new(4, G_TYPE_INT, GDK_TYPE_PIXBUF, G_TYPE_STRING, G_TYPE_STRING);
     GtkCellRenderer *Lcellrender;
+    Lmodel = gtk_list_store_new(4, G_TYPE_INT, GDK_TYPE_PIXBUF, G_TYPE_STRING, G_TYPE_STRING);
 
     gtk_combo_box_set_model(Acombo, GTK_TREE_MODEL(Lmodel));
     gtk_cell_layout_clear(GTK_CELL_LAYOUT(Acombo));
