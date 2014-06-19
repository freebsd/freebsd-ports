--- spectool_gtk_spectral.c.orig	2014-06-10 21:19:12.000000000 +0200
+++ spectool_gtk_spectral.c	2014-06-10 21:19:47.000000000 +0200
@@ -415,9 +415,9 @@ static gboolean spectool_spectral_legend
 	cairo_pattern_t *pattern;
 	int cp;
 
-	g_return_if_fail(widget != NULL);
-	g_return_if_fail(aux != NULL);
-	g_return_if_fail(IS_SPECTOOL_SPECTRAL(aux));
+	g_return_val_if_fail(widget != NULL, FALSE);
+	g_return_val_if_fail(aux != NULL, FALSE);
+	g_return_val_if_fail(IS_SPECTOOL_SPECTRAL(aux), FALSE);
 
 	spectral = SPECTOOL_SPECTRAL(aux);
 
