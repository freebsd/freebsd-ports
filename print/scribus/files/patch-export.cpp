--- scribus/plugins/pixmapexport/export.cpp.orig	Mon Jun  7 01:15:14 2004
+++ scribus/plugins/pixmapexport/export.cpp	Mon Jun  7 01:18:23 2004
@@ -116,7 +116,7 @@
 				QObject::tr("No"),
 				QObject::tr("Yes"),
 				// hack for multiple overwritting (petr)
-				(single==TRUE) ? 0 : QObject::tr("Yes all"),
+				(single==TRUE) ? QString::null : QObject::tr("Yes all"),
 				0, 0);
 		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
 		if (over == 1)
