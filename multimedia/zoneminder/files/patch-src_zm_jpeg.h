--- src/zm_jpeg.h.orig	2009-03-20 15:07:00.000000000 +0300
+++ src/zm_jpeg.h	2011-04-08 17:48:07.339806355 +0400
@@ -36,5 +36,5 @@ void zm_jpeg_error_exit( j_common_ptr ci
 void zm_jpeg_emit_message( j_common_ptr cinfo, int msg_level );
 
 // Prototypes for memory compress/decompression object */
-void jpeg_mem_src(j_decompress_ptr cinfo, const JOCTET *inbuffer, int inbuffer_size );
-void jpeg_mem_dest(j_compress_ptr cinfo, JOCTET *outbuffer, int *outbuffer_size );
+void zm_jpeg_mem_src(j_decompress_ptr cinfo, const JOCTET *inbuffer, int inbuffer_size );
+void zm_jpeg_mem_dest(j_compress_ptr cinfo, JOCTET *outbuffer, int *outbuffer_size );
