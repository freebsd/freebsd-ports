--- libgcpcanvas/gcp-canvas-group.c.orig	Sun Oct 12 13:51:42 2003
+++ libgcpcanvas/gcp-canvas-group.c	Sun Nov  9 00:51:10 2003
@@ -92,9 +92,9 @@
 
 void gnome_canvas_group_ext_print (GPrintable *printable, GnomePrintContext *pc)
 {
-	g_return_if_fail (GNOME_IS_CANVAS_GROUP_EXT (printable));
 	GList *list;
 	double affine[6];
+	g_return_if_fail (GNOME_IS_CANVAS_GROUP_EXT (printable));
 	for (list = GNOME_CANVAS_GROUP (printable) ->item_list; list; list = list->next) {
 		if (GNOME_IS_CANVAS_GROUP_EXT(list->data))
 			gnome_canvas_group_ext_print (G_PRINTABLE (list->data), pc);
