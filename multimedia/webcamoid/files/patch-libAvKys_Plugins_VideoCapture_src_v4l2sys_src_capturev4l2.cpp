--- libAvKys/Plugins/VideoCapture/src/v4l2sys/src/capturev4l2.cpp.orig	2019-09-30 15:37:45 UTC
+++ libAvKys/Plugins/VideoCapture/src/v4l2sys/src/capturev4l2.cpp
@@ -237,18 +237,22 @@ CaptureV4L2::CaptureV4L2(QObject *parent):
     Capture(parent)
 {
     this->d = new CaptureV4L2Private(this);
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     this->d->m_fsWatcher = new QFileSystemWatcher({"/dev"}, this);
     QObject::connect(this->d->m_fsWatcher,
                      &QFileSystemWatcher::directoryChanged,
                      [this] () {
                          this->d->updateDevices();
                      });
+#endif
     this->d->updateDevices();
 }
 
 CaptureV4L2::~CaptureV4L2()
 {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     delete this->d->m_fsWatcher;
+#endif
     delete this->d;
 }
 
@@ -1145,11 +1149,13 @@ void CaptureV4L2Private::updateDevices()
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
