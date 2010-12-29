--- xbmc/utils/IoSupport.cpp.orig	2010-07-11 22:11:12.000000000 +0200
+++ xbmc/utils/IoSupport.cpp	2010-12-13 21:20:19.000000000 +0100
@@ -31,7 +31,7 @@
 #include "WIN32Util.h"
 #include "CharsetConverter.h"
 #endif
-#if defined (_LINUX) && !defined(__APPLE__)
+#if defined (_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <linux/limits.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
@@ -53,6 +53,9 @@
 #include <IOKit/storage/IODVDMediaBSDClient.h>
 #include <IOKit/storage/IOStorageDeviceCharacteristics.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/syslimits.h>
+#endif
 #include "../FileSystem/cdioSupport.h"
 #include "../FileSystem/iso9660.h"
 #include "../MediaManager.h"
@@ -297,7 +300,7 @@
 #ifdef _XBOX
   HalWriteSMBusValue(0x20, 0x0C, FALSE, 1);  // close tray
 #endif
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   // FIXME...
 #elif defined(_LINUX)
   char* dvdDevice = CLibcdio::GetInstance()->GetDeviceFileName();
@@ -496,6 +499,8 @@
     return -1;
   }
   return MODE2_DATA_SIZE;
+#elif defined(__FreeBSD__)
+  // TODO
 #elif defined(_LINUX)
   if (hDevice->m_bCDROM)
   {
