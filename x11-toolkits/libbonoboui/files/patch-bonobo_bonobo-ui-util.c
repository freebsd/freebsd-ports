--- bonobo/bonobo-ui-util.c.orig	Fri Feb 28 10:40:12 2003
+++ bonobo/bonobo-ui-util.c	Wed Apr 16 10:13:23 2003
@@ -558,14 +558,11 @@
 		else
 			prefix = NULL;
 
-		if (prefix)
+		datadir = NULL;
+		g_object_get (G_OBJECT (gnome_program_get ()),
+			GNOME_PARAM_APP_DATADIR, &datadir, NULL);
+		if (!datadir && prefix) 
 			datadir = g_strdup_printf ("%s/share", prefix);
-
- 		else {
-			datadir = NULL;
-			g_object_get (G_OBJECT (gnome_program_get ()),
-				      GNOME_PARAM_APP_DATADIR, &datadir, NULL);
-		}
 
 		if (!datadir) /* desparate fallback */
 			datadir = g_strdup (BONOBO_DATADIR);
