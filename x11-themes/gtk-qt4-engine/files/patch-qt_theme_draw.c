--- src/qt_theme_draw.c.orig	Sun Nov  7 13:41:29 2004
+++ src/qt_theme_draw.c	Sun Nov  7 13:55:19 2004
@@ -625,17 +625,18 @@
 	if (DETAIL("tooltip"))
 	{
 		GdkColor tooltipColor;
+		GdkGC* tooltipGc;
+                GdkGCValues gc_values;
+                GdkGCValuesMask gc_values_mask;
 		tooltipColor.red = 255*257;
 		tooltipColor.green = 255*257;
 		tooltipColor.blue = 220*257;
 		gdk_colormap_alloc_color(style->colormap, &tooltipColor, FALSE, TRUE);
 		
-		GdkGCValues gc_values;
-		GdkGCValuesMask gc_values_mask;
 		gc_values_mask = GDK_GC_FOREGROUND;
 		gc_values.foreground = tooltipColor;
 		
-		GdkGC* tooltipGc = (GdkGC*) gtk_gc_get (style->depth, style->colormap, &gc_values, gc_values_mask);
+		tooltipGc = (GdkGC*) gtk_gc_get (style->depth, style->colormap, &gc_values, gc_values_mask);
 		gdk_draw_rectangle(window, tooltipGc, TRUE, x, y, width, height);
 		gdk_draw_rectangle(window, style->black_gc, FALSE, x, y, width - 1, height - 1);
 		
