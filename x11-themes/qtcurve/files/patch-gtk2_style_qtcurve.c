--- gtk2/style/qtcurve.c.orig	2014-01-25 20:13:54 UTC
+++ gtk2/style/qtcurve.c
@@ -372,7 +372,7 @@ gtkDrawFlatBox(GtkStyle *style, GdkWindo
     } else if (!(qtSettings.app == GTK_APP_JAVA && widget &&
                  GTK_IS_LABEL(widget))) {
         if (state != GTK_STATE_PRELIGHT || opts.crHighlight ||
-            strcmp(detail, "checkbutton") != 0) {
+            ( detail != NULL && strcmp(detail, "checkbutton") != 0 )) {
             parent_class->draw_flat_box(style, window, state, shadow, area,
                                         widget, detail, x, y, width, height);
         }
