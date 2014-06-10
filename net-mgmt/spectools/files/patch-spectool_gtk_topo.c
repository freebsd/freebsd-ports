--- spectool_gtk_topo.c.orig	2014-06-10 21:20:53.000000000 +0200
+++ spectool_gtk_topo.c	2014-06-10 21:21:27.000000000 +0200
@@ -379,9 +379,9 @@ static gboolean spectool_topo_legend_exp
 	cairo_pattern_t *pattern;
 	int cp;
 
-	g_return_if_fail(widget != NULL);
-	g_return_if_fail(aux != NULL);
-	g_return_if_fail(IS_SPECTOOL_TOPO(aux));
+	g_return_val_if_fail(widget != NULL, FALSE);
+	g_return_val_if_fail(aux != NULL, FALSE);
+	g_return_val_if_fail(IS_SPECTOOL_TOPO(aux), FALSE);
 
 	topo = SPECTOOL_TOPO(aux);
 
