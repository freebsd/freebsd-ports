--- src/video/cameradevice.cpp.orig	2016-04-24 12:44:18 UTC
+++ src/video/cameradevice.cpp
@@ -31,7 +31,7 @@ extern "C" {
 #ifdef Q_OS_WIN
 #include "src/platform/camera/directshow.h"
 #endif
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 #include "src/platform/camera/v4l2.h"
 #endif
 #ifdef Q_OS_OSX
@@ -122,7 +122,7 @@ CameraDevice* CameraDevice::open(QString
 
     AVDictionary* options = nullptr;
     if (!iformat);
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     else if (devName.startsWith("x11grab#"))
     {
         QSize screen;
@@ -168,7 +168,7 @@ CameraDevice* CameraDevice::open(QString
         av_dict_set(&options, "framerate", QString().setNum(mode.FPS).toStdString().c_str(), 0);
     }
 #endif
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     else if (iformat->name == QString("video4linux2,v4l2") && mode)
     {
         av_dict_set(&options, "video_size", QString("%1x%2").arg(mode.width).arg(mode.height).toStdString().c_str(), 0);
@@ -311,7 +311,7 @@ QVector<QPair<QString, QString>> CameraD
     else if (iformat->name == QString("dshow"))
         devices += DirectShow::getDeviceList();
 #endif
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     else if (iformat->name == QString("video4linux2,v4l2"))
         devices += v4l2::getDeviceList();
 #endif
@@ -358,7 +358,7 @@ QVector<VideoMode> CameraDevice::getVide
     else if (iformat->name == QString("dshow"))
         return DirectShow::getDeviceModes(devName);
 #endif
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     else if (iformat->name == QString("video4linux2,v4l2"))
         return v4l2::getDeviceModes(devName);
 #endif
@@ -400,7 +400,7 @@ bool CameraDevice::getDefaultInputFormat
     avdevice_register_all();
 
     // Desktop capture input formats
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     idesktopFormat = av_find_input_format("x11grab");
 #endif
 #ifdef Q_OS_WIN
@@ -408,7 +408,7 @@ bool CameraDevice::getDefaultInputFormat
 #endif
 
     // Webcam input formats
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     if ((iformat = av_find_input_format("v4l2")))
         return true;
 #endif
