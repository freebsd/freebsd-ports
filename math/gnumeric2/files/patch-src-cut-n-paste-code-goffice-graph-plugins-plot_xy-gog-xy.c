--- src/cut-n-paste-code/goffice/graph/plugins/plot_xy/gog-xy.c.orig	Sat Mar 13 04:27:56 2004
+++ src/cut-n-paste-code/goffice/graph/plugins/plot_xy/gog-xy.c	Wed Mar 17 00:56:18 2004
@@ -430,12 +430,13 @@
 {
 	GObjectClass *gobject_klass = (GObjectClass *) plot_klass;
 	GogObjectClass *gog_klass = (GogObjectClass *) plot_klass;
+	Gog2DPlotClass *gog_2d_plot_klass;
 
 	bubble_parent_klass = g_type_class_peek_parent (plot_klass);
 	gobject_klass->set_property = gog_bubble_plot_set_property;
 	gobject_klass->get_property = gog_bubble_plot_get_property;
 
-	Gog2DPlotClass *gog_2d_plot_klass = (Gog2DPlotClass*) plot_klass;
+	gog_2d_plot_klass = (Gog2DPlotClass*) plot_klass;
 
 	gog_2d_plot_klass->adjust_bounds = gog_bubble_plot_adjust_bounds;
 	gog_klass->type_name	= gog_bubble_plot_type_name;
