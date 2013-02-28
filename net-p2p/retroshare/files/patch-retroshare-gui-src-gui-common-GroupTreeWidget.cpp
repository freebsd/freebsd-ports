--- ./retroshare-gui/src/gui/common/GroupTreeWidget.cpp.orig	2013-02-28 16:46:27.000000000 +0100
+++ retroshare-gui/src/gui/common/GroupTreeWidget.cpp	2013-02-28 16:47:15.000000000 +0100
@@ -449,15 +449,15 @@
 
 	/* Find out which has given word in it */
 	QTreeWidgetItemIterator itemIterator(ui->treeWidget);
-	QTreeWidgetItem *item;
-	while ((item = *itemIterator) != NULL) {
+	QTreeWidgetItem *item2;
+	while ((item2 = *itemIterator) != NULL) {
 		itemIterator++;
 
-		if (item->data(COLUMN_DATA, ROLE_ID).toString().isEmpty()) {
+		if (item2->data(COLUMN_DATA, ROLE_ID).toString().isEmpty()) {
 			continue;
 		}
 
-		calculateScore(item, filterText);
+		calculateScore(item2, filterText);
 	}
 }
 
