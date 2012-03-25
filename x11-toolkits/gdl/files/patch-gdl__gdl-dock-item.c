--- ./gdl/gdl-dock-item.c.orig	2012-03-19 01:15:14.000000000 +1030
+++ ./gdl/gdl-dock-item.c	2012-03-19 01:15:55.000000000 +1030
@@ -1816,7 +1816,7 @@
 GtkWidget *
 gdl_dock_item_get_grip(GdlDockItem *item)
 {
-    g_return_if_fail (item != NULL);
+    g_return_val_if_fail (item != NULL, NULL);
     g_return_val_if_fail (GDL_IS_DOCK_ITEM (item), NULL);
 
     return item->_priv->grip;
