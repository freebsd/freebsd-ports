--- libs/tiff/tif_dirread.c.orig	Fri Nov 26 21:39:06 2004
+++ libs/tiff/tif_dirread.c	Mon Aug  1 01:06:34 2005
@@ -69,7 +69,7 @@
 	char	*cp = NULL;
 	tsize_t	bytes = nmemb * elem_size;
 
-	if (elem_size && bytes / elem_size == nmemb)
+	if (nmemb && elem_size && bytes / elem_size == nmemb)
 		cp = (char*)_TIFFmalloc(tif, bytes);
 
  	if (cp == NULL)
@@ -1267,12 +1267,16 @@
 		uint16 buf[10];
 		uint16* v = buf;
 
-		if (samples > (int)NITEMS(buf))
-		    v = (uint16*) CheckMalloc(tif, samples, sizeof (uint16),
+		if (dir->tdir_count > (int)NITEMS(buf))
+		    v = (uint16*) CheckMalloc(tif, dir->tdir_count, sizeof (uint16),
 					      "to fetch per-sample values");
 		if (v && TIFFFetchShortArray(tif, dir, v)) {
 			int i;
-			for (i = 1; i < samples; i++)
+			int check_count = dir->tdir_count;
+			if( samples < check_count )
+				check_count = samples;
+
+			for (i = 1; i < check_count; i++)
 				if (v[i] != v[0]) {
 					TIFFError(tif->tif_name,
 		"Cannot handle different per-sample values for field \"%s\"",
@@ -1304,12 +1308,16 @@
 		double buf[10];
 		double* v = buf;
 
-		if (samples > (int)NITEMS(buf))
-			v = (double*) CheckMalloc(tif, samples, sizeof (double),
+		if (dir->tdir_count > (int)NITEMS(buf))
+			v = (double*) CheckMalloc(tif, dir->tdir_count, sizeof (double),
 						  "to fetch per-sample values");
 		if (v && TIFFFetchAnyArray(tif, dir, v)) {
 			int i;
-			for (i = 1; i < samples; i++)
+			int check_count = dir->tdir_count;
+			if( samples < check_count )
+				check_count = samples;
+
+			for (i = 1; i < check_count; i++)
 				if (v[i] != v[0]) {
 					TIFFError(tif->tif_name,
 		"Cannot handle different per-sample values for field \"%s\"",
