--- ./src/wizard.cpp.orig	2013-04-06 21:25:09.000000000 +0200
+++ ./src/wizard.cpp	2013-06-07 14:37:07.694597426 +0200
@@ -499,8 +499,8 @@
     QTreeWidgetItem *item = new QTreeWidgetItem(m_check.programList, QStringList() << QString() << i18n("FFmpeg & ffplay"));
     item->setData(1, Qt::UserRole, i18n("Required for proxy clips, transcoding and screen capture"));
     item->setSizeHint(0, itemSize);
-    QString exepath = KStandardDirs::findExe("ffmpeg");
-    QString playpath = KStandardDirs::findExe("ffplay");
+    QString exepath = KStandardDirs::findExe(QString("ffmpeg%1").arg(FFMPEG_SUFFIX));
+    QString playpath = KStandardDirs::findExe(QString("ffplay%1").arg(FFMPEG_SUFFIX));
     item->setIcon(0, m_okIcon);
     if (exepath.isEmpty()) {
 	// Check for libav version
