--- src/core/device/k3bdevicemanager.cpp.orig	Sun Nov  2 15:42:06 2003
+++ src/core/device/k3bdevicemanager.cpp	Fri Nov  7 12:35:44 2003
@@ -33,7 +33,13 @@
 
 #include <iostream>
 #include <fstab.h>
+#ifndef __FreeBSD__
 #include <mntent.h>
+#else
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
@@ -42,6 +48,11 @@
 #include <sys/stat.h>
 #include <sys/ioctl.h>
 #include <limits.h>
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#include <ktempfile.h>
+#include <sys/param.h>
+#else
 
 /* Fix definitions for 2.5 kernels */
 #include <linux/version.h>
@@ -80,6 +91,7 @@
   (SCSI_DISK_MAJOR(M)   \
    || (M) == SCSI_CDROM_MAJOR)
 #endif /* #ifndef SCSI_BLK_MAJOR */
+#endif
 
 class K3bCdDevice::DeviceManager::Private
 {
@@ -194,6 +206,22 @@
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
@@ -284,6 +312,7 @@
 //       m_foundDevices++;
 //   }
 
+#endif
   scanFstab();
 
   return m_foundDevices;
@@ -426,10 +455,11 @@
 
 void K3bCdDevice::DeviceManager::determineCapabilities(K3bDevice *dev)
 {
+#ifndef __FreeBSD__
   // we just need to do this for writers since we use it to determine the writing modes
   if( !dev->burner() )
     return;
-
+#endif
 
   // we do not use the user configured cdrecord here since we want to make sure
   // to get all the capabilities of the system
@@ -480,9 +510,17 @@
 	dev->m_burner = true;
 	dev->m_writeModes = 0;
 	QStringList lines = QStringList::split( "\n", m_processOutput );
+#ifdef __FreeBSD__
+	bool done = false;
+#endif
 	for( QStringList::const_iterator it = lines.begin(); it != lines.end(); ++it )
 	  {
 	    const QString& line = *it;
+#ifdef __FreeBSD__
+	    kdDebug() << "(K3bDeviceManager): " << line << endl;
+	    if (done)
+            	continue;
+#endif
 
 	    // no info in cdrecord <= 1.10 !!!!!
 	    if( line.startsWith( "Supported modes" ) )
@@ -504,7 +542,11 @@
 		  dev->m_writeModes |= K3bDevice::RAW_R96R;
 		if( modes.contains( "RAW/R96P" ) )
 		  dev->m_writeModes |= K3bDevice::RAW_R96P;
+#ifdef __FreeBSD__
+		done = true;
+#else
 		break;
+#endif
 	      }
 	  }
       }
@@ -515,12 +557,110 @@
     if( dev->m_writeModes == 0 )
       dev->m_writeModes = K3bDevice::SAO|K3bDevice::TAO;
   }
+#ifdef __FreeBSD__
+// For some unknown reason KDE stdout redirection fails on cdrecord -prcap (FreeBSD) :-(
+// See http://www.FreeBSD.org/cgi/query-pr.cgi?pr=ports/51651
+// So it is written to a temp file here
+    KTempFile tmpfile;
+    tmpfile.setAutoDelete(true);
+    QString call = cdrecordBin->path + " " + QString("dev=%1").arg(dev->busTargetLun()) + " -prcap > " + tmpfile.name();
+    kdDebug() << "(K3bDeviceManager) calling: " << call << endl;
+    int result = system(call.latin1());
+    if (!result)
+       kdDebug() << "(K3bDeviceManager) call failed: " << result << endl;
+    QFile tmp (tmpfile.name());
+    if ( tmp.open( IO_ReadOnly ) )
+     {
+        QTextStream stream( &tmp );
+        while ( !stream.eof() )
+	{
+            QString line = stream.readLine();
+            kdDebug() << "(K3bDeviceManager): " << line << endl;
+      if( line.startsWith("  ") )
+	{
+	  if( line.contains("write CD-R media") )
+          {
+            bool b = !line.contains( "not" );
+	    dev->m_burner = b;
+            kdDebug() << "(K3bDeviceManager) is burner: " << b << endl;
+            if (b)
+            {
+	      dev->addDeviceType(K3bDevice::CDR);
+              kdDebug() << "(K3bDeviceManager) device type: CDR" << endl;
+            }
+          }
+
+	  else if( line.contains("write CD-RW media") )
+          {
+            bool b = !line.contains( "not" );
+	    dev->m_bWritesCdrw = b;
+            kdDebug() << "(K3bDeviceManager) writes cdr: " << b << endl;
+            if (b)
+            {
+	      dev->addDeviceType(K3bDevice::CDRW);
+              kdDebug() << "(K3bDeviceManager) device type: CDRW" << endl;
+            }
+          }
+
+	  else if( line.contains("Buffer-Underrun-Free recording") ||
+		   line.contains("support BURN-Proof") )
+          {
+            bool b = !line.contains( "not" );
+	    dev->setBurnproof(b);
+            kdDebug() << "(K3bDeviceManager) burn proof: " << b << endl;
+          }
+
+	  else if( line.contains( "Maximum read  speed" ) ) //lukas: are there really two spaces? trueg: Yes, there are! ;)
+	    dev->m_maxReadSpeed = K3b::round( line.mid( line.find(":")+1 ).toDouble() * 1000.0 / ( 2352.0 * 75.0 ) );
+
+	  else if( line.contains( "Maximum write speed" ) )
+{
+	    dev->m_maxWriteSpeed = K3b::round( line.mid( line.find(":")+1 ).toDouble() * 1000.0 / ( 2352.0 * 75.0 ) );
+}
+	else if( line.contains( "Does read CD-R media" ) )
+        {
+	  dev->addDeviceType(K3bDevice::CDROM);
+          kdDebug() << "(K3bDeviceManager) device type: CDROM" << endl;
+        }
+	else if( line.contains( "Does write DVD-R media" ) )
+        {
+	  dev->addDeviceType(K3bDevice::DVDR);
+          kdDebug() << "(K3bDeviceManager) device type: DVDR" << endl;
+        }
+	else if( line.contains( "Does write DVD-RAM media" ) )
+        {
+	  dev->addDeviceType(K3bDevice::DVDRAM);
+          kdDebug() << "(K3bDeviceManager) device type: DVDRAM" << endl;
+        }
+	else if( line.contains( "Does read DVD-ROM media" ) )
+        {
+	  dev->addDeviceType(K3bDevice::DVD);
+          kdDebug() << "(K3bDeviceManager) device type: DVD" << endl;
+        }
+	  else if( line.contains( "Buffer size" ) )
+	    dev->m_bufferSize = line.mid( line.find(":")+1 ).toInt();
+	}
+      else if( line.startsWith("Vendor_info") )
+        dev->m_vendor = line.mid( line.find(":")+3, 8 ).stripWhiteSpace();
+      else if( line.startsWith("Identifikation") )
+        dev->m_description = line.mid( line.find(":")+3, 16 ).stripWhiteSpace();
+      else if( line.startsWith("Revision") )
+        dev->m_version = line.mid( line.find(":")+3, 4 ).stripWhiteSpace();
+      else
+        kdDebug() << "(K3bDeviceManager) unused cdrecord output: " << line << endl;
+
+    }
+    tmp.close();
+    }
+    dev->guessProfiles();
+#endif
 }
 
 
 bool K3bCdDevice::DeviceManager::testForCdrom(const QString& devicename)
 {
   bool ret = false;
+#ifndef __FreeBSD__
   int cdromfd = K3bCdDevice::openDevice( devicename.ascii() );
   if (cdromfd < 0) {
     kdDebug() << "could not open device " << devicename << " (" << strerror(errno) << ")" << endl;
@@ -549,11 +689,51 @@
     }
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
@@ -586,6 +766,7 @@
     device->m_lun = lun;
   }
 
+#endif
   if( !device->init() ) {
     kdDebug() << "Could not initialize device " << devicename << endl;
     delete device;
@@ -623,13 +804,14 @@
 
 void K3bCdDevice::DeviceManager::scanFstab()
 {
+#ifndef __FreeBSD__
   FILE* fstabFile = setmntent( _PATH_FSTAB, "r" );
   if( !fstabFile )
   {
     kdDebug() << "(K3bDeviceManager) could not open " << _PATH_FSTAB << endl;
     return;
   }
-
+#endif
 
   // clear all mount-Infos
   for( QPtrListIterator<K3bDevice> it( d->allDevices ); it.current(); ++it )
@@ -639,12 +821,22 @@
   }
 
 
+#ifndef __FreeBSD__
   struct mntent* mountInfo = 0;
   while( (mountInfo = ::getmntent( fstabFile )) )
+#else
+  struct fstab * mountInfo = 0;
+  while( (mountInfo = ::getfsent()) )
+#endif  
   {
     // check if the entry corresponds to a device
+#ifndef __FreeBSD__
     QString md = QFile::decodeName( mountInfo->mnt_fsname );
     QString type = QFile::decodeName( mountInfo->mnt_type );
+#else
+    QString md = QFile::decodeName( mountInfo->fs_spec );
+    QString type = QFile::decodeName( mountInfo->fs_vfstype );
+#endif    
 
     bool supermount = false;
 
@@ -652,7 +844,11 @@
       supermount = true;
 
       // parse the device
+#ifndef __FreeBSD__
       QStringList opts = QStringList::split( ",", QString::fromLocal8Bit(mountInfo->mnt_opts) );
+#else
+      QStringList opts = QStringList::split( ",", QString::fromLocal8Bit(mountInfo->fs_mntops) );
+#endif
       for( QStringList::const_iterator it = opts.begin(); it != opts.end(); ++it ) {
 	if( (*it).startsWith("dev=") ) {
 	  md = (*it).mid( 4 );
@@ -668,9 +864,20 @@
 
     if( K3bDevice* dev = findDevice( resolveSymLink(md) ) )
     {
+#ifndef __FreeBSD__
       kdDebug() << "(K3bDeviceManager) found device for " << md << ": " << resolveSymLink(md) << endl;
       if( dev->mountDevice().isEmpty() ) {
         dev->setMountPoint( mountInfo->mnt_dir );
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
@@ -679,6 +886,8 @@
     {
       // compare bus, id, lun since the same device can for example be
       // determined as /dev/srX or /dev/scdX
+#ifndef __FreeBSD__
+// On FreeBSD scsi parameters can not be extracted from a file handle
       int bus = -1, id = -1, lun = -1;
       if( determineBusIdLun( mountInfo->mnt_fsname, bus, id, lun ) ) {
         if( K3bDevice* dev = findDevice( bus, id, lun ) ) {
@@ -689,12 +898,27 @@
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
   } // while mountInfo
 
+#ifndef __FreeBSD__
   endmntent( fstabFile );
+#else
+  endfsent();
+#endif
 }
 
 
@@ -707,6 +931,8 @@
 bool K3bCdDevice::DeviceManager::determineBusIdLun( const QString& dev, int& bus, int& id, int& lun )
 {
   int ret = false;
+#ifndef __FreeBSD__
+// On FreeBSD scsi parameters can not be extracted from a file handle
   int cdromfd = K3bCdDevice::openDevice( dev.ascii() );
   if (cdromfd < 0) {
     kdDebug() << "could not open device " << dev << " (" << strerror(errno) << ")" << endl;
@@ -743,6 +969,7 @@
 
 
   ::close(cdromfd);
+#endif
   return ret;
 }
 
@@ -750,6 +977,7 @@
 QString K3bCdDevice::DeviceManager::resolveSymLink( const QString& path )
 {
   char resolved[PATH_MAX];
+  kdDebug() << "(K3bDeviceManager) resolveSymLink: \"" << path << "\"" << endl;
   if( !realpath( QFile::encodeName(path), resolved ) )
   {
     kdDebug() << "Could not resolve " << path << endl;
@@ -784,5 +1012,125 @@
   else
     return QString("ATAPI:%1").arg(dev->blockDeviceName());
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
+
 
 #include "k3bdevicemanager.moc"
