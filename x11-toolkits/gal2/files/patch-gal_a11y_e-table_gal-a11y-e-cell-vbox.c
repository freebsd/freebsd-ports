--- gal/a11y/e-table/gal-a11y-e-cell-vbox.c.orig	Wed Feb  9 23:03:24 2005
+++ gal/a11y/e-table/gal-a11y-e-cell-vbox.c	Wed Feb  9 23:04:46 2005
@@ -31,8 +31,9 @@
 static gint
 ecv_get_n_children (AtkObject *a11y)
 {
+	GalA11yECellVbox *gaev;
 	g_return_val_if_fail (GAL_A11Y_IS_E_CELL_VBOX (a11y), 0);
-	GalA11yECellVbox *gaev = GAL_A11Y_E_CELL_VBOX (a11y);
+	gaev = GAL_A11Y_E_CELL_VBOX (a11y);
 	return (gaev->a11y_subcell_count);
 }
 
@@ -64,9 +65,10 @@
 	if (i < gaev->a11y_subcell_count) {
 		if (gaev->a11y_subcells[i] == NULL) {
 			gint model_col, row;
+			ECellView *subcell_view;
 			row = gaec->row;
 			model_col = ecvv->model_cols[i];
-			ECellView *subcell_view = ecvv->subcell_views[i];
+			subcell_view = ecvv->subcell_views[i];
 			ret = gal_a11y_e_cell_registry_get_object (NULL,
 				gaec->item,
 				subcell_view,
@@ -200,14 +202,17 @@
 					 int         row)
 {
 	AtkObject *a11y;
+	GalA11yECell *gaec;
+	GalA11yECellVbox *gaev;
+	ECellVboxView *ecvv;
 
 	a11y = g_object_new (gal_a11y_e_cell_vbox_get_type (), NULL);
 	
 	gal_a11y_e_cell_construct (a11y, item, cell_view, parent, model_col, view_col, row);
 
-	GalA11yECell *gaec = GAL_A11Y_E_CELL (a11y);
-	GalA11yECellVbox *gaev = GAL_A11Y_E_CELL_VBOX (a11y);
-	ECellVboxView *ecvv = (ECellVboxView *) (gaec->cell_view);
+	gaec = GAL_A11Y_E_CELL (a11y);
+	gaev = GAL_A11Y_E_CELL_VBOX (a11y);
+	ecvv = (ECellVboxView *) (gaec->cell_view);
 	gaev->a11y_subcell_count = ecvv->subcell_view_count; 
 	gaev->a11y_subcells = g_malloc0 (sizeof(AtkObject *)*gaev->a11y_subcell_count);
 	return a11y;
