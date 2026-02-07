QAbstractItemModel API change

--- src/hopmodel.cpp.orig	2018-11-26 11:54:52 UTC
+++ src/hopmodel.cpp
@@ -34,7 +34,8 @@ HopModel::~HopModel() {}
 
 void HopModel::flush()
 {
-    reset();
+    beginResetModel();
+    endResetModel(); 
 }
 
 //////////////////////////////////////////////////////////////////////////////
