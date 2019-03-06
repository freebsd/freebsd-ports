--- libAvKys/Plugins/VideoCapture/src/v4l2sys/src/capturev4l2.cpp.orig	2019-03-06 17:26:33 UTC
+++ libAvKys/Plugins/VideoCapture/src/v4l2sys/src/capturev4l2.cpp
@@ -162,10 +162,13 @@ class CaptureV4L2Private
                             const QVariantMap &map2) const;
 };
 
+#define FREEBSD_BUG224011_VIDEO0
+
 CaptureV4L2::CaptureV4L2(QObject *parent):
     Capture(parent)
 {
     this->d = new CaptureV4L2Private(this);
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     this->d->m_fsWatcher = new QFileSystemWatcher({"/dev"}, this);
 
     QObject::connect(this->d->m_fsWatcher,
@@ -176,13 +179,16 @@ CaptureV4L2::CaptureV4L2(QObject *parent
                      &QFileSystemWatcher::fileChanged,
                      this,
                      &CaptureV4L2::onFileChanged);
+#endif
 
     this->updateDevices();
 }
 
 CaptureV4L2::~CaptureV4L2()
 {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     delete this->d->m_fsWatcher;
+#endif
     delete this->d;
 }
 
@@ -1302,13 +1308,17 @@ void CaptureV4L2::updateDevices()
     this->d->m_devicesCaps = devicesCaps;
 
     if (this->d->m_devices != devices) {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
         if (!this->d->m_devices.isEmpty())
             this->d->m_fsWatcher->removePaths(this->d->m_devices);
+#endif
 
         this->d->m_devices = devices;
 
+#if !defined(FREEBSD_BUG224011_VIDEO0)
         if (!this->d->m_devices.isEmpty())
             this->d->m_fsWatcher->addPaths(this->d->m_devices);
+#endif
 
         emit this->webcamsChanged(this->d->m_devices);
     }
