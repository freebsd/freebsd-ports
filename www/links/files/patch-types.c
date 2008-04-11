--- types.c.orig	2008-03-19 18:18:18.614955994 -0400
+++ types.c	2008-03-19 18:21:18.345245179 -0400
@@ -820,7 +820,8 @@
 			ext = NULL;
 		}
 	if (ext) while (ext[extl] && ext[extl] != '.' && !dir_sep(ext[extl]) && !end_of_dir(url, ext[extl])) extl++;
-	if ((extl == 3 && !casecmp(ext, "htm", 3)) ||
+	if (force_html || 
+	    (extl == 3 && !casecmp(ext, "htm", 3)) ||
 	    (extl == 4 && !casecmp(ext, "html", 4))) return stracpy("text/html");
 	foreach(e, extensions) {
 		unsigned char *fname = NULL;
