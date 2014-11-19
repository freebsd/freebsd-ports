--- rkward/rbackend/rkfrontendtransmitter.cpp.orig	2014-10-13 21:22:11.000000000 +0200
+++ rkward/rbackend/rkfrontendtransmitter.cpp	2014-10-31 22:13:56.000000000 +0100
@@ -41,7 +41,7 @@
 #ifdef Q_WS_WIN
 	QString ret = dir.filePath ("rkward.rbackend.exe");
 #else
-	QString ret = dir.filePath ("rkward.rbackend");
+	QString ret = "%%PREFIX%%/lib/kde4/libexec/rkward.rbackend";
 #endif
 	RK_DEBUG (RBACKEND, DL_DEBUG, "Looking for backend at %s", qPrintable (ret));
 	QFileInfo fi (ret);
