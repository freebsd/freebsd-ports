--- ljjetready.cpp.orig	Wed Nov  2 22:42:26 2005
+++ ljjetready.cpp	Wed Nov  2 22:45:37 2005
@@ -799,17 +799,7 @@
 
 extern "C"
 {
-void jpeg_finish_compress (j_compress_ptr cinfo);
-JDIMENSION jpeg_write_scanlines (j_compress_ptr cinfo, JSAMPARRAY scanlines, JDIMENSION num_lines);
-void jpeg_start_compress(struct jpeg_compress_struct *,unsigned char);
-void jpeg_suppress_tables(struct jpeg_compress_struct *,unsigned char);
-void jpeg_add_quant_table(struct jpeg_compress_struct *,int,unsigned int const *,int,unsigned char);
-void jpeg_default_colorspace(struct jpeg_compress_struct *);
-void jpeg_set_defaults(struct jpeg_compress_struct *);
-void jpeg_CreateCompress(struct jpeg_compress_struct *,int,unsigned int);
-void jpeg_destroy_compress(struct jpeg_compress_struct *);
 void jpeg_buffer_dest (j_compress_ptr cinfo, JOCTET* outbuff, void* flush_output_buffer_callback);
-struct jpeg_error_mgr * jpeg_std_error(struct jpeg_error_mgr * err);
 }
 
 #define ConvertToGrayMacro(red, green, blue) ((unsigned char)( ( (red * 30) + (green * 59) + (blue * 11) ) / 100 ))
