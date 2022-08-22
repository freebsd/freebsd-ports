--- pwcview.c.orig	2007-10-09 07:03:10 UTC
+++ pwcview.c
@@ -837,6 +837,8 @@ void jpeg_write(int height, JSAMPIMAGE jimage, struct 
 	jdata[1] = jimage[1];
 	jdata[2] = jimage[2];
 	
+	cinfo->raw_data_in = TRUE;
+	cinfo->do_fancy_downsampling = FALSE;
 	jpeg_stdio_dest(cinfo, outfile);
 	jpeg_start_compress(cinfo, TRUE);
 
