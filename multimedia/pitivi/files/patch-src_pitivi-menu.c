--- src/pitivi-menu.c.orig	Mon Dec 20 13:51:12 2004
+++ src/pitivi-menu.c	Mon Dec 20 13:51:40 2004
@@ -215,9 +215,10 @@
 pitivi_menu_configure (PitiviMenu *self)
 {
   GError *error;
+  PitiviMenuPrivate *priv;
   
   error = NULL;
-  PitiviMenuPrivate *priv = self->private;
+  priv = self->private;
   if (priv->merge_id)
     gtk_ui_manager_remove_ui(priv->ui_manager, priv->merge_id);
   pitivi_menubar_configure (priv->ui_manager, priv);
