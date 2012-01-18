--- ./xbmc/storage/IoSupport.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/storage/IoSupport.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -30,7 +30,7 @@
 #include "WIN32Util.h"
 #include "utils/CharsetConverter.h"
 #endif
-#if defined (_LINUX) && !defined(__APPLE__)
+#if defined (_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <linux/limits.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
@@ -54,6 +54,9 @@
 #include <IOKit/storage/IOStorageDeviceCharacteristics.h>
 #endif
 #endif
+#ifdef __FreeBSD__
+#include <sys/syslimits.h>
+#endif
 #include "cdioSupport.h"
 #include "filesystem/iso9660.h"
 #include "MediaManager.h"
@@ -228,6 +231,8 @@
 #ifdef HAS_DVD_DRIVE
 #ifdef __APPLE__
   // FIXME...
+#elif defined(__FreeBSD__)
+  // NYI
 #elif defined(_LINUX)
   char* dvdDevice = CLibcdio::GetInstance()->GetDeviceFileName();
   if (strlen(dvdDevice) != 0)
@@ -402,6 +407,8 @@
     return -1;
   }
   return MODE2_DATA_SIZE;
+#elif defined(__FreeBSD__)
+  // NYI
 #elif defined(_LINUX)
   if (hDevice->m_bCDROM)
   {
