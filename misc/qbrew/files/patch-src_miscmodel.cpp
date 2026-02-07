QAbstractItemModel API change

--- src/miscmodel.cpp.orig	2018-11-26 11:55:17 UTC
+++ src/miscmodel.cpp
@@ -34,7 +34,8 @@ MiscModel::~MiscModel() {}
 
 void MiscModel::flush()
 {
-    reset();
+    beginResetModel();
+    endResetModel(); 
 }
 
 //////////////////////////////////////////////////////////////////////////////
