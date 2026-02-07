--- engine/src/qlcfile.cpp.orig	2023-06-30 07:50:19 UTC
+++ engine/src/qlcfile.cpp
@@ -209,7 +209,7 @@ QDir QLCFile::userDirectory(QString path, QString fall
     Q_UNUSED(fallBackPath)
     QDir dir;
 
-#if defined(Q_WS_X11) || defined(Q_OS_LINUX)
+#if defined(Q_WS_X11) || defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     // If the current user is root, return the system fixture dir.
     // Otherwise return a path under user's home dir.
     if (geteuid() == 0 && QLCFile::hasWindowManager())
