Index: gtk/gtkimage.c
===================================================================
RCS file: /cvs/gnome/gtk+/gtk/gtkimage.c,v
retrieving revision 1.54.2.5
diff -p -u -r1.54.2.5 gtkimage.c
--- gtk/gtkimage.c	9 Apr 2005 02:51:02 -0000	1.54.2.5
+++ gtk/gtkimage.c	9 Apr 2005 15:55:36 -0000
@@ -1545,7 +1545,6 @@ gtk_image_expose (GtkWidget      *widget
       GdkBitmap *mask;
       GdkPixbuf *pixbuf;
       gboolean needs_state_transform;
-      GtkStockItem item;
       gchar *stock_id;
 	  
       
@@ -1655,7 +1654,7 @@ gtk_image_expose (GtkWidget      *widget
           break;
 
         case GTK_IMAGE_STOCK:
-	  if (gtk_stock_lookup (image->data.stock.stock_id, &item))
+	  if (gtk_style_lookup_icon_set (widget->style, image->data.stock.stock_id))
 	    stock_id = image->data.stock.stock_id;
 	  else
 	    stock_id = GTK_STOCK_MISSING_IMAGE;
@@ -1955,7 +1954,6 @@ gtk_image_calc_size (GtkImage *image)
 {
   GtkWidget *widget = GTK_WIDGET (image);
   GdkPixbuf *pixbuf = NULL;
-  GtkStockItem item;
   gchar *stock_id;
   
   /* We update stock/icon set on every size request, because
@@ -1966,7 +1964,7 @@ gtk_image_calc_size (GtkImage *image)
   switch (image->storage_type)
     {
     case GTK_IMAGE_STOCK:
-      if (gtk_stock_lookup (image->data.stock.stock_id, &item))
+      if (gtk_style_lookup_icon_set (widget->style, image->data.stock.stock_id))
 	stock_id = image->data.stock.stock_id;
       else
 	stock_id = GTK_STOCK_MISSING_IMAGE;
