--- src/gnome-cmd-data.c.orig	2007-12-07 01:52:03.000000000 +0100
+++ src/gnome-cmd-data.c	2007-12-07 01:55:02.000000000 +0100
@@ -557,10 +557,10 @@
 			 data->priv->advrename_defaults->height);
 
 	write_int_array ("/gnome-commander/advrename/pat_col_widths%d",
-					 advrename_dialog_default_pat_column_width,
+					 (gint *) &advrename_dialog_default_pat_column_width,
 					 ADVRENAME_DIALOG_PAT_NUM_COLUMNS);
 	write_int_array ("/gnome-commander/advrename/res_col_widths%d",
-					 advrename_dialog_default_res_column_width,
+					 (gint *)&advrename_dialog_default_res_column_width,
 					 ADVRENAME_DIALOG_RES_NUM_COLUMNS);
 	
 	set_int ("/gnome-commander/advrename/sep_value",
@@ -688,10 +688,10 @@
 		"/gnome-commander/advrename/height", 400);
 
 	load_int_array ("/gnome-commander/advrename/pat_col_widths%d",
-					advrename_dialog_default_pat_column_width,
+					(gint *)&advrename_dialog_default_pat_column_width,
 					ADVRENAME_DIALOG_PAT_NUM_COLUMNS);
 	load_int_array ("/gnome-commander/advrename/res_col_widths%d",
-					advrename_dialog_default_res_column_width,
+					(gint *)&advrename_dialog_default_res_column_width,
 					ADVRENAME_DIALOG_RES_NUM_COLUMNS);
 	
 	data->priv->advrename_defaults->sep_value = get_int (
