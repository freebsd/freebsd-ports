--- libAvKys/Plugins/VideoCapture/src/v4l2sys/src/capturev4l2.cpp.orig	2017-10-09 06:45:30 UTC
+++ libAvKys/Plugins/VideoCapture/src/v4l2sys/src/capturev4l2.cpp
@@ -60,12 +60,15 @@ inline IoMethodMap initIoMethodMap()
 
 Q_GLOBAL_STATIC_WITH_ARGS(IoMethodMap, ioMethodToStr, (initIoMethodMap()))
 
+#define FREEBSD_BUG224011_VIDEO0
+
 CaptureV4L2::CaptureV4L2(QObject *parent):
     Capture(parent)
 {
     this->m_id = -1;
     this->m_ioMethod = IoMethodUnknown;
     this->m_nBuffers = 32;
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     this->m_fsWatcher = new QFileSystemWatcher({"/dev"}, this);
 
     QObject::connect(this->m_fsWatcher,
@@ -76,13 +79,15 @@ CaptureV4L2::CaptureV4L2(QObject *parent
                      &QFileSystemWatcher::fileChanged,
                      this,
                      &CaptureV4L2::onFileChanged);
-
+#endif
     this->updateDevices();
 }
 
 CaptureV4L2::~CaptureV4L2()
 {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     delete this->m_fsWatcher;
+#endif
 }
 
 QStringList CaptureV4L2::webcams() const
@@ -1176,13 +1181,16 @@ void CaptureV4L2::updateDevices()
     this->m_cameraControls = cameraControls;
 
     if (this->m_devices != devices) {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
         if (!this->m_devices.isEmpty())
             this->m_fsWatcher->removePaths(this->m_devices);
-
+#endif
         this->m_devices = devices;
 
+#if !defined(FREEBSD_BUG224011_VIDEO0)
         if (!this->m_devices.isEmpty())
             this->m_fsWatcher->addPaths(this->m_devices);
+#endif
 
         emit this->webcamsChanged(this->m_devices);
     }
