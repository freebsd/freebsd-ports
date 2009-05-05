--- programs/table/gchemtable-data-allocator.cc.orig	2009-05-05 01:12:11.000000000 -0400
+++ programs/table/gchemtable-data-allocator.cc	2009-05-05 01:12:44.000000000 -0400
@@ -106,7 +106,7 @@ gct_data_allocator_editor (GogDataAlloca
 	editor->dim_i		= dim_i;
 	editor->data_type	= data_type;
 					
-	if (IS_GOG_SERIES (dataset) && data_type != GOG_DATA_SCALAR) {
+	if (GOG_IS_SERIES (dataset) && data_type != GOG_DATA_SCALAR) {
 		GogPlot *plot = gog_series_get_plot (GOG_SERIES (dataset));
 		if (plot->desc.series.dim[dim_i].priority == GOG_SERIES_ERRORS) {
 			// FIXME: we might know the errors
@@ -189,7 +189,7 @@ gct_control_gui_class_init (GObjectClass
 GSF_CLASS_FULL (GctControlGUI, gct_control_gui,
 		NULL, NULL, gct_control_gui_class_init, NULL,
 		gct_control_gui_init, G_TYPE_OBJECT, 0,
-		GSF_INTERFACE (gct_go_plot_data_allocator_init, GOG_DATA_ALLOCATOR_TYPE));
+		GSF_INTERFACE (gct_go_plot_data_allocator_init, GOG_TYPE_DATA_ALLOCATOR));
 
 void
 gct_control_gui_set_owner (GctControlGUI *gui, GChemTableCurve *curve)
