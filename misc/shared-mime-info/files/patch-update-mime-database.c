--- update-mime-database.c.orig	Mon Oct 13 05:43:38 2003
+++ update-mime-database.c	Wed Jun 23 20:13:10 2004
@@ -377,7 +377,8 @@
 		}
 	}
 
-	xmlFree(lang);
+	if (lang)
+	  xmlFree(lang);
 }
 
 /* 'node' is a <mime-type> node from a source file, whose type is 'type'.
@@ -1330,7 +1331,7 @@
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/:/usr/share/";
+		env = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 	dirs = g_strsplit(env, ":", 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
