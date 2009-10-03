--- ./pwcview.c.orig	2009-10-03 20:45:17.711703547 +0200
+++ ./pwcview.c	2009-10-03 20:46:00.814254980 +0200
@@ -837,6 +837,8 @@
 	jdata[1] = jimage[1];
 	jdata[2] = jimage[2];
 	
+	cinfo->raw_data_in = TRUE;
+	cinfo->do_fancy_downsampling = FALSE;
 	jpeg_stdio_dest(cinfo, outfile);
 	jpeg_start_compress(cinfo, TRUE);
 
