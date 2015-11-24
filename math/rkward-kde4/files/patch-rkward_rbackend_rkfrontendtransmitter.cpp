--- rkward/rbackend/rkfrontendtransmitter.cpp.orig	2015-01-15 13:37:21 UTC
+++ rkward/rbackend/rkfrontendtransmitter.cpp
@@ -41,7 +41,7 @@ QString findBackendAtPath (const QString
 #ifdef Q_WS_WIN
 	QString ret = dir.filePath ("rkward.rbackend.exe");
 #else
-	QString ret = dir.filePath ("rkward.rbackend");
+	QString ret = "%%PREFIX%%/lib/kde4/libexec/rkward.rbackend";
 #endif
 	RK_DEBUG (RBACKEND, DL_DEBUG, "Looking for backend at %s", qPrintable (ret));
 	QFileInfo fi (ret);
