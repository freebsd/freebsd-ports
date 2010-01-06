--- ./qtiplot/src/analysis/dialogs/FitDialog.cpp.orig	2009-10-18 10:44:45.000000000 +0400
+++ ./qtiplot/src/analysis/dialogs/FitDialog.cpp	2009-10-18 18:54:12.000000000 +0400
@@ -119,7 +119,7 @@
 	ApplicationWindow *app = (ApplicationWindow *)parent;
 	QString pluginsPath = app->fitPluginsPath;
 	QFileInfo fi(pluginsPath);
-	if (pluginsPath.isEmpty() || !fi.isDir() || !fi.isWritable())
+	if (pluginsPath.isEmpty() || !fi.isDir())
 		choosePluginsFolder();
 	else
     	loadPlugins();
