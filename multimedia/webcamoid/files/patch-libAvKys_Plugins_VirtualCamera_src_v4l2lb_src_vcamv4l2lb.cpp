--- libAvKys/Plugins/VirtualCamera/src/v4l2lb/src/vcamv4l2lb.cpp.orig	2025-07-29 01:36:55 UTC
+++ libAvKys/Plugins/VirtualCamera/src/v4l2lb/src/vcamv4l2lb.cpp
@@ -1449,6 +1449,7 @@ VCamV4L2LoopBackPrivate::VCamV4L2LoopBackPrivate(VCamV
     self(self)
 {
     this->initDefaultFormats();
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     this->m_fsWatcher = new QFileSystemWatcher({"/dev"}, self);
     QObject::connect(this->m_fsWatcher,
                      &QFileSystemWatcher::directoryChanged,
@@ -1456,12 +1457,15 @@ VCamV4L2LoopBackPrivate::VCamV4L2LoopBackPrivate(VCamV
                      [this] () {
         this->updateDevices();
     });
+#endif
     this->updateDevices();
 }
 
 VCamV4L2LoopBackPrivate::~VCamV4L2LoopBackPrivate()
 {
+#if !defined(FREEBSD_BUG224011_VIDEO0)
     delete this->m_fsWatcher;
+#endif
 }
 
 int VCamV4L2LoopBackPrivate::xioctl(int fd, ulong request, void *arg) const
@@ -2511,11 +2515,13 @@ void VCamV4L2LoopBackPrivate::updateDevices()
     this->m_devicesFormats = devicesFormats;
 
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
