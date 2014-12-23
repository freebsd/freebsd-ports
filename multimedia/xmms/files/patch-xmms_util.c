--- xmms/util.c.orig	2006-07-16 13:40:04 UTC
+++ xmms/util.c
@@ -175,7 +175,7 @@ GdkImage *create_dblsize_image(GdkImage 
 	 * This needs to be optimized
 	 */
 
-	dblimg = gdk_image_new(GDK_IMAGE_NORMAL, gdk_visual_get_best(), img->width << 1, img->height << 1);
+	dblimg = gdk_image_new(GDK_IMAGE_NORMAL, gdk_visual_get_best_with_depth(img->depth), img->width << 1, img->height << 1);
 	if (dblimg->bpp == 1)
 	{
 		char *srcptr, *ptr, *ptr2;
