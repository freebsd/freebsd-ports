--- types.c.orig	Thu Mar 24 10:36:47 2005
+++ types.c	Thu Mar 24 10:38:12 2005
@@ -796,7 +796,8 @@
 		if (*ct == '.') ext = ct + 1;
 		else if (dir_sep(*ct)) ext = NULL;
 	if (ext) while (ext[extl] && !dir_sep(ext[extl]) && !end_of_dir(url, ext[extl])) extl++;
-	if ((extl == 3 && !casecmp(ext, "htm", 3)) ||
+	if (force_html ||
+	    (extl == 3 && !casecmp(ext, "htm", 3)) ||
 	    (extl == 4 && !casecmp(ext, "html", 4))) return stracpy("text/html");
 	foreach(e, extensions) {
 		unsigned char *fname = NULL;
