--- qtiplot/src/lib/src/ColorMapEditor.cpp.orig	2011-07-02 07:23:52 UTC
+++ qtiplot/src/lib/src/ColorMapEditor.cpp
@@ -155,11 +155,7 @@ void ColorMapEditor::setColorMap(const L
 		QColor c = color_map.color(i);
 
 		QTableWidgetItem *it = new QTableWidgetItem(c.name());
-	#ifdef Q_CC_MSVC
 		it->setFlags(it->flags() & (~Qt::ItemIsEditable));
-	#else
-		it->setFlags(!Qt::ItemIsEditable);
-	#endif
 		it->setBackground(QBrush(c));
 		it->setForeground(QBrush(c));
 		table->setItem(i, 1, it);
@@ -246,11 +242,7 @@ void ColorMapEditor::insertLevel()
     table->setCellWidget(row, 0, sb);
 
 	QTableWidgetItem *it = new QTableWidgetItem(c.name());
-#ifdef Q_CC_MSVC
 	it->setFlags(it->flags() & (~Qt::ItemIsEditable));
-#else
-	it->setFlags(!Qt::ItemIsEditable);
-#endif
 	it->setBackground(QBrush(c));
 	it->setForeground(QBrush(c));
 	table->setItem(row, 1, it);
