--- src/kz-tab-label.c.orig	Wed Aug 31 19:55:05 2005
+++ src/kz-tab-label.c	Wed Aug 31 19:55:29 2005
@@ -353,9 +353,10 @@
 kz_tab_label_dispose (GObject *object)
 {
 	KzTabLabel *kztab;
+	KzTabLabelPrivate *priv;
 
 	kztab = KZ_TAB_LABEL(object);
-	KzTabLabelPrivate *priv = KZ_TAB_LABEL_GET_PRIVATE (kztab);
+	priv = KZ_TAB_LABEL_GET_PRIVATE (kztab);
 
 	g_signal_handlers_disconnect_by_func(kz_global_profile,
 					     G_CALLBACK(cb_profile_changed),
