--- types.c.orig	Sat Mar  1 19:06:39 2003
+++ types.c	Sat Mar  1 19:07:45 2003
@@ -705,7 +705,8 @@
 		if (*ct == '.') ext = ct + 1;
 		else if (dir_sep(*ct)) ext = NULL;
 	if (ext) while (ext[extl] && !dir_sep(ext[extl]) && !end_of_dir(ext[extl])) extl++;
-	if ((extl == 3 && !casecmp(ext, "htm", 3)) ||
+	if (force_html ||
+	    (extl == 3 && !casecmp(ext, "htm", 3)) ||
 	    (extl == 4 && !casecmp(ext, "html", 4))) return stracpy("text/html");
 	foreach(e, extensions) if (is_in_list(e->ext, ext, extl)) return stracpy(e->ct);
 
