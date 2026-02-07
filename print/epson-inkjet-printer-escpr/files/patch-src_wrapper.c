--- src/wrapper.c.orig	2024-03-13 01:23:02 UTC
+++ src/wrapper.c
@@ -105,7 +105,7 @@ main (int argc, char *argv[])
 	FILE *pfp;
 	int i;			/* loop */
 	cups_raster_t *ras;	/* raster stream for printing */
-	cups_page_header_t header; /* page device dictionary header */
+	cups_page_header2_t header; /* page device dictionary header */
 	filter_option_t fopt;
 
 /* attach point */
@@ -188,7 +188,7 @@ main (int argc, char *argv[])
 	while (1)
 	{
 		int ret;
-		ret = cupsRasterReadHeader (ras, &header);
+		ret = cupsRasterReadHeader2(ras, &header);
 
 		if (ret == 0 || cancel_flg) //データをすべて読み終わった
 		{
