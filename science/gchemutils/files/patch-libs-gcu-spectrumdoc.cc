--- libs/gcu/spectrumdoc.cc.orig	2009-01-05 14:09:59.000000000 -0500
+++ libs/gcu/spectrumdoc.cc	2009-05-09 15:06:20.000000000 -0400
@@ -28,12 +28,13 @@
 #include <goffice/graph/gog-axis.h>
 #include <goffice/graph/gog-plot.h>
 #include <goffice/graph/gog-series-lines.h>
-#include <goffice/graph/gog-style.h>
 #include <goffice/math/go-fft.h>
 #include <goffice/math/go-math.h>
 #include <goffice/math/go-rangefunc.h>
 #include <goffice/math/go-regression.h>
 #include <goffice/utils/go-color.h>
+#include <goffice/utils/go-style.h>
+#include <goffice/utils/go-styled-object.h>
 #include <gio/gio.h>
 #include <glib/gi18n-lib.h>
 #include <cstring>
@@ -668,8 +669,8 @@ parse_line:
 		case JCAMP_PEAK_TABLE: {
 			// in that case, add drop lines ans remove the normal line
 			GogSeries *series = m_View->GetSeries ();
-			gog_object_add_by_name (GOG_OBJECT (series), "Vertical drop lines", GOG_OBJECT (g_object_new (GOG_SERIES_LINES_TYPE, NULL)));
-			GogStyle *style = gog_styled_object_get_style (GOG_STYLED_OBJECT (series));
+			gog_object_add_by_name (GOG_OBJECT (series), "Vertical drop lines", GOG_OBJECT (g_object_new (GOG_TYPE_SERIES_LINES, NULL)));
+			GOStyle *style = go_styled_object_get_style (GO_STYLED_OBJECT (series));
 			style->line.dash_type = GO_LINE_NONE;
 			style->line.auto_dash = false;
 		}
@@ -1898,7 +1899,7 @@ static double logm (double val, double f
 
 static double expm (double val, double f, double offset)
 {
-	return exp10 (-val) * f + offset;
+	return pow (10, -val) * f + offset;
 }
 
 double (*SpectrumDocument::GetConversionFunction (SpectrumUnitType oldu, SpectrumUnitType newu, double &factor, double &shift)) (double, double, double)
@@ -1966,7 +1967,7 @@ double (*SpectrumDocument::GetConversion
 void SpectrumDocument::OnShowIntegral ()
 {
 	m_IntegralVisible = !m_IntegralVisible;
-	GogStyle *style;
+	GOStyle *style;
 	if (m_IntegralVisible) {
 		if (integral < 0) {
 			integral = variables.size ();
@@ -2036,15 +2037,15 @@ void SpectrumDocument::OnShowIntegral ()
 			gog_series_set_dim (v.Series, 0, godata, NULL);
 			godata = go_data_vector_val_new (v.Values, v.NbValues, NULL);
 			gog_series_set_dim (v.Series, 1, godata, NULL);
-			GogStyledObject *axis = GOG_STYLED_OBJECT (g_object_new (GOG_AXIS_TYPE, "major-tick-labeled", false, NULL));
+			GOStyledObject *axis = GO_STYLED_OBJECT (g_object_new (GOG_TYPE_AXIS, "major-tick-labeled", false, NULL));
 			GogPlot	*plot = gog_series_get_plot (v.Series);
 			GogObject *chart = GOG_OBJECT (gog_object_get_parent (GOG_OBJECT (plot)));
 			gog_object_add_by_name (chart, "Y-Axis", GOG_OBJECT (axis));
 			gog_plot_set_axis (plot, GOG_AXIS (axis));
-			style = gog_styled_object_get_style (axis);
+			style = go_styled_object_get_style (axis);
 			style->line.auto_dash = false;
 			style->line.dash_type = GO_LINE_NONE;
-			style = gog_styled_object_get_style (GOG_STYLED_OBJECT (v.Series));
+			style = go_styled_object_get_style (GO_STYLED_OBJECT (v.Series));
 			style->line.auto_dash = false;
 			style->line.auto_color = false;
 			style->line.color = RGBA_RED;
@@ -2056,13 +2057,13 @@ void SpectrumDocument::OnShowIntegral ()
 			delete [] xn[4];
 			delete [] yb;
 		} else
-			style = gog_styled_object_get_style (GOG_STYLED_OBJECT (variables[integral].Series));
+			style = go_styled_object_get_style (GO_STYLED_OBJECT (variables[integral].Series));
 		// show the series
 		style->line.dash_type = GO_LINE_SOLID;
 		gog_object_request_update (GOG_OBJECT (variables[integral].Series));
 	} else {
 		// hide the series
-		style = gog_styled_object_get_style (GOG_STYLED_OBJECT (variables[integral].Series));
+		style = go_styled_object_get_style (GO_STYLED_OBJECT (variables[integral].Series));
 		style->line.dash_type = GO_LINE_NONE;
 		gog_object_request_update (GOG_OBJECT (variables[integral].Series));
 	}
