--- programs/calc/gchemcalc.cc.orig	2009-01-05 14:09:59.000000000 -0500
+++ programs/calc/gchemcalc.cc	2009-05-05 01:04:35.000000000 -0400
@@ -56,11 +56,11 @@
 #include <goffice/gtk/goffice-gtk.h>
 #include <goffice/graph/gog-axis.h>
 #include <goffice/graph/gog-data-set.h>
-#include <goffice/graph/gog-object.h>
+#include <goffice/graph/gog-object-xml.h>
 #include <goffice/graph/gog-plot.h>
 #include <goffice/graph/gog-series.h>
-#include <goffice/graph/gog-style.h>
-#include <goffice/graph/gog-styled-object.h>
+#include <goffice/utils/go-style.h>
+#include <goffice/utils/go-styled-object.h>
 #include <goffice/utils/go-locale.h>
 #include <goffice/utils/go-image.h>
 #include <goffice/utils/go-line.h>
@@ -736,7 +736,7 @@
 	App = new GChemCalc ();
 	
 	/* Initialize plugins manager */
-	go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_PLUGIN_LOADER_MODULE_TYPE);
+	go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_TYPE_PLUGIN_LOADER_MODULE);
 
 	GladeXML *xml =  glade_xml_new (GLADEDIR"/gchemcalc.glade", "gchemcalc", NULL);
 	App->window = GTK_WINDOW (glade_xml_get_widget (xml, "gchemcalc"));
@@ -808,7 +808,7 @@
 	// Create a series for the plot and populate it with some simple data
 	App->series = gog_plot_new_series (App->plot);
 	gog_object_add_by_name (GOG_OBJECT (App->series), "Vertical drop lines", NULL);
-	GogStyle *style = gog_styled_object_get_style (GOG_STYLED_OBJECT (App->series));
+	GOStyle *style = go_styled_object_get_style (GO_STYLED_OBJECT (App->series));
 	go_marker_set_shape (style->marker.mark, GO_MARKER_NONE);
 	style->marker.auto_shape = false;
 	style->line.dash_type = GO_LINE_NONE;
