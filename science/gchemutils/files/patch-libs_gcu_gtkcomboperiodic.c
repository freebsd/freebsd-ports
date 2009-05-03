--- libs/gcu/gtkcomboperiodic.c.orig	2009-05-03 00:43:02.000000000 -0400
+++ libs/gcu/gtkcomboperiodic.c	2009-05-03 00:44:12.000000000 -0400
@@ -112,7 +112,7 @@ gtk_combo_periodic_class_init (GObjectCl
 
 GSF_CLASS (GtkComboPeriodic, gtk_combo_periodic,
 	   gtk_combo_periodic_class_init, gtk_combo_periodic_init,
-	   GO_COMBO_BOX_TYPE)
+	   GO_TYPE_COMBO_BOX)
 
 GtkWidget *gtk_combo_periodic_new (void)
 {
