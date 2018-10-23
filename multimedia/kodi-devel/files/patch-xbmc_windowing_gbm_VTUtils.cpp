--- xbmc/windowing/gbm/VTUtils.cpp.orig	2018-10-23 13:12:16 UTC
+++ xbmc/windowing/gbm/VTUtils.cpp
@@ -12,12 +12,14 @@
 #include "utils/log.h"
 #include "utils/StringUtils.h"
 
+#ifdef __linux__
 #include <linux/major.h>
 #include <linux/kd.h>
 #include <linux/vt.h>
+#include <sys/sysmacros.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/stat.h>
-#include <sys/sysmacros.h>
 
 using namespace KODI::WINDOWING::GBM;
 
@@ -26,13 +28,14 @@ bool CVTUtils::OpenTTY()
   m_ttyDevice = ttyname(STDIN_FILENO);
 
   m_fd.attach(open(m_ttyDevice.c_str(), O_RDWR | O_CLOEXEC));
-  if (m_fd < 0)
+  if (static_cast<int>(m_fd) < 0)
   {
     CMessagePrinter::DisplayError(StringUtils::Format("ERROR: failed to open tty: %s",  m_ttyDevice));
     CLog::Log(LOGERROR, "CVTUtils::%s - failed to open tty: %s", __FUNCTION__, m_ttyDevice);
     return false;
   }
 
+#ifdef __linux__
   struct stat buf;
   if (fstat(m_fd, &buf) == -1 || major(buf.st_rdev) != TTY_MAJOR || minor(buf.st_rdev) == 0)
   {
@@ -55,7 +58,7 @@ bool CVTUtils::OpenTTY()
     CLog::Log(LOGERROR, "CVTUtils::%s - %s is already in graphics mode, is another display server running?", __FUNCTION__, m_ttyDevice);
     return false;
   }
-
+#endif
   CLog::Log(LOGNOTICE, "CVTUtils::%s - opened tty: %s", __FUNCTION__, m_ttyDevice.c_str());
 
   return true;
