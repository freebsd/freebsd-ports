--- gal/e-table/e-table-group.c.orig	Mon Feb 17 14:23:16 2003
+++ gal/e-table/e-table-group.c	Wed Mar 12 22:13:38 2003
@@ -136,7 +136,7 @@
 	g_object_ref (etg->model);
 	g_object_set (G_OBJECT (etg),
 		"parent", parent,
-		NULL);
+		(void*)0);
 }
 
 /**
