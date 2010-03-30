--- src/readPNG.c.orig	2000-12-08 19:00:45.000000000 +0100
+++ src/readPNG.c	2010-03-30 03:40:10.000000000 +0200
@@ -51,8 +51,8 @@
 	ret = fread(buf, 1, 8, infile);
 	if(ret != 8)
 		return 0;
-	ret = png_check_sig(buf, 8);
-	if(!ret)
+	ret = png_sig_cmp(buf, 0, 8);
+	if(ret)
 		return(0);
 
         /* OK, it is a valid PNG file, so let's rewind it, and start 
@@ -91,8 +91,10 @@
     /*####png_set_message_fn(png_ptr,png_get_msg_ptr(png_ptr),NULL,NULL); */
 
         /* initialize the structures */
+#if 0
 	png_info_init(info_ptr);
 	png_read_init(png_ptr);
+#endif
     
         /* set up the input control */
 	png_init_io(png_ptr, infile);
