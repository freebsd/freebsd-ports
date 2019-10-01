--- src/mount_widget.cpp.orig	2017-03-11 22:16:36 UTC
+++ src/mount_widget.cpp
@@ -57,7 +57,7 @@ MountWidget::MountWidget(QProcess* process, const QStr
         }
     });
 
-    QObject::connect(mProcess, static_cast<void(QProcess::*)(int)>(&QProcess::finished), this, [=](int status)
+    QObject::connect(mProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [=](int status)
     {
         mProcess->deleteLater();
         mRunning = false;
