--- src/device/k3bdevicemanager.cpp.orig	Wed Jan 21 11:20:10 2004
+++ src/device/k3bdevicemanager.cpp	Fri Feb 13 21:03:38 2004
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
 
@@ -196,6 +202,22 @@
 {
   m_foundDevices = 0;
 
+#ifdef __FreeBSD__
+// What k3b does here is the following: it takes a list of device point, which are good candidates for cd drives
+// and asks their properties. If they are indeed cd drives, they are added to a device list. This does not work
+// on FreeBSD (no corresponding ioctls). Here cdrecord is asked for a list of scsi device, which work as cd
+// drives. The device points of those devices are added to the device list.
+  bsd_scan_devices(false);
+  kdDebug() << "(K3bDeviceManager) analyze found device" << endl;
+  for ( QValueList<BSDDevice>::iterator it = m_devices.begin(); it != m_devices.end(); ++it )
+  {
+     if( addDevice( (*it).m_name ) )
+     {
+        kdDebug() << "(K3bDeviceManager) Device " << (*it).m_name << " added" << endl;
+        m_foundDevices++;
+     }
+  }
+#else
   QFile info("/proc/sys/dev/cdrom/info");
   QString line,devstring;
   info.open(IO_ReadOnly);
@@ -286,6 +308,7 @@
 //       m_foundDevices++;
 //   }
 
+#endif
   scanFstab();
 
   return m_foundDevices;
@@ -427,6 +450,7 @@
 bool K3bCdDevice::DeviceManager::testForCdrom(const QString& devicename)
 {
   bool ret = false;
+#ifndef __FreeBSD__
   int cdromfd = K3bCdDevice::openDevice( devicename.ascii() );
   if (cdromfd < 0) {
     kdDebug() << "could not open device " << devicename << " (" << strerror(errno) << ")" << endl;
@@ -467,11 +491,51 @@
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
+  K3bDevice* device = 0;
+  if (!m_lastRefresh.isValid())
+    bsd_scan_devices(false);
+  bool found = false;
+  for ( QValueList<BSDDevice>::iterator it = m_devices.begin(); it != m_devices.end(); ++it )
+  {
+     if( (*it).m_name == devicename )
+     {
+        device = new K3bDevice((*it).m_name.latin1());
+        device->m_bus = (*it).m_bus;
+        device->m_target = (*it).m_target;
+        device->m_lun = (*it).m_lun;
+        device->m_passDevice = (*it).m_passDevice;
+        device->m_vendor = (*it).m_vendor;
+        device->m_description = (*it).m_product;
+        device->m_version = (*it).m_revision;
+        found = true;
+        break;
+     }
+  }
+  if (!found)
+  {
+  // resolve all symlinks
+      QString resolved = resolveSymLink( devicename );
+      kdDebug() << "(K3bDeviceManager) " << devicename << " resolved to " << resolved << endl;
+      int bus, target, lun;
+      if( K3bDevice* oldDev = findDevice( bus, target, lun ) )
+      {
+	kdDebug() << "(K3bDeviceManager) dev already found" << endl;
+	oldDev->addDeviceNode( resolved );
+      }
+      return 0;
+  }
+
+#else
   K3bDevice* device = 0;
 
   // resolve all symlinks
@@ -503,6 +567,7 @@
     device->m_target = target;
     device->m_lun = lun;
   }
+#endif
 
   if( !device->init() ) {
     kdDebug() << "Could not initialize device " << devicename << endl;
@@ -578,9 +643,20 @@
 
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
@@ -589,6 +665,8 @@
     {
       // compare bus, id, lun since the same device can for example be
       // determined as /dev/srX or /dev/scdX
+#ifndef __FreeBSD__
+// On FreeBSD scsi parameters can not be extracted from a file handle
       int bus = -1, id = -1, lun = -1;
       if( determineBusIdLun( mountInfo->fs_spec, bus, id, lun ) ) {
         if( K3bDevice* dev = findDevice( bus, id, lun ) ) {
@@ -599,6 +677,17 @@
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
@@ -673,5 +762,126 @@
   return QString::fromLatin1( resolved );
 }
 
+
+#ifdef __FreeBSD__
+// Calls "camcontrol devlist" to get a list of all available cd devices.
+// The sudo flag indicates, that "camcontrol devlist" should be
+// called. This is tried, if bsd_scan_devices(false) fails.
+// The result of the scan ist stored in m_devices. If within 3
+// seconds after the last call to bsd_scan_devices this function
+// is called again, the last result is used (prevents to call
+// camcontrol several times within a short time).
+void K3bCdDevice::DeviceManager::bsd_scan_devices(bool sudo)
+{
+    QDateTime now = QDateTime::currentDateTime();
+    if (m_lastRefresh.isValid() && m_lastRefresh.secsTo(now) < 3)
+        return;
+    m_lastRefresh = now;
+    m_devices.clear();
+    kdDebug() << "(K3bDeviceManager) Scanning for devices: " << sudo << endl;
+    KTempFile tmpfile;
+    tmpfile.setAutoDelete(true);
+
+    // create call
+    QString call = "/bin/sh -c \"";
+    if (sudo)
+        call += "sudo ";
+    call += "camcontrol devlist > " + tmpfile.name() + " 2>&1 \"";
+    kdDebug() << "(K3bDeviceManager) Reading device list : " << call << endl;
+    if (system(call.latin1()))
+    {
+         if (!sudo)
+         {
+             m_lastRefresh = m_lastRefresh.addDays(-1);
+             bsd_scan_devices(true);
+         }
+             return;
+    }
+
+    // read tmp file line by line
+    QFile tmp (tmpfile.name());
+    if ( tmp.open( IO_ReadOnly ) )
+    {
+        QTextStream stream( &tmp );
+        while ( !stream.eof() )
+	{
+	    QString str = stream.readLine();
+            if (!str.startsWith("<"))
+                continue;
+            str.remove(0,1);
+            int i = str.find(">");
+            if (i < 0)
+                continue;
+            QStringList details = QStringList::split(" ", str.left(i));
+            i = str.find("at scbus", i);
+            if (i < 0)
+                continue;
+            str.remove(0, i+8);
+            i = str.find(" ");
+            if (i < 0)
+                continue;
+            bool ok;
+            int bus = str.left(i).toInt(&ok);
+            if (!ok)
+                continue;
+            i = str.find("target ", i);
+            if (i < 0)
+                continue;
+            str.remove(0, i+7);
+            i = str.find(" ");
+            if (i < 0)
+                continue;
+            int target = str.left(i).toInt(&ok);
+            if (!ok)
+                continue;
+            i = str.find("lun ", i);
+            if (i < 0)
+                continue;
+            str.remove(0, i+4);
+            i = str.find(" ");
+            if (i < 0)
+                continue;
+            int lun = str.left(i).toInt(&ok);
+            if (!ok)
+                continue;
+            i = str.find("(", i);
+            if (i < 0)
+                continue;
+            str.remove(0, i+1);
+            i = str.find(",");
+            if (i < 0)
+                continue;
+            QString name = str.left(i);
+            str.remove(0, i+1);
+            i = str.find(")");
+            if (i < 0)
+                continue;
+            QString pass = name;
+            if (name.startsWith("pass"))
+                name = str.left(i);
+            else
+                pass = str.left(i);
+            QString vendor, product, revision;
+            if (details.count() > 0)
+               revision = details.last();
+            details.pop_back();
+            if (details.count() > 0)
+               product = details.last();
+            details.pop_back();
+            if (details.count() > 0)
+               vendor = details.join(" ");
+            if (!name.startsWith("cd"))
+               continue;
+            kdDebug() << "(K3bDeviceManager) Found device " << name << ", pass = " << pass << ", bus = " << bus << ", target = " << target << ", lun = " << lun << endl;
+            kdDebug() << "(K3bDeviceManager) vendor: " << vendor << ", product: " << product << ", revision: " << revision << ", target = " << target << ", lun = " << lun << endl;
+#if __FreeBSD_version >= 500100
+            m_devices.push_back(BSDDevice("/dev/" + name, "/dev/" + pass, vendor, product, revision, bus, target, lun));
+#else
+            m_devices.push_back(BSDDevice("/dev/" + name + "c", "/dev/" + pass, vendor, product, revision, bus, target, lun));
+#endif
+        }
+    }
+}
+#endif
 
 #include "k3bdevicemanager.moc"
