--- types.c.orig	Fri Apr 26 09:11:15 2002
+++ types.c	Fri Apr 26 09:12:27 2002
@@ -66,5 +66,6 @@
 		else if (dir_sep(*ct)) ext = NULL;
 	if (ext) while (ext[extl] && !dir_sep(ext[extl]) && !end_of_dir(ext[extl])) extl++;
-	if ((extl == 3 && !casecmp(ext, "htm", 3)) ||
+	if (force_html ||
+	    (extl == 3 && !casecmp(ext, "htm", 3)) ||
 	    (extl == 4 && !casecmp(ext, "html", 4))) return stracpy("text/html");
 	foreach(e, extensions) if (is_in_list(e->ext, ext, extl)) return stracpy(e->ct);
