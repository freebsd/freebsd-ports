--- src/ephy-nautilus-view.c.orig	Sun Aug  1 20:12:36 2004
+++ src/ephy-nautilus-view.c	Sun Aug  1 20:13:49 2004
@@ -546,7 +546,7 @@
 	EphyDialog *dialog;
 	EphyNautilusViewPrivate *p = view->priv;
 	
-	dialog = ephy_print_dialog_new (NULL, p->embed, FALSE);
+	dialog = ephy_print_dialog_new (NULL, p->embed);
 
 	ephy_dialog_set_modal (dialog, TRUE);
 	ephy_dialog_run (dialog);
