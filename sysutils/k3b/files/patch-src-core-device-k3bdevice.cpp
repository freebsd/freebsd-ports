--- src/core/device/k3bdevice.cpp.orig	Thu Oct 30 11:53:35 2003
+++ src/core/device/k3bdevice.cpp	Sat Nov  8 12:15:01 2003
@@ -32,7 +32,9 @@
 #include <sys/ioctl.h>
 
 #include <fstab.h>
+#ifndef __FreeBSD__
 #include <mntent.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
@@ -40,6 +42,7 @@
 #include <errno.h>
 #include <sys/stat.h>
 
+#ifndef __FreeBSD__
 #include <linux/version.h>
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,5,70)
 typedef unsigned char u8;
@@ -48,6 +51,18 @@
 #include <linux/cdrom.h>
 #define __STRICT_ANSI__
 #include <linux/major.h>
+#else
+#include <sys/cdio.h>
+#include <sys/dvdio.h>
+#include <ktempfile.h>
+#define __BYTE_ORDER BYTE_ORDER
+#define __BIG_ENDIAN BIG_ENDIAN
+//#define CDROMEJECT CDIOCEJECT
+//#define CDROMCLOSETRAY CDIOCCLOSE
+#define CD_FRAMESIZE_RAW 2352
+#include <cam/scsi/scsi_message.h>
+int bsd_open_close_device(int bus, int target, int lun, bool eject);
+#endif
 
 
 
@@ -167,6 +182,7 @@
 {
   kdDebug() << "(K3bCdDevice) " << blockDeviceName() << ": init()" << endl;
 
+#ifndef __FreeBSD__
   if(open() < 0)
     return false;
 
@@ -175,10 +191,18 @@
   // we also query the mode page 2A and use the cdrom.h stuff to get as much information as possible
   //
 
+  // On BSD the device capabilities are already set by the devicemanager. So this code may
+  // find more capabilities -- if it works
   d->deviceType = 0;
+#endif
   d->supportedProfiles = 0;
 
+#ifndef __FreeBSD__
   ScsiCommand cmd( open() );
+#else
+  ScsiCommand cmd(m_passDevice);
+  d->deviceType |= CDROM;
+#endif  
   unsigned char header[8];
   ::memset( header, 0, 8 );
   cmd[0] = 0x46;	// GET CONFIGURATION
@@ -580,8 +604,16 @@
   int mm_cap_len = 0;
   if( modeSense( &mm_cap_buffer, mm_cap_len, 0x2A ) ) {
     mm_cap_page_2A* mm_p = (mm_cap_page_2A*)(mm_cap_buffer+8);
-    if( mm_p->BUF ) d->burnfree = true;
-    if( mm_p->cd_rw_write ) d->deviceType |= CDRW;
+    if( mm_p->BUF ) 
+    {
+        kdDebug() << "(K3bCdDevice) ModeSense: burnfree." << endl;
+    	d->burnfree = true;
+    }
+    if( mm_p->cd_rw_write ) 
+    {
+        kdDebug() << "(K3bCdDevice) ModeSense: CDRW." << endl;
+        d->deviceType |= CDRW;
+    }
     m_maxWriteSpeed = (int)( from2Byte(mm_p->max_write_speed) * 1024.0 / ( 2352.0 * 75.0 ) );
     m_maxReadSpeed = (int)( from2Byte(mm_p->max_read_speed) * 1024.0 / ( 2352.0 * 75.0 ) );
 
@@ -592,6 +624,7 @@
   }
 
 
+#ifndef __FreeBSD__
 
   //
   // This is the backup if the drive does not support the GET CONFIGURATION command
@@ -619,6 +652,7 @@
   if (drivetype & CDC_DVD)
     d->deviceType |= DVD;
    
+#endif
 
   if( writesCd() )
     checkWriteModes();
@@ -642,10 +676,11 @@
     m_version = QString::fromLocal8Bit( (char*)(inq+32), 4 ).stripWhiteSpace();
   }
 
+#ifndef __FreeBSD__
   close();
+#endif
 
   d->interfaceType = interfaceType();
-
   return furtherInit();
 }
 
@@ -649,6 +684,23 @@
   return furtherInit();
 }
 
+void K3bCdDevice::CdDevice::guessProfiles()
+{
+  if (!d->supportedProfiles)
+  {
+     kdDebug() << "(K3bCdDevice): no profiles found; setting them from device type = " << d->deviceType << endl;
+     if (d->deviceType & CDROM) d->supportedProfiles |= MEDIA_CD_ROM; 
+     if (d->deviceType & CDR) d->supportedProfiles |= MEDIA_CD_R; 
+     if (d->deviceType & CDRW) d->supportedProfiles |= MEDIA_CD_RW; 
+     if (d->deviceType & DVDR) d->supportedProfiles |= MEDIA_DVD_R_SEQ; 
+     if (d->deviceType & DVDRAM) d->supportedProfiles |= MEDIA_DVD_RAM; 
+     if (d->deviceType & DVD) d->supportedProfiles |= MEDIA_DVD_ROM; 
+     if (d->deviceType & DVDRW) d->supportedProfiles |= MEDIA_DVD_RW_OVWR | MEDIA_DVD_RW_SEQ;// ???
+     if (d->deviceType & DVDPR) d->supportedProfiles |= MEDIA_DVD_PLUS_R; 
+     if (d->deviceType & DVDPRW) d->supportedProfiles |= MEDIA_DVD_PLUS_RW; 
+  }    
+//            case 0x11: d->supportedProfiles |= MEDIA_DVD_R_SEQ;
+}
 
 bool K3bCdDevice::CdDevice::furtherInit()
 {
@@ -658,6 +710,7 @@
 
 K3bCdDevice::CdDevice::interface K3bCdDevice::CdDevice::interfaceType()
 {
+#ifndef __FreeBSD__
   if (d->interfaceType == OTHER)
   {
     // if the device is already opened we do not close it
@@ -680,6 +733,9 @@
     if( needToClose )
       close();
   }
+#else
+  d->interfaceType = SCSI;
+#endif
   return d->interfaceType;
 }
 
@@ -826,7 +882,11 @@
 
     unsigned char dvdheader[20];
     ::memset( dvdheader, 0, 20 );
+#ifndef __FreeBSD__
     ScsiCommand cmd( open() );
+#else
+    ScsiCommand cmd(m_passDevice);
+#endif  
     cmd[0] = 0xad;  // GPCMD_READ_DVD_STRUCTURE;
     cmd[9] = 20;
     if( cmd.transport( TR_DIR_READ, dvdheader, 20 ) ) {
@@ -846,6 +906,7 @@
 
 int K3bCdDevice::CdDevice::isReady() const
 {
+#ifndef __FreeBSD__
   // if the device is already opened we do not close it
   // to allow fast multible method calls in a row
   bool needToClose = !isOpen();
@@ -905,6 +966,10 @@
   }
   else
     return 2;
+#else
+  ((CdDevice *)this)->refreshDeviceData();
+  return m_driveReady;
+#endif
 }
 
 
@@ -941,6 +1006,7 @@
     delete [] data;
   }
   else {
+#ifndef __FreeBSD__
     kdDebug() << "(K3bCdDevice::CdDevice) " << blockDeviceName() 
 	      << ": READ DISC INFORMATION failed. falling back to cdrom.h" << endl;
     int drive_status = ::ioctl(d->deviceFd,CDROM_DRIVE_STATUS);
@@ -953,6 +1019,10 @@
       kdDebug() << "(K3bCdDevice::CdDevice) " << blockDeviceName() << ": No disk in drive" << endl;
       ret = NO_DISK;
     } 
+#else
+  ((CdDevice *)this)->refreshDeviceData();
+  ret = m_deviceStatus;
+#endif
   }
 
   if( needToClose )
@@ -1013,7 +1083,11 @@
   unsigned char header[2];
   ::memset( header, 0, 2 );
 
+#ifndef __FreeBSD__
   ScsiCommand cmd( open() );
+#else
+  ScsiCommand cmd(m_passDevice);
+#endif  
   cmd[0] = 0x51;   // READ DISC INFORMATION
   cmd[8] = 2;
 
@@ -1199,6 +1273,7 @@
   bool readSuccess = true;
 
   if( !readSectorsRaw( data, lba, 1 ) ) {
+#ifndef __FreeBSD__
     kdDebug() << "(K3bCdDevice::CdDevice) " << blockDeviceName()
 	      << ": MMC RAW READ failed. falling back to cdrom.h." << endl;
 
@@ -1209,8 +1284,11 @@
     if( ::ioctl(d->deviceFd,CDROMREADRAW,data) == -1 ) {
       kdDebug() << "(K3bCdDevice::CdDevice) " << blockDeviceName()
 		<< ": could not get track header, (lba " << lba << ") ! "  << strerror(errno) << endl;
+#endif
       readSuccess = false;
+#ifndef __FreeBSD__
     }
+#endif
   }
 
   if( readSuccess ) {
@@ -1556,7 +1634,7 @@
   bool success = true;
 
   toc.clear();
-
+#ifndef __FreeBSD__
   struct cdrom_tochdr tochdr;
   struct cdrom_tocentry tocentry;
 
@@ -1642,6 +1720,10 @@
   else
     success = false;
 
+#else
+    ((CdDevice *)this)->refreshDeviceData();
+    toc = m_toc;
+#endif
   return success;
 }
 
@@ -1653,7 +1735,7 @@
   bool needToClose = !isOpen();
 
   bool success = false;
-
+#ifndef __FreeBSD__
   if( open() != -1 ) {
     //
     // we probaly need to fixup the toc for multisession mixed-mode cds 
@@ -1681,7 +1763,7 @@
 	kdDebug() << "(K3bCdDevice::CdDevice) CDROMMULTISESSION failed." << endl;
     }
   }
-
+#endif
   if( needToClose )
     close();
 
@@ -1692,17 +1774,25 @@
 bool K3bCdDevice::CdDevice::block( bool b ) const
 {
   if( open() != -1 ) {
+#ifndef __FreeBSD__
     ScsiCommand cmd( open() );
+#else
+    ScsiCommand cmd(m_passDevice);
+#endif  
     cmd[0] = 0x1E;   // ALLOW MEDIA REMOVAL
     cmd[4] = b ? 0x1 : 0x0;
     int r = cmd.transport();
     if( r ) {
       kdDebug() << "(K3bCdDevice::CdDevice) MMC ALLOW MEDIA REMOVAL failed. Falling back to cdrom.h." << endl;
+#ifndef __FreeBSD__
       r = ::ioctl(d->deviceFd,CDROM_LOCKDOOR, b ? 1 : 0 );
+#else
+      r = ::ioctl(d->deviceFd,b ? CDIOCPREVENT : CDIOCALLOW);
+#endif
     }
 
     if( r )
-      kdDebug() << "(K3bCdDevice) Cannot block/unblock device " << devicename() << endl;
+      kdDebug() << "(K3bCdDevice) Cannot block/unblock device " << devicename() << ", errno: " << errno << endl;
 
     close();
     return ( r == 0 );
@@ -1724,22 +1814,36 @@
 
     return e;
   }
+#ifndef __FreeBSD__
   else
     return false;
+#else
+  ((CdDevice *)this)->refreshDeviceData();
+  return m_rewritableCd;
+#endif
 }
 
 bool K3bCdDevice::CdDevice::eject() const
 {
   block(false);
 
+#ifndef __FreeBSD__
   if( open() != -1 ) {
     ScsiCommand cmd( open() );
+#else
+  if( true ) {
+    ScsiCommand cmd(m_passDevice);
+#endif  
     cmd[0] = 0x1B;   // START/STOP UNIT
     cmd[4] = 0x2;    // LoEj = 1, Start = 0
     int r = cmd.transport();
     if( r ) {
       kdDebug() << "(K3bCdDevice::CdDevice) MMC START/STOP UNIT failed. Falling back to cdrom.h." << endl;
+#ifndef __FreeBSD__
       r = ::ioctl( d->deviceFd, CDROMEJECT );
+#else
+      r = bsd_open_close_device(m_bus, m_target, m_lun, true);
+#endif
     }
     
     close();
@@ -1752,14 +1856,23 @@
 
 bool K3bCdDevice::CdDevice::load() const
 {
+#ifndef __FreeBSD__
   if( open() != -1 ) {
     ScsiCommand cmd( open() );
+#else
+  if( true ) {
+    ScsiCommand cmd(m_passDevice);
+#endif  
     cmd[0] = 0x1B;   // START/STOP UNIT
     cmd[4] = 0x3;    // LoEj = 1, Start = 1
     int r = cmd.transport();
     if( r ) {
       kdDebug() << "(K3bCdDevice::CdDevice) MMC START/STOP UNIT failed. Falling back to cdrom.h." << endl;
+#ifndef __FreeBSD__
       r = ::ioctl( d->deviceFd, CDROMCLOSETRAY );
+#else
+      r = bsd_open_close_device(m_bus, m_target, m_lun, false);
+#endif
     }
     close();
     return (r == 0);
@@ -1793,7 +1906,7 @@
     d->deviceFd = openDevice( QFile::encodeName(devicename()) );
   if (d->deviceFd < 0)
   {
-    kdDebug() << "(K3bCdDevice) Error: could not open device." << endl;
+    kdDebug() << "(K3bCdDevice) Error: could not open device: " << QFile::encodeName(devicename()) << endl;
     d->deviceFd = -1;
   }
 
@@ -1915,7 +2028,11 @@
   unsigned char profileBuf[8];
   ::memset( profileBuf, 0, 8 );
 
+#ifndef __FreeBSD__
   ScsiCommand cmd( open() );
+#else
+  ScsiCommand cmd(m_passDevice);
+#endif  
   cmd[0] = 0x46;	// GET CONFIGURATION
   cmd[1] = 1;
   cmd[8] = 8;
@@ -1974,7 +2091,11 @@
     }
     inf.m_currentProfile = profile;
 
+#ifndef __FreeBSD__
     ScsiCommand cmd( open() );
+#else
+    ScsiCommand cmd(m_passDevice);
+#endif  
 
     if( inf.diskState() != STATE_NO_MEDIA ) {
 
@@ -2037,6 +2158,33 @@
 
 	delete [] data;
       }
+#ifdef __FreeBSD__
+      else
+      {
+         ((CdDevice *)this)->refreshDeviceData();
+         inf.m_rewritable = m_rewritableCd;
+         inf.m_numSessions = m_toc.size();
+         inf.m_capacity = m_discSize;
+         inf.m_remaining = m_remainingSize; 
+         inf.m_diskState = STATE_UNKNOWN;
+         inf.m_lastSessionState = STATE_UNKNOWN;
+         if (m_deviceStatus == EMPTY)
+         {
+           inf.m_diskState = STATE_EMPTY;
+           inf.m_lastSessionState = STATE_EMPTY;
+         }
+         else if (m_deviceStatus == APPENDABLE)
+         {
+           inf.m_diskState = STATE_INCOMPLETE;
+           inf.m_lastSessionState = STATE_INCOMPLETE;
+         }
+         else if (m_deviceStatus == COMPLETE)
+         {
+           inf.m_diskState = STATE_COMPLETE;
+           inf.m_lastSessionState = STATE_COMPLETE;
+         }
+      }
+#endif
 
       //
       // Now we determine the size:
@@ -2085,7 +2233,7 @@
 	  if( cmd.transport( TR_DIR_READ, trackHeader, 32 ) ) {
 	    kdDebug() << "(K3bCdDevice) READ_TRACK_INFORMATION failed." << endl;
 	    kdDebug() << "(K3bCdDevice) getting disk size via toc." << endl;
-	    
+#ifndef __FreeBSD__
 	    // TODO: use readToc!
 
 	    struct cdrom_tocentry tocentry;
@@ -2097,6 +2245,11 @@
 	      inf.m_capacity = tocentry.cdte_addr.lba;
 	      inf.m_capacity -= 1;  // we need the last sector of the last track, not the first from the lead-out
 	    }
+#else
+            ((CdDevice *)this)->refreshDeviceData();
+            inf.m_capacity = m_discSize;
+            inf.m_capacity -= 1;
+#endif
 	  }
 	  else {
 	    // not sure about this....
@@ -2160,7 +2313,11 @@
 
     unsigned char dvdheader[20];
     ::memset( dvdheader, 0, 20 );
+#ifndef __FreeBSD__
     ScsiCommand cmd( open() );
+#else
+    ScsiCommand cmd(m_passDevice);
+#endif  
     cmd[0] = 0xad;  // GPCMD_READ_DVD_STRUCTURE;
     cmd[9] = 20;
     if( cmd.transport( TR_DIR_READ, dvdheader, 20 ) ) {
@@ -2199,7 +2356,11 @@
 
     bool success = true;
 
+#ifndef __FreeBSD__
     ScsiCommand cmd( open() );
+#else
+    ScsiCommand cmd(m_passDevice);
+#endif  
     cmd[0] = 0x25;  // READ CAPACITY
     unsigned char buf[8];
     ::memset( buf, 0, 8 );
@@ -2236,7 +2397,11 @@
     unsigned char header[4]; // for reading the size of the returned data
     ::memset( header, 0, 4 );
 
+#ifndef __FreeBSD__
     ScsiCommand cmd( open() );
+#else
+    ScsiCommand cmd(m_passDevice);
+#endif  
     cmd[0] = 0x23;  // GPCMD_READ_FORMAT_CAPACITIES;
     cmd[8] = 4;
     if( cmd.transport( TR_DIR_READ, header, 4 ) == 0 ) {
@@ -2324,7 +2489,11 @@
   unsigned char header[8];
   ::memset( header, 0, 8 );
 
+#ifndef __FreeBSD__
   ScsiCommand cmd( open() );
+#else
+  ScsiCommand cmd(m_passDevice);
+#endif  
   cmd[0] = 0x5A;	// MODE SENSE
   cmd[1] = 0x08;        // Disable Block Descriptors
   cmd[2] = page;
@@ -2362,7 +2531,11 @@
 
   bool ret = false;
 
+#ifndef __FreeBSD__
   ScsiCommand cmd( open() );
+#else
+  ScsiCommand cmd(m_passDevice);
+#endif  
   cmd[0] = 0x55;	// MODE SELECT
   cmd[1] = ( sp ? 1 : 0 ) | ( pf ? 0x10 : 0 );
   cmd[7] = pageLen>>8;
@@ -2486,7 +2659,11 @@
   unsigned char header[2];
   ::memset( header, 0, 2 );
 
+#ifndef __FreeBSD__
   ScsiCommand cmd( open() );
+#else
+  ScsiCommand cmd(m_passDevice);
+#endif  
   cmd[0] = 0x43;  // READ TOC/PMA/ATIP
   cmd[1] = ( time ? 0x2 : 0x0 );
   cmd[2] = format & 0x0F;
@@ -2536,7 +2713,11 @@
   unsigned char header[8];
   ::memset( header, 0, 8 );
 
+#ifndef __FreeBSD__
   ScsiCommand cmd( open() );
+#else
+  ScsiCommand cmd(m_passDevice);
+#endif  
   cmd[0] = 0xbd;  // MECHANISM STATUS
   cmd[8] = 8;  // first we read the header
   if( cmd.transport( TR_DIR_READ, header, 8 ) == 0 ) {
@@ -2640,7 +2821,11 @@
 
   ::memset( data, 0, dataLen );
 
+#ifndef __FreeBSD__
   ScsiCommand cmd( open() );
+#else
+  ScsiCommand cmd(m_passDevice);
+#endif  
   cmd[0] = 0xbe;  // READ CD
   cmd[1] = (sectorType<<2 & 0x1c) | ( dap ? 0x2 : 0x0 );
   cmd[2] = startAdress>>24;
@@ -2668,3 +2853,363 @@
 
   return ret;
 }
+#ifdef __FreeBSD__
+void K3bDevice::CdDevice::refreshDeviceData()
+{
+    // was it called within the last 3 seconds?
+    QDateTime now = QDateTime::currentDateTime();
+    if (m_lastRefresh.isValid() && m_lastRefresh.secsTo(now) < 3)
+        return; // yes: use previous values
+    
+    m_driveReady = 0;
+    m_rewritableCd = 0;
+    m_discSize = 0;
+    m_remainingSize = 0;
+    m_deviceStatus = NO_INFO;
+    m_toc.clear();
+
+    KTempFile tmpfile;
+    tmpfile.setAutoDelete(true);
+
+    // call cdrecord -toc to get the toc and to detect empty disks
+    QString call = "/bin/sh -c \"cdrecord -toc " + QString("dev=%1").arg( busTargetLun() ) + " > " + tmpfile.name() + " 2>&1 \"";
+    kdDebug() << "(K3bCdDevice) Reading Toc : " << call << endl;
+    system(call.latin1());
+
+    // read tmp file line by line
+    K3bTrack lastTrack;
+    bool firstEntry = true;
+    QFile tmp (tmpfile.name());
+    if ( tmp.open( IO_ReadOnly ) )
+    {
+        QTextStream stream( &tmp );
+        bool done = false;
+        while ( !stream.eof() )
+        {
+            QString str = stream.readLine();
+            kdDebug() << "(K3bCdDevice): " << str << endl;
+            if (done)
+                continue;
+            // no disk inserted?
+            if ( str.startsWith( "cdrecord: No disk" ) )
+            {
+                m_driveReady = NO_DISK;
+                kdDebug() << "(K3bCdDevice) No Toc Data!" << endl;
+                // close and delete tmp file
+                tmp.close();
+                done = true;
+                continue;
+            }
+            // emoty disk inserted?
+            else if (str.startsWith("cdrecord: Cannot read TOC header"))
+            {
+               kdDebug() << "(K3bCdDevice) cd is empty" << endl;
+               m_driveReady = EMPTY;
+            }
+            // track data available?
+            if( str.startsWith("track:") ) 
+            {
+                    // cdrecord produces the following outout:
+                    // <tracknumber> lba: <startSector> (<...>) <startTime> adr: 1 control: <trackType> mode: <trackMode>
+                    // the last tracknumber will always be "lout", the leadout of the cd which we only use to determine the
+                    // length of the last track
+
+                    // we just want the startSector, the trackType, and the trackMode
+                    int start = 6; // skip the "track:"
+                    start = str.find(":", start )+1;
+                    int end = str.find( "(", start );
+
+                    bool ok;
+                    int startSec = str.mid( start, end-start ).toInt(&ok);
+                    if( ok ) 
+                    {
+                        start = str.find( "control:", start )+8; // skip the "control:"
+                        end = str.find("mode:", start );
+                        int control = str.mid( start, end-start ).toInt(&ok);
+                        if( ok ) 
+                        {
+                            start = end + 6;
+                            int mode = str.mid( start ).toInt(&ok);
+                            if( ok ) 
+                            {
+                              // all values have been determined
+                              // since we need the start of the next track to determine the length we save the values
+                              // in lastTrack and append the current lastTrack to the toc
+
+                              if( !firstEntry ) 
+                              {
+                                      m_toc.append( K3bTrack( lastTrack.firstSector(), startSec-1, lastTrack.type(), lastTrack.mode() ) );
+                                      kdDebug() << "(K3bCDDevice) Found track: first sector: " << lastTrack.firstSector().toString()
+                                                  << ", last sector: " << startSec-1 << ", type: " << lastTrack.type()
+                                                  << ", mode: " << lastTrack.mode()  << endl;
+                                      if (m_deviceStatus == EMPTY)
+                                                m_deviceStatus = APPENDABLE;
+                                      if( lastTrack.mode() == K3bTrack::MODE1 )
+                                                m_deviceStatus = COMPLETE;
+                              }
+                              // now this is the meaning of control and mode:
+                              // control (combination of the following)
+                              // 0x01 - Audio with preemp
+                              // 0x02 - Audio copy permitted
+                              // 0x04 - Data track
+                              // 0x08 - 4 channel audio
+
+                              // mode (only for data tracks)
+                              // 1 - Mode 1
+                              // 2 - Mode 2
+
+                              int trackType = 0;
+                              int trackMode = K3bTrack::UNKNOWN;
+                              if( control & 0x04 ) 
+                              {
+                                      trackType = K3bTrack::DATA;
+                                      if( mode == 1 )
+                                          trackMode = K3bTrack::MODE1;
+                                      else if( mode == 2 )
+                                          trackMode = K3bTrack::MODE2;
+                              }
+                              else
+                                      trackType = K3bTrack::AUDIO;
+
+                              lastTrack = K3bTrack( startSec, startSec, trackType, trackMode );
+                              firstEntry = false;
+                            }
+                            else 
+                            {
+                              kdDebug() << "(K3bCdDevice) Could not parse mode of track: " << str.mid( start ) << endl;
+                            }
+                        }
+                        else 
+                        {
+                            kdDebug() << "(K3bCdDevice) Could not parse control of track: " << str.mid( start, end-start ) << endl;
+                        }
+                    }
+                    else 
+                    {
+                        kdDebug() << "(K3bCdDevice) Could not parse start sector of track: " << str.mid( start, end-start) << endl;
+                    }
+            }
+
+        }
+        // close and delete tmp file
+        tmp.close();
+
+    }
+    // skip further tests if there is no disk
+    if (m_driveReady != NO_DISK && m_driveReady != NO_INFO)
+    {
+
+            KTempFile tmpfile2;
+            tmpfile2.setAutoDelete(true);
+            
+            // call cdrdao disk-info to get disk capacities, device status, and dsik type
+            call = "/bin/sh -c \"cdrdao disk-info --device " + QString("%1").arg( busTargetLun() ) + " --driver " + cdrdaoDriver() + " > " + tmpfile2.name() + " 2>&1 \"";
+            kdDebug() << "(K3bCdDevice) Reading remaining disk size : " << call << endl;
+            system(call.latin1());
+
+            // read tmp file line by line
+            QFile tmp2(tmpfile2.name());
+            if ( tmp2.open( IO_ReadOnly ) )
+            {
+                QTextStream stream( &tmp2 );
+                while ( !stream.eof() )
+                {
+                    QString str = stream.readLine();
+                    kdDebug() << "(K3bCdDevice): " << str << endl;
+                    
+                    // remaining capacity available?
+                    if ( str.contains( "Remaining Capacity   :" ) )
+                    {
+                        // cdrdao produces the following outout:
+                        // <remaining time> ( <remaining blocks> blocks, <remaining size> MB)
+
+                        int start = str.find("(" )+1;
+                        int end = str.find( " ", start );
+
+                        bool ok;
+                        int remaining = str.mid( start, end-start ).toInt(&ok);
+                        if( ok )
+                        {
+                           m_remainingSize = remaining-1;
+                        }
+                        else 
+                          kdDebug() << "(K3bCdDevice) Could not parse remaining time: " << str.mid( start, end-start) << endl;
+                    }
+                    
+                    // total capacity available?
+                    else if ( str.contains( "Total Capacity       :" ) )
+                    {
+                        // cdrdao produces the following outout:
+                        // <time> ( <blocks> blocks, <size> MB)
+
+                        int start = str.find("(" )+1;
+                        int end = str.find( " ", start );
+
+                        bool ok;
+                        int total = str.mid( start, end-start ).toInt(&ok);
+                        if( ok )
+                        {
+                                m_discSize = total-1;
+                        }
+                        else
+                                kdDebug() << "(K3bCdDevice) Could not parse total time: " << str.mid( start, end-start) << endl;
+                    }
+                    
+                    // is it an empty CD?
+                    else if (str.startsWith("CD-R empty           : yes"))
+                    {
+                            m_deviceStatus = EMPTY;
+                            kdDebug() << "(K3bCdDevice) device status: empty" << endl;
+                    }
+                    
+                    // is the last session closed?
+                    else if (str.startsWith("Appendable           : no"))
+                    {
+                            m_deviceStatus = COMPLETE;
+                            kdDebug() << "(K3bCdDevice) device status: complete" << endl;
+                    }
+                    
+                    // is the last session open?
+                    else if (str.startsWith("Appendable           : yes"))
+                    {
+                            m_deviceStatus = APPENDABLE;
+                            kdDebug() << "(K3bCdDevice) device status: appendable" << endl;
+                    }
+                    
+                    // is it a cd-rw?
+                    else  if (str.startsWith("CD-RW                : yes"))
+                    {
+                            kdDebug() << "(K3bCdDevice) cd is erasable" << endl;
+                            m_rewritableCd = 1;
+                    }
+
+                }
+                // close and delete tmp2 file
+                tmp2.close();
+            }
+    
+            if (m_discSize.toString() == "00:00:00") // cdrdao failed somehow
+            {
+    
+                KTempFile tmpfile3;
+                tmpfile3.setAutoDelete(true);
+
+                //create call
+                QString call = "/bin/sh -c \"cdrecord -atip " + QString("dev=%1").arg( busTargetLun() ) + " > " + tmpfile3.name() + " 2>&1 \"";
+                kdDebug() << "(K3bCdDevice) Reading disk size : " << call << endl;
+                system(call.latin1());
+
+                // read tmp file line by line
+                K3bTrack lastTrack;
+                QFile tmp3(tmpfile3.name());
+                if ( tmp3.open( IO_ReadOnly ) )
+                {
+                        QTextStream stream( &tmp3 );
+                        while ( !stream.eof() )
+                        {
+                                QString str = stream.readLine();
+                                if (str.startsWith("  Is erasable"))
+                                {
+                                        m_rewritableCd = 1;
+                                }
+                                else if( str.startsWith("  ATIP start of lead out:") ) 
+                                {
+                                        // cdrecord produces the following outout:
+                                        // <tracknumber> lba: <startSector> (<...>) <startTime> adr: 1 control: <trackType> mode: <trackMode>
+                                        // the last tracknumber will always be "lout", the leadout of the cd which we only use to determine the
+                                        // length of the last track
+
+                                        // we just want the startSector, the trackType, and the trackMode
+                                        int start = 6; // skip the "track:"
+                                        start = str.find(":", start )+1;
+                                        int end = str.find( "(", start )-1;
+
+                                        bool ok;
+                                        int leadOut = str.mid( start, end-start ).toInt(&ok);
+                                        if( ok )
+                                                m_discSize = leadOut;
+                                        else 
+                                                kdDebug() << "(K3bCdDevice) Could not parse lead out: " << str.mid( start, end-start) << endl;
+                                }
+
+                        }
+                        // close and delete tmp3 file
+                        tmp3.close();
+                }
+            }
+    
+    }
+
+    // print out cd data
+    kdDebug() << "(K3bCdDevice) disk size: " << m_discSize.toString() << endl;
+    kdDebug() << "(K3bCdDevice) remaining size: " << m_remainingSize.toString() << endl;
+    kdDebug() << "(K3bCdDevice) total size: " << m_discSize.toString() << endl;
+    kdDebug() << "(K3bCdDevice) drive ready: " << m_driveReady << endl;
+
+    if (m_deviceStatus == EMPTY)
+            kdDebug() << "(K3bCdDevice) device status: empty" << endl;
+    else if (m_deviceStatus == APPENDABLE)
+            kdDebug() << "(K3bCdDevice) device status: appendable" << endl;
+    else if (m_deviceStatus == COMPLETE)
+            kdDebug() << "(K3bCdDevice) device status: complete" << endl;
+    else if (m_deviceStatus == NO_DISK)
+            kdDebug() << "(K3bCdDevice) device status: no disk" << endl;
+    else if (m_deviceStatus == NO_INFO)
+            kdDebug() << "(K3bCdDevice) device status: no info" << endl;
+    if (m_rewritableCd)
+            kdDebug() << "(K3bCdDevice) cd is erasable" << endl;
+    else
+            kdDebug() << "(K3bCdDevice) cd is not erasable" << endl;
+
+    // reset timer
+    m_lastRefresh = QDateTime::currentDateTime();
+}
+
+void K3bDevice::CdDevice::addDeviceType(DeviceType type)
+{
+    d->deviceType |= type;
+}
+
+int bsd_open_close_device(int bus, int target, int lun, bool eject)
+{
+        union ccb *ccb;
+	int error = 0;
+        struct cam_device *cam_dev = cam_open_btl(bus, target, lun, O_RDWR, NULL);
+	ccb = cam_getccb(cam_dev);
+        bool startstop = false;
+	scsi_start_stop(&ccb->csio, 1, NULL, startstop ? MSG_SIMPLE_Q_TAG :MSG_ORDERED_Q_TAG, startstop,
+		eject, 0, SSD_FULL_SIZE, 120000);
+	ccb->ccb_h.flags |= CAM_DEV_QFRZDIS;
+	if (cam_send_ccb(cam_dev, ccb) < 0) {
+		perror("error sending start unit");
+
+		cam_freeccb(ccb);
+		return(1);
+	}
+
+	if ((ccb->ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP)
+		if (startstop) 
+                {
+			kdDebug() << "(K3bCdDevice) bsd_open_close_device: Unit started successfully" << endl;
+			if (eject)
+				kdDebug() << "(K3bCdDevice) bsd_open_close_device: Media loaded" << endl;
+		} 
+                else 
+                {
+			kdDebug() << "(K3bCdDevice) bsd_open_close_device: Unit stopped successfully" << endl;
+			if (eject)
+				kdDebug() << "(K3bCdDevice) bsd_open_close_device: Media ejected" << endl;
+		}
+	else 
+        {
+		error = 1;
+		if (startstop)
+			kdDebug() << "(K3bCdDevice) bsd_open_close_device: Error received from start unit command" << endl;
+		else
+			kdDebug() << "(K3bCdDevice) bsd_open_close_device: Error received from stop unit command" << endl;
+	}
+	cam_freeccb(ccb);
+	return error;
+}
+
+#endif
