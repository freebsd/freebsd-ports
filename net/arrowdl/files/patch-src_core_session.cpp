--- src/core/session.cpp.orig	2025-03-23 11:56:15 UTC
+++ src/core/session.cpp
@@ -255,7 +255,7 @@ void Session::read(QList<AbstractJob *> &jobs,
 {
     QFile file(filename);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
-        qWarning("Couldn't open file.");
+        qWarning("Couldn't open file %s", filename.toStdString().c_str());
         return;
     }
     QByteArray saveData = file.readAll();
@@ -275,7 +275,7 @@ void Session::write(const QList<AbstractJob *> &jobs, 
     QFile file(filename);
 
     if (!file.open(QIODevice::WriteOnly)) {
-        qWarning("Couldn't open save file.");
+        qWarning("Couldn't open save file %s", filename.toStdString().c_str());
         return;
     }
 
