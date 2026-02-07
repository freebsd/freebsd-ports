--- yuvdeinterlace/yuvdeinterlace.cc.orig	2009-09-19 18:16:47 UTC
+++ yuvdeinterlace/yuvdeinterlace.cc
@@ -918,7 +918,7 @@ int
 main (int argc, char *argv[])
 {
   int frame = 0;
-  int errno = 0;
+  int error = 0;
   int ss_h, ss_v;
 
   deinterlacer YUVdeint;
@@ -1009,10 +1009,10 @@ main (int argc, char *argv[])
   y4m_init_frame_info (&YUVdeint.Y4MStream.oframeinfo);
 
 /* open input stream */
-  if ((errno = y4m_read_stream_header (YUVdeint.Y4MStream.fd_in,
+  if ((error = y4m_read_stream_header (YUVdeint.Y4MStream.fd_in,
 				       &YUVdeint.Y4MStream.istreaminfo)) != Y4M_OK)
     {
-      mjpeg_error_exit1 ("Couldn't read YUV4MPEG header: %s!", y4m_strerr (errno));
+      mjpeg_error_exit1 ("Couldn't read YUV4MPEG header: %s!", y4m_strerr (error));
     }
 
   /* get format information */
@@ -1089,7 +1089,7 @@ main (int argc, char *argv[])
   y4m_write_stream_header (YUVdeint.Y4MStream.fd_out, &YUVdeint.Y4MStream.ostreaminfo);
 
   /* read every frame until the end of the input stream and process it */
-  while (Y4M_OK == (errno = y4m_read_frame (YUVdeint.Y4MStream.fd_in,
+  while (Y4M_OK == (error = y4m_read_frame (YUVdeint.Y4MStream.fd_in,
 					    &YUVdeint.Y4MStream.istreaminfo,
 					    &YUVdeint.Y4MStream.iframeinfo, YUVdeint.inframe)))
     {
