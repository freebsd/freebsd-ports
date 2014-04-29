--- media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc
+++ media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc
@@ -19,7 +19,7 @@
 #include <stdlib.h>
 
 //v4l includes
-#if defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/videoio.h>
 #elif defined(__sun)
 #include <sys/videodev2.h>
--- media/webrtc/trunk/webrtc/modules/video_capture/linux/video_capture_linux.cc
+++ media/webrtc/trunk/webrtc/modules/video_capture/linux/video_capture_linux.cc
@@ -18,7 +18,7 @@
 #include <string.h>
 
 //v4l includes
-#if defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/videoio.h>
 #elif defined(__sun)
 #include <sys/videodev2.h>
