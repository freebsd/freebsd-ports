--- libs/gcu/spectrumview.cc.orig	2009-01-05 14:09:59.000000000 -0500
+++ libs/gcu/spectrumview.cc	2009-05-05 00:56:31.000000000 -0400
@@ -30,9 +30,10 @@
 #include <goffice/graph/gog-object.h>
 #include <goffice/graph/gog-plot.h>
 #include <goffice/graph/gog-series.h>
-#include <goffice/graph/gog-style.h>
 #include <goffice/gtk/go-graph-widget.h>
 #include <goffice/utils/go-image.h>
+#include <goffice/utils/go-style.h>
+#include <goffice/utils/go-styled-object.h>
 #include <gsf/gsf-output-gio.h>
 #include <glib/gi18n-lib.h>
 #include <cmath>
@@ -65,7 +66,7 @@ SpectrumView::SpectrumView (SpectrumDocu
 	m_Widget = go_graph_widget_new (NULL);
 	GogGraph *graph = go_graph_widget_get_graph (GO_GRAPH_WIDGET (m_Widget));
 	/* Add a title */
-	GogLabel *label = (GogLabel *) g_object_new (GOG_LABEL_TYPE, NULL);
+	GogLabel *label = (GogLabel *) g_object_new (GOG_TYPE_LABEL, NULL);
 	gog_object_add_by_name (GOG_OBJECT (graph), "Title", GOG_OBJECT (label));
 	/* Get the chart created by the widget initialization */
 	GogChart *chart = go_graph_widget_get_chart (GO_GRAPH_WIDGET (m_Widget));
@@ -144,7 +145,7 @@ void SpectrumView::SetAxisLabel (GogAxis
 		gog_object_clear_parent (label);
 		g_object_unref (label);
 	}
-	label = GOG_OBJECT (g_object_new (GOG_LABEL_TYPE, NULL));
+	label = GOG_OBJECT (g_object_new (GOG_TYPE_LABEL, NULL));
 	gog_dataset_set_dim (GOG_DATASET (label), 0, data, NULL);
 	gog_object_add_by_name (axis, "Label", label);
 	
@@ -156,7 +157,7 @@ void SpectrumView::ShowAxis (GogAxisType
 	GSList *axes = gog_chart_get_axes (chart, target);
 	GogObject *axis = GOG_OBJECT (axes->data);
 	g_object_set (G_OBJECT (axis), "major-tick-labeled", false, NULL);
-	GogStyle *style = gog_styled_object_get_style (GOG_STYLED_OBJECT (axis));
+	GOStyle *style = go_styled_object_get_style (GO_STYLED_OBJECT (axis));
 	style->line.dash_type = GO_LINE_NONE;
 	style->line.auto_dash = false;
 }
