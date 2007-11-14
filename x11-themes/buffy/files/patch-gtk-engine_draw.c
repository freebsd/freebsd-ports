--- gtk-engine/draw.c.orig	2007-11-12 14:41:47.000000000 +0100
+++ gtk-engine/draw.c	2007-11-12 14:43:43.000000000 +0100
@@ -97,7 +97,7 @@
 };
 
 
-static void
+void
 draw_shadow(GtkStyle * style, GdkWindow * window, GtkStateType state_type, GtkShadowType shadow_type, GdkRectangle * area, GtkWidget * widget, gchar * detail, gint x, gint y, gint width, gint height)
 {
 
@@ -260,7 +260,7 @@
 }
 
 
-static void
+void
 draw_arrow(GtkStyle * style, GdkWindow * window, GtkStateType state_type, GtkShadowType shadow_type, GdkRectangle * area, GtkWidget * widget, gchar * detail, GtkArrowType arrow_type, gint fill, gint x, gint y, gint width, gint height)
 {
 
@@ -351,7 +351,7 @@
 	gdk_draw_polygon(window, shadowGCs[1], TRUE, points, 3);
 }
 
-static void
+void
 draw_diamond(GtkStyle * style, GdkWindow * window, GtkStateType state_type, GtkShadowType shadow_type, GdkRectangle * area, GtkWidget * widget, gchar * detail, gint x, gint y, gint width, gint height)
 {
 	gint            half_width;
@@ -441,7 +441,7 @@
 	}
 }
 
-static void
+void
 draw_string(GtkStyle * style, GdkWindow * window, GtkStateType state_type, GdkRectangle * area, GtkWidget * widget, gchar * detail, gint x, gint y, const gchar * string)
 {
 
@@ -467,7 +467,7 @@
 
 }
 
-static void
+void
 draw_box(GtkStyle * style, GdkWindow * window, GtkStateType state_type, GtkShadowType shadow_type, GdkRectangle * area, GtkWidget * widget, gchar * detail, gint x, gint y, gint width, gint height)
 {
 	g_return_if_fail(style != NULL);
@@ -764,7 +764,7 @@
 
 
 
-static void
+void
 draw_check(GtkStyle * style, GdkWindow * window, GtkStateType state_type, GtkShadowType shadow_type, GdkRectangle * area, GtkWidget * widget, gchar * detail, gint x, gint y, gint width, gint height)
 {
 
@@ -836,7 +836,7 @@
 	}
 }
 
-static void
+void
 draw_shadow_gap(GtkStyle * style, GdkWindow * window, GtkStateType state_type, GtkShadowType shadow_type, GdkRectangle * area, GtkWidget * widget, gchar * detail, gint x, gint y, gint width, gint height, GtkPositionType gap_side, gint gap_x, gint gap_width)
 {
 	GdkRectangle    rect;
@@ -889,7 +889,7 @@
 	gdk_gc_set_clip_rectangle(style->bg_gc[GTK_STATE_NORMAL], NULL);
 }
 
-static void
+void
 draw_box_gap(GtkStyle * style, GdkWindow * window, GtkStateType state_type, GtkShadowType shadow_type, GdkRectangle * area, GtkWidget * widget, gchar * detail, gint x, gint y, gint width, gint height, GtkPositionType gap_side, gint gap_x, gint gap_width)
 {
 	GdkRectangle    rect;
