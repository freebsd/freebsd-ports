--- Linphone/tool/native/DesktopTools.hpp.orig
+++ Linphone/tool/native/DesktopTools.hpp
@@ -20,7 +20,7 @@
 
 #include <QtGlobal>
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #include "DesktopToolsLinux.hpp"
 #elif defined(Q_OS_WIN)
 #include "DesktopToolsWindows.hpp"
