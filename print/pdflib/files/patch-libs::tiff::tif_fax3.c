--- libs/tiff/tif_fax3.c.orig	Sun Jan 23 12:05:49 2005
+++ libs/tiff/tif_fax3.c	Sun Jan 23 12:06:35 2005
@@ -445,7 +445,7 @@
 	char	*cp = NULL;
 	tsize_t	bytes = nmemb * elem_size;
 
-	if (elem_size && bytes / elem_size == nmemb)
+	if (nmemb && elem_size && bytes / elem_size == nmemb)
 		cp = (char*) _TIFFmalloc(tif, bytes);
 
 	if (cp == NULL)
