--- src/video/cameradevice.cpp.orig	2016-11-13 15:20:00 UTC
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
@@ -150,7 +150,7 @@ CameraDevice* CameraDevice::open(QString
 
     AVDictionary* options = nullptr;
     if (!iformat);
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     else if (devName.startsWith("x11grab#"))
     {
         QSize screen;
@@ -359,7 +359,7 @@ QVector<QPair<QString, QString>> CameraD
     else if (iformat->name == QString("dshow"))
         devices += DirectShow::getDeviceList();
 #endif
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     else if (iformat->name == QString("video4linux2,v4l2"))
         devices += v4l2::getDeviceList();
 #endif
@@ -467,7 +467,7 @@ QVector<VideoMode> CameraDevice::getVide
     else if (iformat->name == QString("dshow"))
         return DirectShow::getDeviceModes(devName);
 #endif
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     else if (iformat->name == QString("video4linux2,v4l2"))
         return v4l2::getDeviceModes(devName);
 #endif
@@ -488,7 +488,7 @@ QVector<VideoMode> CameraDevice::getVide
  */
 QString CameraDevice::getPixelFormatString(uint32_t pixel_format)
 {
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     return v4l2::getPixelFormatString(pixel_format);
 #else
     return QString("unknown");
@@ -504,7 +504,7 @@ QString CameraDevice::getPixelFormatStri
  */
 bool CameraDevice::betterPixelFormat(uint32_t a, uint32_t b)
 {
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	return v4l2::betterPixelFormat(a, b);
 #else
 	return false;
@@ -524,7 +524,7 @@ bool CameraDevice::getDefaultInputFormat
     avdevice_register_all();
 
     // Desktop capture input formats
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     idesktopFormat = av_find_input_format("x11grab");
 #endif
 #ifdef Q_OS_WIN
@@ -532,7 +532,7 @@ bool CameraDevice::getDefaultInputFormat
 #endif
 
     // Webcam input formats
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     if ((iformat = av_find_input_format("v4l2")))
         return true;
 #endif
