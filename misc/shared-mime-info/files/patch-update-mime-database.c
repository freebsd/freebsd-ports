--- update-mime-database.c.orig	Fri Dec  3 15:46:28 2004
+++ update-mime-database.c	Fri Mar 25 14:51:30 2005
@@ -408,7 +408,8 @@
 		}
 	}
 
-	xmlFree(lang);
+	if (lang)
+		xmlFree(lang);
 }
 
 /* 'node' is a <mime-type> node from a source file, whose type is 'type'.
@@ -1458,7 +1459,7 @@
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/:/usr/share/";
+		env = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 	dirs = g_strsplit(env, ":", 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
