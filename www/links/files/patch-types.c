--- types.c.orig	2016-06-17 20:33:57 UTC
+++ types.c
@@ -849,7 +849,8 @@ unsigned char *get_content_type_by_exten
 			ext = NULL;
 		}
 	if (ext) while (ext[extl] && ext[extl] != '.' && !dir_sep(ext[extl]) && !end_of_dir(url, ext[extl])) extl++;
-	if ((extl == 3 && !casecmp(ext, cast_uchar "htm", 3)) ||
+	if (force_html || 
+	    (extl == 3 && !casecmp(ext, cast_uchar "htm", 3)) ||
 	    (extl == 4 && !casecmp(ext, cast_uchar "html", 4))) return stracpy(cast_uchar "text/html");
 	foreach(e, extensions) {
 		unsigned char *fname = NULL;
