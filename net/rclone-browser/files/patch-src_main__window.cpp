--- src/main_window.cpp.orig	2017-03-11 22:16:36 UTC
+++ src/main_window.cpp
@@ -193,7 +193,7 @@ void MainWindow::rcloneGetVersion()
 
     QProcess* p = new QProcess();
 
-    QObject::connect(p, static_cast<void(QProcess::*)(int)>(&QProcess::finished), this, [=](int code)
+    QObject::connect(p, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [=](int code)
     {
         if (code == 0)
         {
@@ -241,7 +241,7 @@ void MainWindow::rcloneConfig()
 {
     QProcess* p = new QProcess(this);
 
-    QObject::connect(p, static_cast<void(QProcess::*)(int)>(&QProcess::finished), this, [=](int code)
+    QObject::connect(p, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [=](int code)
     {
         if (code == 0)
         {
@@ -297,7 +297,7 @@ void MainWindow::rcloneListRemotes()
 
     QProcess* p = new QProcess();
 
-    QObject::connect(p, static_cast<void(QProcess::*)(int)>(&QProcess::finished), this, [=](int code)
+    QObject::connect(p, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [=](int code)
     {
         if (code == 0)
         {
@@ -570,7 +570,7 @@ void MainWindow::addStream(const QString& remote, cons
     auto rclone = new QProcess();
     rclone->setStandardOutputProcess(player);
 
-    QObject::connect(player, static_cast<void(QProcess::*)(int)>(&QProcess::finished), this, [=](int status)
+    QObject::connect(player, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [=](int status)
     {
         player->deleteLater();
         if (status != 0 && player->error() == QProcess::FailedToStart)
