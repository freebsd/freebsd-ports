--- tools/browser/oaf-helper.c.orig	Sun Feb  6 03:04:39 2005
+++ tools/browser/oaf-helper.c	Sun Feb  6 03:06:17 2005
@@ -58,10 +58,12 @@
 	gchar **search;
 
 	lang = getenv ("LANG");
+	if (!lang)
+		return g_strdup ("");
 
 	search = g_strsplit (lang, "_", 1);
 	if (!search)
-		return "";
+		return g_strdup ("");
 
 	ret = g_strdup_printf ("%s", search[0]);
 
