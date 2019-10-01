--- src/job_widget.cpp.orig	2017-03-11 22:16:36 UTC
+++ src/job_widget.cpp
@@ -162,7 +162,7 @@ JobWidget::JobWidget(QProcess* process, const QString&
         }
     });
 
-    QObject::connect(mProcess, static_cast<void(QProcess::*)(int)>(&QProcess::finished), this, [=](int status)
+    QObject::connect(mProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [=](int status)
     {
         mProcess->deleteLater();
         for (auto label : mActive)
