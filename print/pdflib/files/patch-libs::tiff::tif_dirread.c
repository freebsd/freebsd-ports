--- libs/tiff/tif_dirread.c.orig	Sun Jan 23 12:04:30 2005
+++ libs/tiff/tif_dirread.c	Sun Jan 23 12:05:30 2005
@@ -69,7 +69,7 @@
 	char	*cp = NULL;
 	tsize_t	bytes = nmemb * elem_size;
 
-	if (elem_size && bytes / elem_size == nmemb)
+	if (nmemb && elem_size && bytes / elem_size == nmemb)
 		cp = (char*)_TIFFmalloc(tif, bytes);
 
  	if (cp == NULL)
