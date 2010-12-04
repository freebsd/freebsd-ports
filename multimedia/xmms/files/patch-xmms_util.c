--- xmms/util.c.orig	2006-11-05 12:29:59.000000000 +0800
+++ xmms/util.c	2006-11-05 12:30:01.000000000 +0800
@@ -175,7 +175,7 @@ GdkImage *create_dblsize_image(GdkImage 
 	 * This needs to be optimized
 	 */
 
-	dblimg = gdk_image_new(GDK_IMAGE_NORMAL, gdk_visual_get_best(), img->width << 1, img->height << 1);
+	dblimg = gdk_image_new(GDK_IMAGE_NORMAL, gdk_visual_get_best_with_depth(img->depth), img->width << 1, img->height << 1);
 	if (dblimg->bpp == 1)
 	{
 		register guint8 *srcptr, *ptr, *ptr2, pix;
