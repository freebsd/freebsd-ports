--- src/device/k3bdevice.cpp.orig	Sun Nov 28 01:22:29 2004
+++ src/device/k3bdevice.cpp	Sun Jan  2 09:30:08 2005
@@ -57,6 +57,13 @@
 
 #endif // Q_OS_LINUX
 
+#ifdef __FreeBSD__
+#define __BYTE_ORDER BYTE_ORDER
+#define __BIG_ENDIAN BIG_ENDIAN
+#define CD_FRAMESIZE_RAW 2352
+#define nearbyint(x) rint(x)
+#endif
+
 
 #ifdef HAVE_RESMGR
 extern "C" {
@@ -188,8 +195,10 @@
 
   d->supportedProfiles = 0;
 
+#ifndef __FreeBSD__
   if(open() < 0)
     return false;
+#endif
 
 
   //
@@ -228,6 +237,7 @@
   unsigned char header[2048];
   ::memset( header, 0, 2048 );
 
+  cmd.clear();
   cmd[0] = MMC::GET_CONFIGURATION;
   cmd[8] = 8;
   if( cmd.transport( TR_DIR_READ, header, 8 ) ) {
@@ -820,6 +830,24 @@
     m_bufferSize = 1024;
     d->burnfree = false;
   }
+  else if( vendor().startsWith("TEAC") ) { 
+    if( description().startsWith("CD-R56S") ) {
+      m_writeModes |= TAO;
+      d->deviceType |= CDROM|CDR;
+      m_maxWriteSpeed = 6;
+      m_maxReadSpeed = 24;
+      m_bufferSize = 1302;
+      d->burnfree = false;
+    }
+    if( description().startsWith("CD-R58S") ) {
+      m_writeModes |= TAO;
+      d->deviceType |= CDROM|CDR;
+      m_maxWriteSpeed = 8;
+      m_maxReadSpeed = 24;
+      m_bufferSize = 4096;
+      d->burnfree = false;
+    }
+  }
   else if( vendor().startsWith("MATSHITA") ) {
     if( description().startsWith("CD-R   CW-7501") ) {
       m_writeModes = TAO|SAO;
@@ -2663,10 +2691,12 @@
 {
   // if the device is already opened we do not close it
   // to allow fast multible method calls in a row
+#ifndef __FreeBSD__
   bool needToClose = !isOpen();
 
   if (open() < 0)
     return;
+#endif
 
   // header size is 8
   unsigned char* buffer = 0;
@@ -2752,13 +2782,16 @@
     delete [] buffer;
   }
     
+#ifndef __FreeBSD__
   if( needToClose )
     close();
+#endif
 }
 
 
 bool K3bCdDevice::CdDevice::readTocPmaAtip( unsigned char** data, int& dataLen, int format, bool time, int track ) const
 {
+  kdDebug() << "(K3bCdDevice::CdDevice) readTocPmaAtip started,  format:" << format << ", time: " << time << ", track: " << track << endl;
   unsigned char header[2048];
   ::memset( header, 0, 2048 );
 
