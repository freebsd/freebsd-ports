--- src/zm_image.cpp.orig	2009-05-25 22:04:00.000000000 +0400
+++ src/zm_image.cpp	2011-04-08 17:48:07.338804532 +0400
@@ -461,7 +461,7 @@ bool Image::DecodeJpeg( const JOCTET *in
 		return( false );
 	}
 
-	jpeg_mem_src( cinfo, inbuffer, inbuffer_size );
+	zm_jpeg_mem_src( cinfo, inbuffer, inbuffer_size );
 
 	jpeg_read_header( cinfo, TRUE );
 
@@ -523,7 +523,7 @@ bool Image::EncodeJpeg( JOCTET *outbuffe
 		jpeg_create_compress( cinfo );
 	}
 
-	jpeg_mem_dest( cinfo, outbuffer, outbuffer_size );
+	zm_jpeg_mem_dest( cinfo, outbuffer, outbuffer_size );
 
 	cinfo->image_width = width; 	/* image width and height, in pixels */
 	cinfo->image_height = height;
