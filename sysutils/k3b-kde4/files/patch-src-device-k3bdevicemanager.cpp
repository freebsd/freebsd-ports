--- src/device/k3bdevicemanager.cpp.orig	Sun Feb 29 13:52:41 2004
+++ src/device/k3bdevicemanager.cpp	Tue May 11 22:57:03 2004
@@ -49,6 +49,12 @@
 #include <sys/stat.h>
 #include <sys/ioctl.h>
 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#include <ktempfile.h>
+#include <sys/param.h>
+#endif
+
 
 #ifdef Q_OS_LINUX
 
@@ -196,6 +202,13 @@
 {
   m_foundDevices = 0;
 
+#ifdef __FreeBSD__
+// What k3b does here is the following: it takes a list of device point, which are good candidates for cd drives
+// and asks their properties. If they are indeed cd drives, they are added to a device list. This does not work
+// on FreeBSD (no corresponding ioctls). Here cdrecord is asked for a list of scsi device, which work as cd
+// drives. The device points of those devices are added to the device list.
+  bsd_scan_devices();
+#else
   QFile info("/proc/sys/dev/cdrom/info");
   QString line,devstring;
   info.open(IO_ReadOnly);
@@ -286,6 +299,7 @@
 //       m_foundDevices++;
 //   }
 
+#endif
   scanFstab();
 
   return m_foundDevices;
@@ -427,6 +441,7 @@
 bool K3bCdDevice::DeviceManager::testForCdrom(const QString& devicename)
 {
   bool ret = false;
+#ifndef __FreeBSD__
   int cdromfd = K3bCdDevice::openDevice( devicename.ascii() );
   if (cdromfd < 0) {
     kdDebug() << "could not open device " << devicename << " (" << strerror(errno) << ")" << endl;
@@ -467,11 +482,36 @@
   }
 
   ::close( cdromfd );
+#endif
   return ret;
 }
 
 K3bDevice* K3bCdDevice::DeviceManager::addDevice( const QString& devicename )
 {
+#ifdef __FreeBSD__
+// this piece of code extracts some device parameter, like scsi or ide device. The whole process
+// fails on FreeBSD. Here the device name is simply looked up in a list of devices found by a
+// call of cdrecord --scanbus.
+  K3bDevice* device = findDevice(devicename);
+  if (device)
+     return 0;
+  // resolve all symlinks
+      QString resolved = resolveSymLink( devicename );
+      kdDebug() << "(K3bDeviceManager) " << devicename << " resolved to " << resolved << endl;
+      if( K3bDevice* oldDev = findDevice( resolved ) )
+      {
+        kdDebug() << "(K3bDeviceManager) dev already found" << endl;
+        oldDev->addDeviceNode( resolved );
+        return 0;
+      }
+  device = new K3bDevice(resolved.latin1());
+  return addDevice( device );
+}
+
+K3bDevice* K3bCdDevice::DeviceManager::addDevice( CdDevice* device )
+{
+  const QString devicename = device->devicename();
+#else
   K3bDevice* device = 0;
 
   // resolve all symlinks
@@ -503,6 +543,7 @@
     device->m_target = target;
     device->m_lun = lun;
   }
+#endif
 
   if( !device->init() ) {
     kdDebug() << "Could not initialize device " << devicename << endl;
@@ -578,9 +619,20 @@
 
     if( K3bDevice* dev = findDevice( resolveSymLink(md) ) )
     {
+#ifndef __FreeBSD__
       kdDebug() << "(K3bDeviceManager) found device for " << md << ": " << resolveSymLink(md) << endl;
       if( dev->mountDevice().isEmpty() ) {
         dev->setMountPoint( mountInfo->fs_file );
+#else
+      kdDebug() << "(K3bDeviceManager) found device for " << md << " (" << resolveSymLink(md) << "): " << mountInfo->fs_file << endl;
+// Several mount points for one device might exist. If more than one are found, the one with
+// user permission should have a higher priority.
+      struct stat filestat;
+      if( dev->mountDevice().isEmpty() || (mountInfo->fs_file && !stat(mountInfo->fs_file, &filestat) && filestat.st_uid == geteuid()))
+      {
+        kdDebug() << "(K3bDeviceManager) setting mount point for device " << md << ": " << mountInfo->fs_file << endl;
+        dev->setMountPoint( mountInfo->fs_file );
+#endif
         dev->setMountDevice( md );
 	dev->m_supermount = supermount;
       }
@@ -589,6 +641,8 @@
     {
       // compare bus, id, lun since the same device can for example be
       // determined as /dev/srX or /dev/scdX
+#ifndef __FreeBSD__
+// On FreeBSD scsi parameters can not be extracted from a file handle
       int bus = -1, id = -1, lun = -1;
       if( determineBusIdLun( mountInfo->fs_spec, bus, id, lun ) ) {
         if( K3bDevice* dev = findDevice( bus, id, lun ) ) {
@@ -599,6 +653,17 @@
           }
         }
       }
+#else
+// Therefore they are looked up in the device list.
+          kdDebug() << "(K3bDeviceManager) device:  " << mountInfo->fs_spec << endl;
+	  if( K3bDevice* dev = findDevice( mountInfo->fs_spec ) ) {
+            kdDebug() << " found! " << endl;
+	    if( dev->mountDevice().isEmpty() ) {
+	      dev->setMountPoint( mountInfo->fs_file );
+	      dev->setMountDevice( md );
+	    }
+	  }
+#endif
 
 
     }
@@ -674,5 +739,131 @@
   return QString::fromLatin1( resolved );
 }
 
+
+#ifdef __FreeBSD__
+#include <cam/cam.h>
+#include <cam/scsi/scsi_pass.h>
+#include <camlib.h>
+void K3bCdDevice::DeviceManager::bsd_scan_devices()
+{
+	union ccb ccb;
+	int fd, i;
+	int need_close = 0;
+	int skip_device = 0;
+	int bus, target, lun;
+	QString dev1, dev2;
+
+	if ((fd = open(XPT_DEVICE, O_RDWR)) == -1) 
+	{
+		kdDebug() << "couldn't open %s " << XPT_DEVICE << endl;
+		return;
+	}
+	
+	memset(&ccb, 0, sizeof(ccb));
+
+	ccb.ccb_h.func_code = XPT_DEV_MATCH;
+	char buffer[100*sizeof(struct dev_match_result)];
+	ccb.cdm.match_buf_len = 100*sizeof(struct dev_match_result);
+	ccb.cdm.matches = (struct dev_match_result *)buffer;
+	ccb.cdm.num_matches = 0;
+	ccb.cdm.num_patterns = 0;
+	ccb.cdm.pattern_buf_len = 0;
+	do {
+		if (ioctl(fd, CAMIOCOMMAND, &ccb) == -1) {
+			kdDebug() << "(bsd_scan_devices) error sending CAMIOCOMMAND ioctl: " << errno << endl;
+			break;
+		}
+
+		if ((ccb.ccb_h.status != CAM_REQ_CMP)
+		 || ((ccb.cdm.status != CAM_DEV_MATCH_LAST) && (ccb.cdm.status != CAM_DEV_MATCH_MORE))) {
+			kdDebug() << "(bsd_scan_devices) got CAM error " << ccb.ccb_h.status << ", CDM error %d" << ccb.cdm.status << endl;
+			break;
+		}
+		kdDebug() << "(bsd_scan_devices) number of matches " << (int)ccb.cdm.num_matches << endl;
+		for (int i = 0; i < (int)ccb.cdm.num_matches; i++) {
+			switch (ccb.cdm.matches[i].type) {
+			case DEV_MATCH_DEVICE: {
+				struct device_match_result *dev_result = &ccb.cdm.matches[i].result.device_result;
+
+				if (dev_result->flags & DEV_RESULT_UNCONFIGURED)
+				{
+					skip_device = 1;
+					break;
+				} 
+				else
+					skip_device = 0;
+				if (need_close) 
+				{
+					QString pass = dev1;
+					QString dev = "/dev/" + dev2;
+					if (dev2.startsWith("pass"))
+					{
+						pass = dev2;
+						dev = "/dev/" + dev1;
+					}
+#if __FreeBSD_version < 500100
+					dev += "c";
+#endif
+
+					K3bDevice* device = new K3bDevice(dev.latin1());
+					device->m_bus = bus;
+					device->m_target = target;
+					device->m_lun = lun;
+					device->m_passDevice = "/dev/" + pass;
+					kdDebug() << "(bsd_scan_devices) add device " << dev << ":" << bus << ":" << target << ":" << lun << endl;
+					addDevice(device);
+					need_close = 0;
+				}
+				bus = dev_result->path_id;
+				target = dev_result->target_id;
+				lun = dev_result->target_lun;
+
+				need_close = 1;
+
+				break;
+			}
+			case DEV_MATCH_PERIPH: {
+				struct periph_match_result *periph_result = &ccb.cdm.matches[i].result.periph_result;
+
+				if (skip_device != 0)
+					break;
+
+				if (need_close > 1)
+					dev1 = periph_result->periph_name + QString::number(periph_result->unit_number);
+				else
+					dev2 = periph_result->periph_name + QString::number(periph_result->unit_number);
+
+				need_close++;
+				break;
+			}
+			}
+		}
+
+	} while ((ccb.ccb_h.status == CAM_REQ_CMP)
+		&& (ccb.cdm.status == CAM_DEV_MATCH_MORE));
+
+	if (need_close)
+	{
+					QString pass = dev1;
+					QString dev = "/dev/" + dev2;
+					if (dev2.startsWith("pass"))
+					{
+						pass = dev2;
+						dev = "/dev/" + dev1;
+					}
+#if __FreeBSD_version < 500100
+					dev += "c";
+#endif
+					K3bDevice* device = new K3bDevice(dev.latin1());
+					device->m_bus = bus;
+					device->m_target = target;
+					device->m_lun = lun;
+					device->m_passDevice = "/dev/" + pass;
+					kdDebug() << "(bsd_scan_devices) add device " << dev << ":" << bus << ":" << target << ":" << lun << endl;
+					addDevice(device);
+	}
+	close(fd);
+}
+#endif
 
 #include "k3bdevicemanager.moc"
