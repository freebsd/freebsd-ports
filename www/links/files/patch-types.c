--- types.c.orig	2019-11-17 18:26:27 UTC
+++ types.c
@@ -872,7 +872,8 @@ unsigned char *get_content_type_by_extension(unsigned 
 			ext = NULL;
 		}
 	if (ext) while (ext[extl] && ext[extl] != '.' && !dir_sep(ext[extl]) && !end_of_dir(url, ext[extl])) extl++;
-	if ((extl == 3 && !casecmp(ext, cast_uchar "htm", 3)) ||
+ 	if (force_html || 
+	    (extl == 3 && !casecmp(ext, cast_uchar "htm", 3)) ||
 	    (extl == 4 && !casecmp(ext, cast_uchar "html", 4)) ||
 	    (extl == 5 && !casecmp(ext, cast_uchar "xhtml", 5))) return stracpy(cast_uchar "text/html");
 	foreach(struct list, l, ll, extensions.list_entry) {
