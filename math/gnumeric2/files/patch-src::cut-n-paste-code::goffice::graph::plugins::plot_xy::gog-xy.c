--- src/cut-n-paste-code/goffice/graph/plugins/plot_xy/gog-xy.c.orig    Mon Jan 19 01:04:42 2004
+++ src/cut-n-paste-code/goffice/graph/plugins/plot_xy/gog-xy.c Mon Jan 19 01:06:36 2004
@@ -359,9 +359,9 @@
 {
	GogObjectClass *gog_klass = (GogObjectClass *) plot_klass;

-	bubble_parent_klass = g_type_class_peek_parent (plot_klass);
-
	Gog2DPlotClass *gog_2d_plot_klass = (Gog2DPlotClass*) plot_klass;
+
+	bubble_parent_klass = g_type_class_peek_parent (plot_klass);

	gog_2d_plot_klass->adjust_bounds = gog_bubble_plot_adjust_bounds;
	gog_klass->type_name    = gog_bubble_plot_type_name;
