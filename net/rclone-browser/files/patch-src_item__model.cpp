--- src/item_model.cpp.orig	2017-03-11 22:16:36.000000000 +0000
+++ src/item_model.cpp	2019-09-01 18:49:37.991420000 +0000
@@ -2,6 +2,8 @@
 #include "icon_cache.h"
 #include "utils.h"
 
+#include <algorithm>
+
 namespace
 {
     static void advanceSpinner(QString& text)
@@ -10,7 +12,7 @@
         QChar current = text[spinnerPos];
         static const QChar spinner[] = { '-', '\\', '|', '/' };
         size_t spinnerCount = sizeof(spinner) / sizeof(*spinner);
-        const QChar* found = qFind(spinner, spinner + spinnerCount, current);
+        const QChar* found = std::find(spinner, spinner + spinnerCount, current);
         size_t idx = found - spinner;
         size_t next = idx == spinnerCount - 1 ? 0 : idx + 1;
         text[spinnerPos] = spinner[next];
@@ -161,7 +163,7 @@
 {
     Item* item = get(index);
     item->name = name;
-    item->path = item->parent->path.filePath(item->name);
+    item->path.setPath(item->parent->path.filePath(item->name));
     emit dataChanged(index, index, QVector<int>{Qt::DisplayRole});
 }
 
@@ -182,7 +184,7 @@
     Item* item = new Item();
     item->isFolder = true;
     item->name = name;
-    item->path = path;
+    item->path.setPath(path);
     item->parent = mRoot;
     mRoot->childs.append(item);
 
@@ -500,7 +502,7 @@
             auto it = existing.find(item->name);
             if (it == existing.end())
             {
-                item->path = parent->path.filePath(item->name);
+                item->path.setPath(parent->path.filePath(item->name));
                 if (!item->isFolder && mFileIcons)
                 {
                     QString ext = QFileInfo(item->name).suffix();
@@ -561,8 +563,8 @@
         }
     };
 
-    QObject::connect(lsd, static_cast<void(QProcess::*)(int)>(&QProcess::finished), this, rcloneFinished);
-    QObject::connect(lsl, static_cast<void(QProcess::*)(int)>(&QProcess::finished), this, rcloneFinished);
+    QObject::connect(lsd, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, rcloneFinished);
+    QObject::connect(lsl, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, rcloneFinished);
 
     QObject::connect(lsd, &QProcess::readyRead, this, [=]()
     {
@@ -617,7 +619,7 @@
 
 void ItemModel::sortRecursive(Item* item, const ItemSorter& sorter)
 {
-    qSort(item->childs.begin(), item->childs.end(), sorter);
+    std::sort(item->childs.begin(), item->childs.end(), sorter);
 
     for (auto child : item->childs)
     {
