--- gal/e-table/e-table-group.c.orig	Thu Nov 28 13:51:22 2002
+++ gal/e-table/e-table-group.c	Thu Nov 28 22:23:01 2002
@@ -22,6 +22,7 @@
  */
 
 #include <config.h>
+#include <stdarg.h>
 #include <gtk/gtksignal.h>
 #include <libgnomecanvas/gnome-canvas-rect-ellipse.h>
 #include "e-table-group.h"
@@ -129,13 +130,14 @@
 			 ETableHeader     *header,
 			 ETableModel      *model)
 {
+	va_list args;
 	etg->full_header = full_header;
 	gtk_object_ref (GTK_OBJECT(etg->full_header));
 	etg->header = header;
 	gtk_object_ref (GTK_OBJECT(etg->header));
 	etg->model = model;
 	gtk_object_ref (GTK_OBJECT(etg->model));
-	gnome_canvas_item_construct (GNOME_CANVAS_ITEM (etg), parent, 0, NULL);
+	gnome_canvas_item_construct (GNOME_CANVAS_ITEM (etg), parent, 0, args);
 }
 
 /**
