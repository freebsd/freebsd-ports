--- src/kz-window.c.orig	Wed Dec 22 02:51:51 2004
+++ src/kz-window.c	Tue Dec 28 22:33:41 2004
@@ -1373,6 +1373,11 @@
 {
 	KzWindow *kz;
 
+	gboolean shortcircuit;
+        gboolean force_chain;
+        gboolean handled;
+	guint modifier;
+
 	g_return_val_if_fail(KZ_IS_WINDOW(widget), FALSE);
 
 	kz = KZ_WINDOW(widget);
@@ -1386,10 +1391,10 @@
 	 * rules, we might be doing them a favour.
 	 */
 
-	gboolean shortcircuit = FALSE;
-	gboolean force_chain  = FALSE;
-	gboolean handled = FALSE;
-	guint modifier = event->state & gtk_accelerator_get_default_mod_mask ();
+	shortcircuit = FALSE;
+	force_chain  = FALSE;
+	handled = FALSE;
+	modifier = event->state & gtk_accelerator_get_default_mod_mask ();
 	/* guint i; */
 
 	if (event->keyval == GDK_Escape)
