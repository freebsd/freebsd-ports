--- libgcpcanvas/gcp-canvas-shape.c.orig	Sun Oct 12 13:51:42 2003
+++ libgcpcanvas/gcp-canvas-shape.c	Sun Nov  9 00:53:27 2003
@@ -95,13 +95,13 @@
 
 void gnome_canvas_shape_ext_print (GPrintable *printable, GnomePrintContext *pc)
 {
-	g_return_if_fail (GNOME_IS_CANVAS_SHAPE_EXT (printable));
 	GnomeCanvasShape *shape;
 	GnomeCanvasShapePriv * priv;
 	GnomeCanvasPathDef * path;
 	gdouble width;
 	ArtBpath * bpath;
 	
+	g_return_if_fail (GNOME_IS_CANVAS_SHAPE_EXT (printable));
 	shape = GNOME_CANVAS_SHAPE (printable);
 	priv = shape->priv;
 	path = priv->path;
