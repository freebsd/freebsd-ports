--- src/plugins/multimedia/ffmpeg/qv4l2camera_p.h.orig	2024-03-19 05:09:26 UTC
+++ src/plugins/multimedia/ffmpeg/qv4l2camera_p.h
@@ -18,6 +18,8 @@
 #include <private/qplatformcamera_p.h>
 #include <sys/time.h>
 
+#include <sys/time.h> // timeval
+
 QT_BEGIN_NAMESPACE
 
 class QV4L2FileDescriptor;
