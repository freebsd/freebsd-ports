--- capplet/mtm-reflow-view.c.orig	Fri Nov 10 20:59:14 2000
+++ capplet/mtm-reflow-view.c	Thu Apr 19 14:30:24 2001
@@ -191,2 +191,3 @@
 	GnomeCanvasItem *item;
+	gint position = 0;
 
@@ -208,3 +209,3 @@
 
-	e_reflow_add_item (E_REFLOW (view->priv->reflow), item);
+	e_reflow_add_item (E_REFLOW (view->priv->reflow), item, &position);
 	view->priv->previews = g_list_append (view->priv->previews, item);
