--- src/zm_local_camera.cpp.orig	2015-01-25 12:05:37.455924920 +0100
+++ src/zm_local_camera.cpp	2015-01-25 12:06:24.903920783 +0100
@@ -739,7 +739,7 @@
     {
         Debug( 3, "Terminating video stream" );
         //enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
-        enum v4l2_buf_type type = v4l2_data.fmt.type;
+        enum v4l2_buf_type type = (v4l2_buf_type)v4l2_data.fmt.type;
         if ( vidioctl( vid_fd, VIDIOC_STREAMOFF, &type ) < 0 )
             Error( "Failed to stop capture stream: %s", strerror(errno) );
 
@@ -1519,7 +1519,7 @@
 
         Debug( 3, "Starting video stream" );
         //enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
-        enum v4l2_buf_type type = v4l2_data.fmt.type;
+        enum v4l2_buf_type type = (v4l2_buf_type)v4l2_data.fmt.type;
         if ( vidioctl( vid_fd, VIDIOC_STREAMON, &type ) < 0 )
             Fatal( "Failed to start capture stream: %s", strerror(errno) );
     }
