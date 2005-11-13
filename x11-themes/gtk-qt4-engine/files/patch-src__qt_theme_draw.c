--- src/qt_theme_draw.c.orig    Thu Nov 10 16:23:45 2005
+++ src/qt_theme_draw.c Thu Nov 10 16:24:55 2005
@@ -1777,6 +1777,7 @@
         {
           pixmap = pix_test;
           parent_relative = FALSE;
+          gdk_drawable_set_colormap(pixmap, style->colormap);
         }

       gdk_window_set_back_pixmap (window, pixmap, parent_relative);
