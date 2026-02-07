QAbstractItemModel API change.

--- src/stylemodel.cpp.orig	2018-11-26 11:58:44 UTC
+++ src/stylemodel.cpp
@@ -34,7 +34,8 @@ StyleModel::~StyleModel(){}
 
 void StyleModel::flush()
 {
-    reset();
+    beginResetModel();
+    endResetModel(); 
 }
 
 //////////////////////////////////////////////////////////////////////////////
