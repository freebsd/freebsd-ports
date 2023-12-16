--- src/settings/autostartmanager/abstractautostartmanager.cpp.orig	2023-10-14 14:48:26 UTC
+++ src/settings/autostartmanager/abstractautostartmanager.cpp
@@ -18,7 +18,7 @@
  */
 
 #include "abstractautostartmanager.h"
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
 #include "portalautostartmanager.h"
 #include "unixautostartmanager.h"
 #elif defined(Q_OS_DARWIN)
@@ -36,7 +36,7 @@ AbstractAutostartManager *AbstractAutostartManager::cr
 
 AbstractAutostartManager *AbstractAutostartManager::createAutostartManager(QObject *parent)
 {
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
     if (PortalAutostartManager::isAvailable())
         return new PortalAutostartManager(parent);
     return new UnixAutostartManager(parent);
