--- src/device/k3bdevice.cpp.orig	Thu Feb 12 11:21:15 2004
+++ src/device/k3bdevice.cpp	Fri Feb 13 21:03:38 2004
@@ -56,6 +56,12 @@
 
 #endif // Q_OS_LINUX
 
+#ifdef __FreeBSD__
+#define __BYTE_ORDER BYTE_ORDER
+#define __BIG_ENDIAN BIG_ENDIAN
+#define CD_FRAMESIZE_RAW 2352
+#endif
+
 
 #ifdef HAVE_RESMGR
 extern "C" {
@@ -152,8 +158,10 @@
 
   d->supportedProfiles = 0;
 
+#ifndef __FreeBSD__
   if(open() < 0)
     return false;
+#endif
 
 
   //
