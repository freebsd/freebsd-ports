--- gal/e-table/e-table-group.c.orig	Wed Nov 20 10:02:06 2002
+++ gal/e-table/e-table-group.c	Thu Feb  6 22:35:27 2003
@@ -22,6 +22,7 @@
  */
 
 #include <config.h>
+#include <stdarg.h>
 #include <gtk/gtksignal.h>
 #include <libgnomecanvas/gnome-canvas-rect-ellipse.h>
 #include "e-table-group.h"
@@ -128,13 +129,14 @@
 			 ETableHeader     *header,
 			 ETableModel      *model)
 {
+	va_list args;
 	etg->full_header = full_header;
 	g_object_ref (etg->full_header);
 	etg->header = header;
 	g_object_ref (etg->header);
 	etg->model = model;
 	g_object_ref (etg->model);
-	gnome_canvas_item_construct (GNOME_CANVAS_ITEM (etg), parent, 0, NULL);
+	gnome_canvas_item_construct (GNOME_CANVAS_ITEM (etg), parent, 0, args);
 }
 
 /**
