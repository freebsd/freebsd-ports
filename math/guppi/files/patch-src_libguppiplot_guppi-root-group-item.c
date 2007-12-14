--- src/libguppiplot/guppi-root-group-item.c.orig	2002-01-08 07:31:08.000000000 +0100
+++ src/libguppiplot/guppi-root-group-item.c	2007-12-13 15:36:33.000000000 +0100
@@ -153,10 +153,10 @@
   guppi_canvas_item_set_bbox_c (item, 0, 0, xsize, ysize);
 }
 
+static void canv_size_allocate (GtkWidget *, GtkAllocation *, gpointer);
 static void
 changed_scale (GuppiCanvasItem *item, double scale)
 {
-  static void canv_size_allocate (GtkWidget *, GtkAllocation *, gpointer);
   GuppiRootGroupItem *root_item = GUPPI_ROOT_GROUP_ITEM (item);
 
   if (GUPPI_CANVAS_ITEM_CLASS (parent_class)->changed_scale)
@@ -548,6 +548,7 @@
     return motion_notify_event (root, &(ev->motion));
 
   default:
+  ;
   }
 
   return FALSE;
@@ -777,6 +778,7 @@
   case ROOT_GROUP_RESIZE_NONE:
   default:
     /* insure we do nothing */
+    ;
   }
 
   if (please_resize_canvas)
