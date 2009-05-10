--- programs/table/gchemtable-curve.cc.orig	2009-01-05 14:10:00.000000000 -0500
+++ programs/table/gchemtable-curve.cc	2009-05-10 15:08:23.000000000 -0400
@@ -37,11 +37,9 @@
 #include <goffice/graph/gog-data-set.h>
 #include <goffice/graph/gog-guru.h>
 #include <goffice/graph/gog-label.h>
-#include <goffice/graph/gog-object.h>
+#include <goffice/graph/gog-object-xml.h>
 #include <goffice/graph/gog-plot.h>
 #include <goffice/graph/gog-series.h>
-#include <goffice/graph/gog-style.h>
-#include <goffice/graph/gog-styled-object.h>
 #include <goffice/math/go-math.h>
 #include <goffice/utils/go-locale.h>
 #include <goffice/utils/go-line.h>
@@ -95,7 +93,7 @@ static void on_get_data (GtkClipboard *c
 			go_locale_untranslated_booleans ();
 		
 			xout = gsf_xml_out_new (output);
-			gog_object_write_xml_sax (GOG_OBJECT (graph), xout);
+			gog_object_write_xml_sax (GOG_OBJECT (graph), xout, NULL);
 			g_object_unref (xout);
 		
 			/* go_setlocale restores bools to locale translation */
@@ -332,7 +330,7 @@ GChemTableCurve::GChemTableCurve (GChemT
 		obj = gog_object_get_child_by_role (GOG_OBJECT (chart),
 				gog_object_find_role_by_name (GOG_OBJECT (chart), "Y-Axis"));
 		data = go_data_scalar_str_new (_("Pauling electronegativity"), FALSE);
-		label = (GogObject*) g_object_new (GOG_LABEL_TYPE, NULL);
+		label = (GogObject*) g_object_new (GOG_TYPE_LABEL, NULL);
 		gog_dataset_set_dim (GOG_DATASET (label), 0, data, &error);
 		gog_object_add_by_name (obj, "Label", label);
 		gtk_window_set_title (dialog, _("Pauling electronegativity"));
@@ -348,7 +346,7 @@ GChemTableCurve::GChemTableCurve (GChemT
 		obj = gog_object_get_child_by_role (GOG_OBJECT (chart),
 				gog_object_find_role_by_name (GOG_OBJECT (chart), "Y-Axis"));
 		data = go_data_scalar_str_new (_("Electron affinity (kJ/mol)"), FALSE);
-		label = (GogObject*) g_object_new (GOG_LABEL_TYPE, NULL);
+		label = (GogObject*) g_object_new (GOG_TYPE_LABEL, NULL);
 		gog_dataset_set_dim (GOG_DATASET (label), 0, data, &error);
 		gog_object_add_by_name (obj, "Label", label);
 		gtk_window_set_title (dialog, _("Electron affinity"));
@@ -381,7 +379,7 @@ GChemTableCurve::GChemTableCurve (GChemT
 		obj = gog_object_get_child_by_role (GOG_OBJECT (chart),
 				gog_object_find_role_by_name (GOG_OBJECT (chart), "Y-Axis"));
 		data = go_data_scalar_str_new (buf, TRUE);
-		label = (GogObject*) g_object_new (GOG_LABEL_TYPE, NULL);
+		label = (GogObject*) g_object_new (GOG_TYPE_LABEL, NULL);
 		gog_dataset_set_dim (GOG_DATASET (label), 0, data, &error);
 		gog_object_add_by_name (obj, "Label", label);
 		buf = g_strconcat (rk, _("ionization energy"), NULL);
@@ -404,7 +402,7 @@ GChemTableCurve::GChemTableCurve (GChemT
 		obj = gog_object_get_child_by_role (GOG_OBJECT (chart),
 				gog_object_find_role_by_name (GOG_OBJECT (chart), "Y-Axis"));
 		data = go_data_scalar_str_new (_("Covalent radii"), FALSE);
-		label = (GogObject*) g_object_new (GOG_LABEL_TYPE, NULL);
+		label = (GogObject*) g_object_new (GOG_TYPE_LABEL, NULL);
 		gog_dataset_set_dim (GOG_DATASET (label), 0, data, &error);
 		gog_object_add_by_name (obj, "Label", label);
 		gtk_window_set_title (dialog, _("Covalent radii"));
@@ -424,7 +422,7 @@ GChemTableCurve::GChemTableCurve (GChemT
 		obj = gog_object_get_child_by_role (GOG_OBJECT (chart),
 				gog_object_find_role_by_name (GOG_OBJECT (chart), "Y-Axis"));
 		data = go_data_scalar_str_new (_("Van der Waals radii"), FALSE);
-		label = (GogObject*) g_object_new (GOG_LABEL_TYPE, NULL);
+		label = (GogObject*) g_object_new (GOG_TYPE_LABEL, NULL);
 		gog_dataset_set_dim (GOG_DATASET (label), 0, data, &error);
 		gog_object_add_by_name (obj, "Label", label);
 		gtk_window_set_title (dialog, _("Van der Waals radii"));
@@ -444,7 +442,7 @@ GChemTableCurve::GChemTableCurve (GChemT
 		obj = gog_object_get_child_by_role (GOG_OBJECT (chart),
 				gog_object_find_role_by_name (GOG_OBJECT (chart), "Y-Axis"));
 		data = go_data_scalar_str_new (_("Metallic radii"), FALSE);
-		label = (GogObject*) g_object_new (GOG_LABEL_TYPE, NULL);
+		label = (GogObject*) g_object_new (GOG_TYPE_LABEL, NULL);
 		gog_dataset_set_dim (GOG_DATASET (label), 0, data, &error);
 		gog_object_add_by_name (obj, "Label", label);
 		gtk_window_set_title (dialog, _("Metallic radii"));
@@ -459,7 +457,7 @@ GChemTableCurve::GChemTableCurve (GChemT
 		obj = gog_object_get_child_by_role (GOG_OBJECT (chart),
 				gog_object_find_role_by_name (GOG_OBJECT (chart), "Y-Axis"));
 		data = go_data_scalar_str_new (_("Melting point"), FALSE);
-		label = (GogObject*) g_object_new (GOG_LABEL_TYPE, NULL);
+		label = (GogObject*) g_object_new (GOG_TYPE_LABEL, NULL);
 		gog_dataset_set_dim (GOG_DATASET (label), 0, data, &error);
 		gog_object_add_by_name (obj, "Label", label);
 		gtk_window_set_title (dialog, _("Melting point"));
@@ -474,7 +472,7 @@ GChemTableCurve::GChemTableCurve (GChemT
 		obj = gog_object_get_child_by_role (GOG_OBJECT (chart),
 				gog_object_find_role_by_name (GOG_OBJECT (chart), "Y-Axis"));
 		data = go_data_scalar_str_new (_("Boiling point"), FALSE);
-		label = (GogObject*) g_object_new (GOG_LABEL_TYPE, NULL);
+		label = (GogObject*) g_object_new (GOG_TYPE_LABEL, NULL);
 		gog_dataset_set_dim (GOG_DATASET (label), 0, data, &error);
 		gog_object_add_by_name (obj, "Label", label);
 		gtk_window_set_title (dialog, _("Boiling point"));
@@ -496,7 +494,7 @@ GChemTableCurve::GChemTableCurve (GChemT
 	obj = gog_object_get_child_by_role (GOG_OBJECT (chart),
 			gog_object_find_role_by_name (GOG_OBJECT (chart), "X-Axis"));
 	data = go_data_scalar_str_new ("Z", FALSE);
-	label = (GogObject*) g_object_new (GOG_LABEL_TYPE, NULL);
+	label = (GogObject*) g_object_new (GOG_TYPE_LABEL, NULL);
 	gog_dataset_set_dim (GOG_DATASET (label), 0, data, &error);
 	gog_object_add_by_name (obj, "Label", label);
 }
@@ -571,7 +569,7 @@ graph_user_config_free_data (gpointer da
 static void
 on_update_graph (GogGraph *graph, gpointer data)
 {
-	g_return_if_fail (IS_GOG_GRAPH (graph));
+	g_return_if_fail (GOG_IS_GRAPH (graph));
 	GctControlGUI *tcg = GCT_CONTROL_GUI (data);
 	GChemTableCurve *curve = gct_control_gui_get_owner (tcg);
 	curve->SetGraph (graph);
