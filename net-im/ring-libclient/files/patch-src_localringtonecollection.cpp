--- src/localringtonecollection.cpp.orig	2016-05-19 17:41:40 UTC
+++ src/localringtonecollection.cpp
@@ -115,7 +115,7 @@ bool LocalRingtoneCollection::load()
       qWarning() << "Ringtones doesn't exist or is not readable";
 
 //TODO remove that and do a proper collection for each platforms
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
    QDir ringtonesDir(QFileInfo(QCoreApplication::applicationFilePath()).path()+"/../share/ring/ringtones/");
 #elif defined(Q_OS_WIN)
    QDir ringtonesDir(QFileInfo(QCoreApplication::applicationFilePath()).path()+"/ringtones/");
