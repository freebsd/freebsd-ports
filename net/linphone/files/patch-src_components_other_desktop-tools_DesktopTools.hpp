--- src/components/other/desktop-tools/DesktopTools.hpp.orig	2022-07-05 13:20:17 UTC
+++ src/components/other/desktop-tools/DesktopTools.hpp
@@ -23,7 +23,7 @@
 
 #include <QtGlobal>
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
   #include "DesktopToolsLinux.hpp"
 #elif defined(Q_OS_WIN)
   #include "DesktopToolsWindows.hpp"
