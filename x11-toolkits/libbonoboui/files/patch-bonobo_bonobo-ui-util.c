--- bonobo/bonobo-ui-util.c.orig	Mon Sep  2 11:24:00 2002
+++ bonobo/bonobo-ui-util.c	Sat Nov 16 16:38:54 2002
@@ -539,11 +539,10 @@
 					      GNOME_PARAM_GNOME_PREFIX, &prefix, NULL);
 		}
 
-		/* sub-optimal, but what can you do */
-		if (prefix)
-			datadir = g_strdup_printf ("%s/share", prefix);
-		else
-			datadir = g_strdup (BONOBO_DATADIR);
+		g_object_get (G_OBJECT (gnome_program_get ()),
+		              GNOME_PARAM_APP_DATADIR, &datadir, NULL);
+		if (!datadir)
+		    datadir = g_strdup (BONOBO_DATADIR);
 
 		cl->program = gnome_program_init (
 			doc_id, "2.1",
