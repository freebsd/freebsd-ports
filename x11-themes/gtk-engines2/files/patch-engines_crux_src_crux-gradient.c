--- engines/crux/src/crux-gradient.c.orig	Thu Oct 16 20:57:05 2003
+++ engines/crux/src/crux-gradient.c	Thu Oct 16 21:01:18 2003
@@ -207,7 +207,7 @@
 			const eazel_engine_gradient *gradient)
 {
     int rgb_size = clip_rect->height;
-    guchar *rgb = alloca (rgb_size * 3), *ptr;
+    guchar *rgb = g_malloc (rgb_size * 3), *ptr;
 
     eazel_engine_fill_gradient_rgb_buffer (gradient, full_rect->height, rgb,
 					   clip_rect->y - full_rect->y,
@@ -239,7 +239,7 @@
     }
     else
     {
-	guchar *xrgb = alloca (clip_rect->width * clip_rect->height * 3);
+	guchar *xrgb = g_malloc (clip_rect->width * clip_rect->height * 3);
 	int x, y;
 	guchar *ptr_in = rgb, *ptr_out = xrgb;
 	for (y = 0; y < clip_rect->height; y++)
@@ -257,7 +257,10 @@
 	gdk_draw_rgb_image (drawable, gc, clip_rect->x, clip_rect->y,
 			    clip_rect->width, clip_rect->height,
 			    dither_mode, xrgb, clip_rect->width * 3);
+	g_free (xrgb);
     }
+
+    g_free (rgb);
 }
 
 static void
