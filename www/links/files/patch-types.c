--- types.c.orig	2012-06-06 15:49:37.000000000 -0400
+++ types.c	2012-06-27 02:28:56.000000000 -0400
@@ -841,7 +841,8 @@
 			ext = NULL;
 		}
 	if (ext) while (ext[extl] && ext[extl] != '.' && !dir_sep(ext[extl]) && !end_of_dir(url, ext[extl])) extl++;
-	if ((extl == 3 && !casecmp(ext, cast_uchar "htm", 3)) ||
+	if (force_html || 
+	    (extl == 3 && !casecmp(ext, cast_uchar "htm", 3)) ||
 	    (extl == 4 && !casecmp(ext, cast_uchar "html", 4))) return stracpy(cast_uchar "text/html");
 	foreach(e, extensions) {
 		unsigned char *fname = NULL;
