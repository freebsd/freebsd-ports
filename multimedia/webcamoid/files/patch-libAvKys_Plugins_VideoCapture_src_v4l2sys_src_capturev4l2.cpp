--- libAvKys/Plugins/VideoCapture/src/v4l2sys/src/capturev4l2.cpp.orig	2021-02-15 15:25:23 UTC
+++ libAvKys/Plugins/VideoCapture/src/v4l2sys/src/capturev4l2.cpp
@@ -727,6 +727,7 @@ void CaptureV4L2::reset()
 CaptureV4L2Private::CaptureV4L2Private(CaptureV4L2 *self):
     self(self)
 {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     this->m_fsWatcher = new QFileSystemWatcher({"/dev"}, self);
     QObject::connect(this->m_fsWatcher,
                      &QFileSystemWatcher::directoryChanged,
@@ -734,12 +735,15 @@ CaptureV4L2Private::CaptureV4L2Private(CaptureV4L2 *se
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
 
 QVariantList CaptureV4L2Private::capsFps(int fd,
@@ -1385,11 +1389,13 @@ void CaptureV4L2Private::updateDevices()
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
