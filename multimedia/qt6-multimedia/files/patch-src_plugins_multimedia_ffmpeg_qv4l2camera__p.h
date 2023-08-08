--- src/plugins/multimedia/ffmpeg/qv4l2camera_p.h.orig	2022-12-12 19:36:40 UTC
+++ src/plugins/multimedia/ffmpeg/qv4l2camera_p.h
@@ -23,6 +23,8 @@
 #include <qsocketnotifier.h>
 #include <qmutex.h>
 
+#include <sys/time.h> // timeval
+
 QT_BEGIN_NAMESPACE
 
 class QV4L2CameraDevices : public QObject,
