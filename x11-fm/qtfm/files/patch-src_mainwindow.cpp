--- src/mainwindow.cpp.orig	2012-03-11 10:11:28.000000000 -0500
+++ src/mainwindow.cpp	2012-04-29 23:06:06.481938775 -0500
@@ -21,7 +21,11 @@
 
 
 #include <QtGui>
+#ifdef __FreeBSD__
+#include <sys/mount.h>
+#else
 #include <sys/vfs.h>
+#endif
 #include <fcntl.h>
 
 #include "mainwindow.h"
@@ -280,10 +284,15 @@ void MainWindow::lateStart()
     customMapper = new QSignalMapper();
     connect(customMapper, SIGNAL(mapped(QString)),this, SLOT(actionMapper(QString)));
 
+#ifdef __FreeBSD__
+    worker = new MountWorker();
+    worker->setParent(this);
+    worker->start(QThread::IdlePriority);
+#else
     int fd = open("/proc/self/mounts",O_RDONLY,0);
     notify = new QSocketNotifier(fd,QSocketNotifier::Write);
     connect(notify, SIGNAL(activated(int)), this, SLOT(mountWatcherTriggered()),Qt::QueuedConnection);
-
+#endif
 
     term = settings->value("term").toString();
     progress = 0;
@@ -336,6 +345,9 @@ void MainWindow::closeEvent(QCloseEvent 
 {
     writeSettings();
 
+#ifdef __FreeBSD__
+    worker->close();
+#endif
     if(isDaemon)
     {
         this->setVisible(0);
@@ -1839,7 +1851,7 @@ void MainWindow::actionMapper(QString cm
     QString exec = temp.at(0);
     temp.removeAt(0);
 
-    temp.replaceInStrings("\\","\ ");
+    temp.replaceInStrings("\\"," ");
 
     QProcess *customProcess = new QProcess();
     customProcess->setWorkingDirectory(pathEdit->itemText(0));
