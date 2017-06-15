--- gui/src/mainwindow.cpp.orig	2012-12-03 07:13:07 UTC
+++ gui/src/mainwindow.cpp
@@ -426,7 +426,7 @@ void QPxToolMW::selectTab()
 	int idx;
 	QAction *act = (QAction*) sender();
 	idx = act_sblist.indexOf(act);
-	if (act<0) return;
+	if (idx<0) return;
 	mwidget->selectTab(idx);
 }
 
