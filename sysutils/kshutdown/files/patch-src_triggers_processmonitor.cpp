--- src/triggers/processmonitor.cpp.orig	2018-12-26 12:42:28 UTC
+++ src/triggers/processmonitor.cpp
@@ -28,6 +28,7 @@
 	#include <csignal> // for ::kill
 #endif // !Q_OS_WIN32
 
+#include <errno.h>
 // public
 
 Process::Process(QObject *parent, const QString &command)
