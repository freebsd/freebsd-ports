--- types.c.orig	Thu Jul  5 13:10:37 2007
+++ types.c	Thu Jul  5 13:12:07 2007
@@ -807,7 +807,8 @@
 			ext = NULL;
 		}
 	if (ext) while (ext[extl] && ext[extl] != '.' && !dir_sep(ext[extl]) && !end_of_dir(url, ext[extl])) extl++;
-	if ((extl == 3 && !casecmp(ext, "htm", 3)) ||
+	if (force_html ||
+	    (extl == 3 && !casecmp(ext, "htm", 3)) ||
 	    (extl == 4 && !casecmp(ext, "html", 4))) return stracpy("text/html");
 	foreach(e, extensions) {
 		unsigned char *fname = NULL;
