--- bacon-cd-selection.c.orig	Thu Nov  4 00:25:43 2004
+++ bacon-cd-selection.c	Thu Nov  4 00:25:57 2004
@@ -177,10 +177,10 @@
 static void
 bacon_cd_selection_init (BaconCdSelection *bcs)
 {
-	bcs->priv = g_new0 (BaconCdSelectionPrivate, 1);
-  
 	GtkCellRenderer *cell;
 	GtkListStore *store;
+	bcs->priv = g_new0 (BaconCdSelectionPrivate, 1);
+  
 
   store = gtk_list_store_new (1, G_TYPE_STRING);
 	gtk_combo_box_set_model (GTK_COMBO_BOX (bcs),
