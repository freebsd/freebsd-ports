--- ./qtiplot/src/analysis/dialogs/FitDialog.cpp.orig	2009-03-05 15:57:04.000000000 +0300
+++ ./qtiplot/src/analysis/dialogs/FitDialog.cpp	2009-03-27 14:20:44.000000000 +0300
@@ -119,7 +119,7 @@
 	ApplicationWindow *app = (ApplicationWindow *)parent;
 	QString pluginsPath = app->fitPluginsPath;
 	QFileInfo fi(pluginsPath);
-	if (pluginsPath.isEmpty() || !fi.isDir() || !fi.isWritable())
+	if (pluginsPath.isEmpty() || !fi.isDir())
 		choosePluginsFolder();
 	else
     	loadPlugins();
