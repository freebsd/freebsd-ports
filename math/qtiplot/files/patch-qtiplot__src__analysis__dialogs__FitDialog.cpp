--- qtiplot/src/analysis/dialogs/FitDialog.cpp.orig	2011-10-17 10:38:07 UTC
+++ qtiplot/src/analysis/dialogs/FitDialog.cpp
@@ -101,7 +101,7 @@ FitDialog::FitDialog(Graph *g, QWidget* 
 	ApplicationWindow *app = (ApplicationWindow *)parent;
 	QString pluginsPath = app->fitPluginsPath;
 	QFileInfo fi(pluginsPath);
-	if (pluginsPath.isEmpty() || !fi.isDir() || !fi.isWritable())
+	if (pluginsPath.isEmpty() || !fi.isDir())
 		choosePluginsFolder();
 	else
     	loadPlugins();
@@ -1019,11 +1019,7 @@ void FitDialog::showFitPage()
 	int prec = boxPrecision->value();
     for (int i = 0; i<parameters; i++){
         QTableWidgetItem *it = new QTableWidgetItem(paramList[i]);
-#ifdef Q_CC_MSVC
         it->setFlags(it->flags() & (~Qt::ItemIsEditable));
-#else
-        it->setFlags(!Qt::ItemIsEditable);
-#endif
         it->setBackground(QBrush(Qt::lightGray));
         it->setForeground(Qt::black);
         QFont font = it->font();
@@ -1049,7 +1045,7 @@ void FitDialog::showFitPage()
         boxParams->setCellWidget(i, 2, sb);
 
         it = new QTableWidgetItem();
-		it->setFlags(!Qt::ItemIsEditable);
+		it->setFlags(it->flags() & (~Qt::ItemIsEditable));
 		it->setText("--");
 		boxParams->setItem(i, 5, it);
 	}
@@ -1061,11 +1057,7 @@ void FitDialog::showFitPage()
         boxParams->showColumn(4);
 		for (int i = 0; i<boxParams->rowCount(); i++ ){
             QTableWidgetItem *it = new QTableWidgetItem();
-#ifdef Q_CC_MSVC
             it->setFlags(it->flags() & (~Qt::ItemIsEditable));
-#else
-            it->setFlags(!Qt::ItemIsEditable);
-#endif
             it->setBackground(QBrush(Qt::lightGray));
             boxParams->setItem(i, 4, it);
 
