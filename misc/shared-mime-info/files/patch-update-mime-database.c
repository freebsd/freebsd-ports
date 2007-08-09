--- update-mime-database.c.orig	2007-06-27 15:46:53.000000000 -0400
+++ update-mime-database.c	2007-08-09 15:21:39.000000000 -0400
@@ -445,7 +445,8 @@ static void remove_old(Type *type, xmlNo
 		}
 	}
 
-	xmlFree(lang);
+	if (lang)
+		xmlFree(lang);
 }
 
 /* 'node' is a <mime-type> node from a source file, whose type is 'type'.
@@ -1510,7 +1511,7 @@ static void check_in_path_xdg_data(const
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/"PATH_SEPARATOR"/usr/share/";
+		env = "/usr/local/gnome/share/"PATH_SEPARATOR"/usr/local/share/"PATH_SEPARATOR"/usr/share/";
 	dirs = g_strsplit(env, PATH_SEPARATOR, 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
