--- libAvKys/Plugins/VideoCapture/src/capture/v4l2sys/src/capturev4l2.cpp.orig	2025-07-29 01:36:55 UTC
+++ libAvKys/Plugins/VideoCapture/src/capture/v4l2sys/src/capturev4l2.cpp
@@ -941,6 +941,7 @@ CaptureV4L2Private::CaptureV4L2Private(CaptureV4L2 *se
 CaptureV4L2Private::CaptureV4L2Private(CaptureV4L2 *self):
     self(self)
 {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     this->m_fsWatcher = new QFileSystemWatcher({"/dev"}, self);
     QObject::connect(this->m_fsWatcher,
                      &QFileSystemWatcher::directoryChanged,
@@ -948,12 +949,15 @@ CaptureV4L2Private::CaptureV4L2Private(CaptureV4L2 *se
                      [this] () {
         this->updateDevices();
     });
+#endif
     this->updateDevices();
 }
 
 CaptureV4L2Private::~CaptureV4L2Private()
 {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     delete this->m_fsWatcher;
+#endif
 }
 
 int CaptureV4L2Private::planesCount(const v4l2_format &format) const
@@ -1809,11 +1813,13 @@ void CaptureV4L2Private::updateDevices()
     this->m_devicesCaps = devicesCaps;
 
     if (this->m_devices != devices) {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
         if (!this->m_devices.isEmpty())
             this->m_fsWatcher->removePaths(this->m_devices);
+#endif
 
         this->m_devices = devices;
-#ifndef Q_OS_BSD4
+#if !defined(FREEBSD_BUG224011_VIDEO0)
         if (!this->m_devices.isEmpty())
             this->m_fsWatcher->addPaths(this->m_devices);
 #endif
