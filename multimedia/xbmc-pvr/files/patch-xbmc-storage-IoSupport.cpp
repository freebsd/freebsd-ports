--- xbmc/storage/IoSupport.cpp.orig
+++ xbmc/storage/IoSupport.cpp
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
@@ -226,7 +229,7 @@ HRESULT CIoSupport::EjectTray( const boo
 HRESULT CIoSupport::CloseTray()
 {
 #ifdef HAS_DVD_DRIVE
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   // FIXME...
 #elif defined(_LINUX)
   char* dvdDevice = CLibcdio::GetInstance()->GetDeviceFileName();
@@ -402,6 +405,8 @@ INT CIoSupport::ReadSectorMode2(HANDLE h
     return -1;
   }
   return MODE2_DATA_SIZE;
+#elif defined(__FreeBSD__)
+  // TODO
 #elif defined(_LINUX)
   if (hDevice->m_bCDROM)
   {
