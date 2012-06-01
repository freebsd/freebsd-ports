--- png.c.orig	2008-06-07 09:41:41.000000000 +0200
+++ png.c	2012-05-06 09:32:52.000000000 +0200
@@ -38,7 +38,7 @@
 /* Error for from-web PNG images. */
 void img_my_png_error(png_structp png_ptr, png_const_charp error_string)
 {
-	longjmp(png_ptr->jmpbuf,1);
+	longjmp(png_jmpbuf(png_ptr),1);
 }
 
 void png_info_callback(png_structp png_ptr, png_infop info_ptr)
@@ -192,7 +192,7 @@
 #ifdef DEBUG
 	if (!info_ptr) internal ("png_create_info_struct failed\n");
 #endif /* #ifdef DEBUG */
-	if (setjmp(png_ptr->jmpbuf)){
+	if (setjmp(png_jmpbuf(png_ptr))){
 error:
 		png_destroy_read_struct(&png_ptr, &info_ptr,
 			(png_infopp)NULL);
@@ -202,7 +202,7 @@
 	png_set_progressive_read_fn(png_ptr, NULL,
 				    png_info_callback, png_row_callback,
 				    png_end_callback);
-   	if (setjmp(png_ptr->jmpbuf)) goto error;
+   	if (setjmp(png_jmpbuf(png_ptr))) goto error;
 	decoder=mem_alloc(sizeof(*decoder));
 	decoder->png_ptr=png_ptr;
 	decoder->info_ptr=info_ptr;
@@ -221,7 +221,7 @@
 	png_ptr=((struct png_decoder *)(cimg->decoder))->png_ptr;
 	info_ptr=((struct png_decoder *)(cimg->decoder))->info_ptr;
 	end_callback_hit=0;
-	if (setjmp(png_ptr->jmpbuf)){
+	if (setjmp(png_jmpbuf(png_ptr))){
 		img_end(cimg);
 		return;
 	}
