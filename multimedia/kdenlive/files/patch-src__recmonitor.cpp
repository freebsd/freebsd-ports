--- ./src/recmonitor.cpp.orig	2013-04-06 21:25:09.000000000 +0200
+++ ./src/recmonitor.cpp	2013-06-05 15:37:14.742805014 +0200
@@ -269,7 +269,7 @@
         m_stopAction->setEnabled(false);
         m_playAction->setEnabled(false);
 	if (KdenliveSettings::ffmpegpath().isEmpty()) {
-	    QString exepath = KStandardDirs::findExe("ffmpeg");
+	    QString exepath = KStandardDirs::findExe(QString("ffmpeg%1").arg(FFMPEG_SUFFIX));
 	    if (exepath.isEmpty()) {
 		// Check for libav version
 		exepath = KStandardDirs::findExe("avconv");
