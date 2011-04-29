--- src/zm_jpeg.c.orig	2009-03-20 15:07:00.000000000 +0300
+++ src/zm_jpeg.c	2011-04-08 17:48:07.338804532 +0400
@@ -173,7 +173,7 @@ static void term_destination (j_compress
  * for closing it after finishing compression.
  */
 
-void jpeg_mem_dest (j_compress_ptr cinfo, JOCTET *outbuffer, int *outbuffer_size )
+void zm_jpeg_mem_dest (j_compress_ptr cinfo, JOCTET *outbuffer, int *outbuffer_size )
 {
     mem_dest_ptr dest;
 
@@ -350,12 +350,12 @@ static void term_source (j_decompress_pt
  * for closing it after finishing decompression.
  */
 
-void jpeg_mem_src( j_decompress_ptr cinfo, const JOCTET *inbuffer, int inbuffer_size )
+void zm_jpeg_mem_src( j_decompress_ptr cinfo, const JOCTET *inbuffer, int inbuffer_size )
 {
     mem_src_ptr src;
 
     /* The source object and input buffer are made permanent so that a series
-     * of JPEG images can be read from the same file by calling jpeg_mem_src
+     * of JPEG images can be read from the same file by calling zm_jpeg_mem_src
      * only before the first one.  (If we discarded the buffer at the end of
      * one image, we'd likely lose the start of the next one.)
      * This makes it unsafe to use this manager and a different source
