--- gail-gnome/panel-applet-atk-object.c.orig	Sat Jul 24 11:09:32 2004
+++ gail-gnome/panel-applet-atk-object.c	Sat Jul 24 11:10:42 2004
@@ -112,7 +112,9 @@
 
   applet_atk_object_priv = panel_applet_atk_object_private_create (applet);
   g_object_set_data (G_OBJECT (retval), applet_atk_priv, applet_atk_object_priv);
+#ifdef ATK_ROLE_EMBEDDED
   atk_object_set_role (ATK_OBJECT (retval), ATK_ROLE_EMBEDDED);
+#endif
 
   return ATK_OBJECT (retval);
 }
