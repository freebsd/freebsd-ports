--- src/device/k3bdevice.cpp.orig	Wed Jun 23 12:06:46 2004
+++ src/device/k3bdevice.cpp	Sun Jul 11 12:24:22 2004
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
@@ -153,8 +160,10 @@
 
   d->supportedProfiles = 0;
 
+#ifndef __FreeBSD__
   if(open() < 0)
     return false;
+#endif
 
 
   //
@@ -193,6 +202,7 @@
   unsigned char header[2048];
   ::memset( header, 0, 2048 );
 
+  cmd.clear();
   cmd[0] = MMC::GET_CONFIGURATION;
   cmd[8] = 8;
   if( cmd.transport( TR_DIR_READ, header, 8 ) ) {
@@ -769,6 +779,14 @@
       m_bufferSize = 1024;
       d->burnfree = false;
     }
+    else if( description().startsWith("CD-R56S") ) {
+      m_writeModes |= TAO;
+      d->deviceType |= CDROM|CDR;
+      m_maxWriteSpeed = 6;
+      m_maxReadSpeed = 24;
+      m_bufferSize = 1302;
+      d->burnfree = false;
+    }
   }
   else if( vendor().startsWith("HP") ) {
     if( description().startsWith("CD-Writer 6020") ) {
@@ -2559,10 +2577,12 @@
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
@@ -2648,13 +2668,16 @@
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
 
