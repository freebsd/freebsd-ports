In file included from vdpau_video.c:22:
./vdpau_video.h:277:12: warning: declaration of 'struct v4l2_format' will not be visible outside of this function
      [-Wvisibility]
    struct v4l2_format *v4l2_fmt,
           ^
./vdpau_video.h:278:12: warning: declaration of 'struct v4l2_buffer' will not be visible outside of this function
      [-Wvisibility]
    struct v4l2_buffer *v4l2_buf,
           ^
vdpau_video.c:930:12: warning: declaration of 'struct v4l2_format' will not be visible outside of this function
      [-Wvisibility]
    struct v4l2_format *v4l2_fmt,
           ^
vdpau_video.c:931:12: warning: declaration of 'struct v4l2_buffer' will not be visible outside of this function
      [-Wvisibility]
    struct v4l2_buffer *v4l2_buf,
           ^
vdpau_video.c:927:1: error: conflicting types for 'vdpau_CreateSurfaceFromV4L2Buf'
vdpau_CreateSurfaceFromV4L2Buf(
^
./vdpau_video.h:274:1: note: previous declaration is here
vdpau_CreateSurfaceFromV4L2Buf(
^
4 warnings and 1 error generated.

--- src/vdpau_video.h.orig	2012-10-05 15:02:58 UTC
+++ src/vdpau_video.h
@@ -21,6 +21,8 @@
 #ifndef VDPAU_VIDEO_H
 #define VDPAU_VIDEO_H
 
+#include <linux/videodev2.h>
+
 #include "vdpau_driver.h"
 #include "vdpau_decode.h"
 
