--- src/stream_widget.cpp.orig	2017-03-11 22:16:36 UTC
+++ src/stream_widget.cpp
@@ -58,7 +58,7 @@ StreamWidget::StreamWidget(QProcess* rclone, QProcess*
         }
     });
 
-    QObject::connect(mRclone, static_cast<void(QProcess::*)(int)>(&QProcess::finished), this, [=]()
+    QObject::connect(mRclone, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [=]()
     {
         mRclone->deleteLater();
         mRunning = false;
