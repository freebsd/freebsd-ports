--- qtiplot/src/core/ConfigDialog.cpp.orig	2011-10-25 09:50:22 UTC
+++ qtiplot/src/core/ConfigDialog.cpp
@@ -1390,7 +1390,7 @@ void ConfigDialog::setColorsList(const Q
 	colorsList->setRowCount(colors);
 	for (int i = 0; i < colors; i++){
 		QTableWidgetItem *it = new QTableWidgetItem();
-		it->setFlags(!Qt::ItemIsEditable);
+		it->setFlags(it->flags() & (~Qt::ItemIsEditable));
 		it->setBackground(QBrush(colList[i]));
 		colorsList->setItem(i, 0, it);
 
