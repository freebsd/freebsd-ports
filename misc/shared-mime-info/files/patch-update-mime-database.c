--- update-mime-database.c.orig	2007-07-02 04:00:13.000000000 -0500
+++ update-mime-database.c	2008-01-28 23:42:30.000000000 -0600
@@ -54,6 +54,7 @@
 	"model",
 	"multipart",
 	"x-epoc",
+	"x-content",
 };
 
 /* Represents a MIME type */
@@ -445,7 +446,8 @@
 		}
 	}
 
-	xmlFree(lang);
+	if (lang)
+		xmlFree(lang);
 }
 
 /* 'node' is a <mime-type> node from a source file, whose type is 'type'.
@@ -1510,7 +1512,7 @@
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/"PATH_SEPARATOR"/usr/share/";
+		env = "/usr/local/share/";
 	dirs = g_strsplit(env, PATH_SEPARATOR, 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
